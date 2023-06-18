% Load face dataset
imds = imageDatastore('archive', 'IncludeSubfolders',true,'LabelSource','foldernames');
[imdsTrain,imdsValidation] = splitEachLabel(imds,0.7,'randomized');
numClasses = numel(categories(imdsTrain.Labels))

% Import AlexNet and find its input size
net = alexnet;
inputSize = net.Layers(1).InputSize;

% Take off the old classification head and put a new one on
layersTransfer = net.Layers(1:end-3);
layers = [ layersTransfer;            fullyConnectedLayer(numClasses, 'WeightLearnRateFactor',20,'BiasLearnRateFactor',20);            softmaxLayer;            classificationLayer];

% Set parameters for data augmentation and resizing       
pixelRange = [-30 30];
imageAugmenter = imageDataAugmenter(...
                   'RandXReflection', true,...
                   'RandXTranslation', pixelRange,...
                   'RandYTranslation', pixelRange);
augimdsTrain = augmentedImageDatastore(inputSize, imdsTrain, ...
                                       'ColorPreprocessing','gray2rgb',...
                                       'DataAugmentation', imageAugmenter);

augimdsValidation = augmentedImageDatastore(inputSize,imdsValidation,...
                                            'ColorPreprocessing','gray2rgb');

% Set training options
options = trainingOptions('sgdm', ...
    'MiniBatchSize',10, ...
    'MaxEpochs',6, ...
    'InitialLearnRate',1e-4, ...
    'Shuffle','every-epoch', ...
    'ValidationData',augimdsValidation, ...
    'ValidationFrequency',5, ...
    'ValidationPatience',5, ...
    'Verbose',false, ...
    'Plots','training-progress');

% Train net
netTransfer = trainNetwork(augimdsTrain,layers,options);

% Test net
[YPred,scores] = classify(netTransfer,augimdsValidation);

YValidation = imdsValidation.Labels;
accuracy = mean(YPred == YValidation)

% Visualize some prediction results
idx = randperm(numel(imdsValidation.Files),16);
figure
for i = 1:16
    subplot(4,4,i)
    I = readimage(imdsValidation,idx(i));
    imshow(I)
    label = strcat('Pred: ',cellstr(YPred(idx(i))),' Actual: ',cellstr(YValidation(idx(i))));
    title(string(label));
end

% Form Dataset
imds = imageDatastore('archive', 'IncludeSubfolders', true, 'LabelSource', 'foldernames');
[imdsTrain, imdsValidation] = splitEachLabel(imds, 0.6, 'randomized');
numClasses = numel(categories(imdsTrain.Labels));

% Import net and find its input size
net = vgg19;
inputSize = net.Layers(1).InputSize;

% Take off the old classification head and put a new one on
layersTransfer = net.Layers(1:end-3);
layers = [    layersTransfer;    fullyConnectedLayer(numClasses, 'WeightLearnRateFactor', 20, 'BiasLearnRateFactor', 20);    softmaxLayer;    classificationLayer];

% Set parameters for data augmentation and resizing
pixelRange = [-30 30];
imageAugmenter = imageDataAugmenter(...
    'RandXReflection', true, ...
    'RandXTranslation', pixelRange, ...
    'RandYTranslation', pixelRange);
augimdsTrain = augmentedImageDatastore(inputSize, imdsTrain, ...
    'ColorPreprocessing', 'gray2rgb', ...
    'DataAugmentation', imageAugmenter);

augimdsValidation = augmentedImageDatastore(inputSize, imdsValidation, ...
    'ColorPreprocessing', 'gray2rgb');

% Set training options
options = trainingOptions('sgdm', ...
    'MiniBatchSize', 10, ...
    'MaxEpochs', 6, ...
    'InitialLearnRate', 1e-4, ...
    'Shuffle', 'every-epoch', ...
    'ValidationData', augimdsValidation, ...
    'ValidationFrequency', 5, ...
    'ValidationPatience', 5, ...
    'Verbose', false, ...
    'Plots', 'training-progress');

% Train net
netTransfer = trainNetwork(augimdsTrain, layers, options);

% Test net
[YPred, scores] = classify(netTransfer, augimdsValidation);

YValidation = imdsValidation.Labels;
accuracy = mean(YPred == YValidation)

idx = randperm(numel(imdsValidation.Files), 16);
figure
for i = 1:16
    subplot(4, 4, i)
    I = readimage(imdsValidation, idx(i));
    imshow(I)
    label = strcat('Pred: ', cellstr(YPred(idx(i))), ' Actual: ', cellstr(YValidation(idx(i))));
    title(string(label));
end

%%% Part 2-use these features with cosine similarity
layer = 'fc7';
featuresTrain = activations(netTransfer, augimdsTrain, layer, 'OutputAs', 'rows');
featuresValidation = activations(netTransfer, augimdsValidation, layer, 'OutputAs', 'rows');

% Get predicted scores for validation data from AlexNet and VGG 19
[~, alexnetScores] = classify(netTransfer, augimdsValidation);
[~, vgg19Scores] = classify(vgg19Transfer, augimdsValidation);

% Convert labels to binary vectors for ROC curve analysis
alexnetLabels = imdsValidation.Labels;
vgg19Labels = imdsValidation.Labels;
alexnetBinaryLabels = double(alexnetLabels == categorical('face'))';
vgg19BinaryLabels = double(vgg19Labels == categorical('face'))';

% Calculate ROC curves and AUC values for AlexNet and VGG 19
[alexnetX, alexnetY, alexnetT, alexnetAUC] = perfcurve(alexnetBinaryLabels, alexnetScores(:, 2), 1);
[vgg19X, vgg19Y, vgg19T, vgg19AUC] = perfcurve(vgg19BinaryLabels, vgg19Scores(:, 2), 1);

% Plot ROC curves for both models
figure;
plot(alexnetX, alexnetY)
hold on
plot(vgg19X, vgg19Y)
hold off
xlabel('False positive rate')
ylabel('True positive rate')
title('ROC curves for AlexNet and VGG 19')
legend(['AlexNet (AUC = ' num2str(alexnetAUC) ')'], ['VGG 19 (AUC = ' num2str(vgg19AUC) ')'])

