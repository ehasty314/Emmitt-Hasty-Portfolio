#include <iostream>
#include <queue>
#include "/Users/ehast/Documents/GitHub/CS303/Assignment_3/move_header.h"
using namespace std;


int main ()
{
    std::queue <int> myQueue;//declaring Queue and initializing
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);

    std::cout<<"Before removing front"<<std::endl;
    std::cout<<myQueue.front()<<std::endl;
    std::cout<<"After removing front and adding it to rear"<<std::endl;
    move_to_rear(myQueue);

return 0;
}