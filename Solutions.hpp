
#ifndef Solutions_hpp
#define Solutions_hpp

#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solutions{
private:
    vector<string> generateParenthesisHelper(int left, int right);
public:
    vector<int> countBits(int num);
    int maxDepth(TreeNode* root);
    void moveZeroes(vector<int>& nums);
    void deleteNode(ListNode* node);
    vector<int> productExceptSelf(vector<int>& nums);
    vector<vector<int>> permute(vector<int>& nums);
    vector<string> generateParenthesis(int n);
    TreeNode* invertTree(TreeNode* root);
    vector<int> singleNumber(vector<int>& nums);
    bool isSameTree(TreeNode* p, TreeNode* q);
    vector<int> topKFrequent(vector<int>& nums, int k);
    int maxProfit(vector<int>& prices);
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    bool isAnagram(string s, string t);
    int getSum(int a, int b);
    bool exist(vector<vector<char>>& board, string word);
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
	int minSubArrayLen(int s, vector<int>& nums);
    int maxProduct(vector<int>& nums);
	int ladderLength(string beginWord, string endWord, vector<string>& wordList);
	void reverseWords(string &s);
	int numDecodings(string s);
    int threeSumClosest(vector<int>& nums, int target);
};


#endif /* Solutions_hpp */
