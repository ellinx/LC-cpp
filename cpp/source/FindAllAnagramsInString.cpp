
#include "../Solutions.hpp"
#include "../Tester.hpp"

/***************** Find All Anagrams In A String *****************/
/*
 Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
 
 Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
 
 The order of output does not matter.
 
 Example 1:
 
 Input:
 s: "cbaebabacd" p: "abc"
 
 Output:
 [0, 6]
 
 Explanation:
 The substring with start index = 0 is "cba", which is an anagram of "abc".
 The substring with start index = 6 is "bac", which is an anagram of "abc".
 Example 2:
 
 Input:
 s: "abab" p: "ab"
 
 Output:
 [0, 1, 2]
 
 Explanation:
 The substring with start index = 0 is "ab", which is an anagram of "ab".
 The substring with start index = 1 is "ba", which is an anagram of "ab".
 The substring with start index = 2 is "ab", which is an anagram of "ab".
 */


vector<int> Solutions::findAnagrams(string s, string p) {
    vector<int> res;
    if (s.size()<p.size()) return res;
    
    int start = 0;
    int end = 0;
    int count = 0;
    vector<int> letters(26,0);
    for (char a : p) {
        if (letters[a-'a']==0) {
            count++;
        }
        letters[a-'a']++;
    }
    

    while (end<p.size()) {
        letters[s[end]-'a']--;
        if (letters[s[end]-'a']==0){
            count--;
        }
        end++;
    }
    end--;
    while (end<s.size()) {
//        cout<<"start="<<start<<",end="<<end<<" ";
//        Tester::print(letters);
        if (count==0) {
            res.push_back(start);
        }
        
        if (letters[s[start]-'a']==0) {
            count++;
        }
        letters[s[start]-'a']++;
        start++;
        end++;
        letters[s[end]-'a']--;
        if (letters[s[end]-'a']==0){
            count--;
        }
    }
    return res;
}
