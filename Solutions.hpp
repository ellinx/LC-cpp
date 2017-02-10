
#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <stack>

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

class Solution{
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
};


#endif /* Solution_hpp */
