#include <iostream>
#include <queue>
#include "/Users/ehast/Documents/GitHub/CS303/Assignment_3/move_header.h"
using namespace std;

void move_to_rear(std::queue<int> myQ){

    int num=myQ.front(); //Read the first element of the queue into num

    myQ.pop(); //Remove the first element of the queue

    myQ.push(num); //Add num to the end of the queue

    cout << myQ.front() << endl;
}