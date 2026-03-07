#include<bits/stdc++.h>
using namespace std;

// function to check if string is palindrome using recursion
bool palindrome(int start_index , int end_index , string &s){

    // Base Case:
    // If start index crosses end index OR both become equal,
    // it means we checked all characters and the string is a palindrome
    if(start_index >= end_index) return true;

    // If characters at current positions are not equal
    // then the string cannot be a palindrome
    if(s[start_index] != s[end_index]) return false;

    // Recursive Step:
    // Move start forward and end backward
    // to compare the next pair of characters
    return palindrome(start_index + 1 , end_index - 1 , s);
}

int main(){

    string s = "abcdcba";

    // length of string
    int n = s.length();

    // checking palindrome from first to last character
    bool ans = palindrome(0 , n-1 , s);

    // prints 1 if true , 0 if false
    cout << ans << endl;

    return 0;
}