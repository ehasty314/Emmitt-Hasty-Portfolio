#include <iostream>
#include "/Users/ehast/Documents/GitHub/CS303/Assignment_3/palindrome.h"
using namespace std;
 
bool isPalindrome(string s, int i){
        
    if(i > s.size()/2){ //Base case
       return true ;
    }
    
    return s[i] == s[s.size()-i-1] && isPalindrome(s, i+1) ; // Recursive algorithm that compares i - 1 and i + 1
    
}