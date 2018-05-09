
/***************** Restore IP Addresses  *****************/
/*
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 
 For example:
 Given "25525511135",
 
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

#include "../Solutions.hpp"

void helper(string& candidate, int index, string s, vector<string>& res);

//ip part is 0~255, no leading 0s
vector<string> Solutions::restoreIpAddresses(string s) {
    vector<string> res;
    if (s.size()<4) return res;
    
    string candidate;
    helper(candidate, 0, s, res);
    return res;
}

void helper(string& candidate, int index, string s, vector<string>& res) {
    //already has three parts, this is the last one
    if (index==3) {
        if (s[0]=='0' && s.size()>1) return;
        //cout<<"candidate="+candidate<<",s="+s<<endl;
        if (s.size()<4 && stoi(s)<256) {
            res.push_back(candidate + "." + s);
        }
        return;
    }
    
    //no leading 0s, so only one 0
    if (s[0]=='0' && s.size()>1) {
        string tmp = candidate;
        if (!candidate.empty()) {
            candidate += ".0";
        } else {
            candidate += "0";
        }
        helper(candidate, index+1, s.substr(1), res);
        candidate = tmp;
        return;
    }
    
    //normal case
    for (int i=0;i<min((int)s.size()-1, 3);i++) {
        string cur = s.substr(0,i+1);
        if (stoi(cur)<256) {
            string tmp = candidate;
            if (!candidate.empty()) {
                candidate += "."+cur;
            } else {
                candidate += cur;
            }
            helper(candidate, index+1, s.substr(i+1), res);
            candidate = tmp;
        }
    }
}
