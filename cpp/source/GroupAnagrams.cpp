#include "../Solutions.hpp"

using namespace std;

/***************** Group Anagrams *****************/
/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note: All inputs will be in lower-case.

*/

vector<vector<string>> Solutions::groupAnagrams(vector<string>& strs) {
	unordered_map<string,vector<string>> mp;
	vector<vector<string>> res;

	for (int i=0;i<strs.size();i++) {
		string key = strs[i];
		sort(key.begin(),key.end());
		auto iter = mp.find(key);
		if (iter != mp.end()) {
			iter->second.push_back(strs[i]);
		} else {
			vector<string> tmp(1,strs[i]);
			mp[key] = tmp;
		}
	}

	for (auto iter=mp.begin();iter!=mp.end();iter++) {
		res.push_back(iter->second);
	}

	return res;
}