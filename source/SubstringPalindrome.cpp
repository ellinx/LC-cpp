#include "../Solutions.hpp"

using namespace std;

/***************** Number of Palindromic Substring *****************/
/*
 Given a string, calculate the number of substring which is palindrome.
*/

int PalindromeSubstring(string s) {
    int res = 0;
    //odd length substring
    for (int i=0;i<s.size();i++) {
        int k=0;
        while ( k<=i && k<s.size()-i) {
            if (s[i-k]==s[i+k]) res++;
        }
    }
    
    //even length substring
    for (int i=1;i<s.size();i++) {
        int k=0;
        while (k<=i-1 && k<s.size()-i) {
            if (s[i-1-k]==s[i+k]) res++;
        }
    }
    
    return res;
}
