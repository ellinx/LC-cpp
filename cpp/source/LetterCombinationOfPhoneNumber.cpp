#include "../Solutions.hpp"

using namespace std;

/***************** Letter Combination of Phone Number *****************/
/*
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 [   1      2      3    ]
          (abc)  (def)
 [   4      5      6    ]
   (ghi)  (jkl)  (mno)
 [   7      8      9    ]
   (pqrs) (tuv)  (wxyz)
 [   *      0      #    ]
 
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

void helper(int cur, string& buildBlk, string& digits, vector<string>& res);
string getStr(char a);

//iterative
vector<string> Solutions::letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    
    
    string tmp = getStr(digits[0]);
    for (int j=0;j<tmp.size();j++) {
        res.push_back(string(1,tmp[j]));
    }
    int index=1;
    while (index < digits.size()) {
        vector<string> newRes;
        for (int i=0;i<res.size();i++) {
            tmp = getStr(digits[index]);
            for (int j=0;j<tmp.size();j++) {
                newRes.push_back(res[i]+tmp[j]);
            }
        }
        res = newRes;
        index++;
    }
    return res;
}

#if 0  //recursive
vector<string> Solutions::letterCombinations(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    string buildBlk;
    helper(0,buildBlk,digits,res);
    return res;
}
#endif

void helper(int cur, string& buildBlk, string& digits, vector<string>& res) {
    if (cur==digits.size()) {
        res.push_back(buildBlk);
        return;
    }
    string tmp = getStr(digits[cur]);
    for (int i=0;i<tmp.size();i++) {
        buildBlk.push_back(tmp[i]);
        helper(cur+1,buildBlk,digits,res);
        buildBlk.pop_back();
    }
}

string getStr(char a) {
    switch (a) {
        case '2':
            return "abc";
            break;
        case '3':
            return "def";
            break;
        case '4':
            return "ghi";
            break;
        case '5':
            return "jkl";
            break;
        case '6':
            return "mno";
            break;
        case '7':
            return "pqrs";
            break;
        case '8':
            return "tuv";
            break;
        case '9':
            return "wxyz";
            break;
        default:
            break;
    }
    return "";
}
