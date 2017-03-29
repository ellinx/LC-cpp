#include "../Solutions.hpp"

using namespace std;

/***************** Minimum Window Substring *****************/
/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 
 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".
 
 If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/

string Solutions::minWindow(string s, string t) {
	vector<int> chars(128,0);
	for (int i=0;i<t.size();i++) {
		chars[t[i]]++;
	}

	int start = 0;
	int end = 0;
	int head = 0;
	int length = -1;
	int count = t.size();
	chars[s[0]]--;
	if (chars[s[0]]>=0) count--;
	while (end < s.size()) {
		if (count==0) {
			if (length<0 || length>end-start+1) {
				head = start;
				length = end-start+1;
			}
			chars[s[start]]++;
			if (chars[s[start]]>0) count++;
			start++;
		} else {
			end++;
			chars[s[end]]--;
			if (chars[s[end]]>=0) count--;
		}
	}
	cout<<"length="<<length<<endl;
	return (length>0)?s.substr(head,length):"";
}

#if 0
string Solutions::minWindow(string s, string t) {
    unordered_map<char,int> tSet;
    unordered_map<char,int> unused;
    unordered_map<char,int> used;
    string res;
    int start=0;
    int end=0;
    
    for (int i=0;i<t.size();i++) {
        if (unused.find(t[i])==unused.end()) {
            unused.emplace(t[i],1);
            tSet.emplace(t[i],1);
        } else {
            unused[t[i]]++;
            tSet[t[i]]++;
        }
    }
    
    if (unused.find(s[0])!=unused.end()) {
        if (unused[s[0]]==1) {
            unused.erase(s[0]);
        } else {
            unused[s[0]]--;
        }
        used.emplace(s[0],1);
    }
    
    while (start<s.size()) {
        if (!unused.empty()) {
            if (end>=s.size()-1) return res;
            end++;
            if (unused.find(s[end])==unused.end()) {
                if (used.find(s[end])!=used.end()) used[s[end]]++;
            } else {
                if (unused[s[end]]==1) {
                    unused.erase(s[end]);
                } else {
                    unused[s[end]]--;
                }
                if (used.find(s[end])==used.end()) {
                    used.emplace(s[end],1);
                } else {
                    used[s[end]]++;
                }
            }
        } else {
            if (res.empty() || res.size()>end-start+1) {
                res = s.substr(start,end-start+1);
            }
            if (used.find(s[start])!=used.end()) {
                if (used[s[start]]>tSet[s[start]]) {
                    used[s[start]]--;
                } else if (used[s[start]]==tSet[s[start]]) {
                    if (used[s[start]]==1) {
                        used.erase(s[start]);
                    } else {
                        used[s[start]]--;
                    }
                    unused.emplace(s[start],1);
                } else {
                    if (used[s[start]]==1) {
                        used.erase(s[start]);
                    } else {
                        used[s[start]]--;
                    }
                    unused[s[start]]++;
                }
            }
            start++;
        }
    }
    return res;
}
#endif
