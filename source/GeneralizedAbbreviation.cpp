#include "../Solutions.hpp"

using namespace std;

/***************** Generalized Abbreviation *****************/
/*
 Write a function to generate the generalized abbreviations of a word.
 
 Example:
 Given word = "word", return the following list (order does not matter):
 
 ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */

void DFS(string& candicate, string s, vector<string>& res);

vector<string> Solutions::generateAbbreviations(string word) {
    vector<string> res;
    string candidate;
    
    res.push_back(word);
    for (int i=1;i<word.size();i++) {
        candidate = to_string(i) + word.substr(i,1);
        DFS(candidate, word.substr(i+1,-1), res);
    }
    res.push_back(to_string(word.size()));
    return res;
}

void DFS(string& candicate, string s, vector<string>& res) {
    if (s.empty()) {
        res.push_back(candicate);
        return;
    }
    
    res.push_back(candicate+s);
    for (int i=1;i<s.size();i++) {
        string tmp = candicate;
        candicate += to_string(i) + s.substr(i,1);
        DFS(candicate, s.substr(i+1,-1), res);
        candicate = tmp;
    }
    res.push_back(candicate+to_string(s.size()));
}
