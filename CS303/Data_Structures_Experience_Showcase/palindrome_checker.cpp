#include <iostream>
#include "/Users/ehast/Documents/GitHub/CS303/Assignment_3/palindrome.h"
using namespace std;
 
     
     
int main()
{
    string str1 = "palindrome" ; //Case: Not a palindrome
    if (isPalindrome(str1, 0))
    cout << "The word " << str1 << " is a palindrome" << endl;
    else
    cout << "The word " << str1 << " is not a palindrome" << endl;

    string str2 = "racecar" ; //Case: Is a palindrome
    if (isPalindrome(str2, 0))
    cout << "The word " << str2 << " is a palindrome" << endl;
    else
    cout << "The word " << str2 << " is not a palindrome" << endl;
 
    return 0;
 
}