#include <iostream>
#include <string>
#include <map>

using namespace std;

// Output the data stored in stateDataMap.
void print_map(map<string, string> stateDataMap) {
    for (map<string, string>::iterator it = stateDataMap.begin(); it != stateDataMap.end(); it++) {
        cout << "State: " << it->first << ", Capital: " << it->second << endl;
    }
}

// Output the capitalName using the stateName 
void print_capital(map<string, string> stateDataMap, string state) {
    map<string, string>::iterator it = stateDataMap.find(state);
    if (it == stateDataMap.end()) {
        cout << state << " is not found" << endl;
    } else {
        cout << "Capital of " << state << " is " << it->second << endl;
    }
}

int main() {
    // Declare map container stateDataMap 
    map<string, string> stateDataMap;

    // Add the following pairs to stateDataMap:
    // (Nebraska, Lincoln), (New York, Albany), (Ohio, Columbus), (California, Sacramento), (Massachusetts, Boston), and (Texas, Austin).
    stateDataMap["Nebraska"] = "Lincoln";
    stateDataMap["New York"] = "Albany";
    stateDataMap["Ohio"] = "Columbus";
    stateDataMap["California"] = "Sacramento";
    stateDataMap["Massachusetts"] = "Boston";
    stateDataMap["Texas"] = "Austin";

    // Output the data stored in stateDataMap
    print_map(stateDataMap);

    // Change the capital of California to Los Angeles
    stateDataMap["California"] = "Los Angeles";

    // Output the capitalName using the stateName
    string state;
    cout << "Enter state name: ";
    getline(cin, state);
    print_capital(stateDataMap, state);
    return 0;
}