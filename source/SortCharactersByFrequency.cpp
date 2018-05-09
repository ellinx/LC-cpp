#include "../Solutions.hpp"

/*************** Sort Characters By Frequency **************/
/*
 Given a string, sort it in decreasing order based on the frequency of characters.
 
 Example 1:
 
 Input:
 "tree"
 
 Output:
 "eert"
 
 Explanation:
 'e' appears twice while 'r' and 't' both appear once.
 So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
 Example 2:
 
 Input:
 "cccaaa"
 
 Output:
 "cccaaa"
 
 Explanation:
 Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 Note that "cacaca" is incorrect, as the same characters must be together.
 Example 3:
 
 Input:
 "Aabb"
 
 Output:
 "bbAa"
 
 Explanation:
 "bbaA" is also a valid answer, but "Aabb" is incorrect.
 Note that 'A' and 'a' are treated as two different characters.
 */

string Solutions::frequencySort(string s) {
    string res;
    
    auto cmp = [](pair<char,int> a, pair<char, int> b){
        return a.second<b.second;
    };
    
    priority_queue<pair<char,int>, vector<pair<char,int>>, decltype(cmp)> maxHeap(cmp);
    unordered_map<char, int> mp;
    for (char a : s) {
        if (mp.find(a)==mp.end()) {
            mp[a] = 1;
        } else {
            mp[a]++;
        }
    }
    
    for (auto iter=mp.begin();iter!=mp.end();iter++) {
        maxHeap.push(*iter);
    }
    
    while (!maxHeap.empty()) {
        auto tmp = maxHeap.top();
        maxHeap.pop();
        for (int i=0;i<tmp.second;i++)
            res += tmp.first;
    }
    
    return res;
}
