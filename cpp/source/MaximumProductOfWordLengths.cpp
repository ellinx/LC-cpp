#include "../Solutions.hpp"

using namespace std;

/***************** Maximum Product of Word Lengths *****************/

/*
 Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
 
 Example 1:
 Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 Return 16
 The two words can be "abcw", "xtfn".
 
 Example 2:
 Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 Return 4
 The two words can be "ab", "cd".
 
 Example 3:
 Given ["a", "aa", "aaa", "aaaa"]
 Return 0
 No such pair of words.
 */

int Solutions::maxProductWordLength(vector<string>& words) {
    int n = words.size();
    if (n<2) return 0;
    int maxPro = 0;
    vector<int> letters(n,0);
    
    for (int i=0;i<n;i++) {
        for (char a : words[i]) {
            letters[i] |= 1<<(a-'a');
        }
    }
    
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if ((letters[i] & letters[j]) == 0) {
                int newPro = words[i].size()*words[j].size();
                maxPro = max(maxPro, newPro);
            }
        }
    }
    return maxPro;
}
