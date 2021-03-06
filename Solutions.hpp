
#ifndef Solutions_hpp
#define Solutions_hpp

#include <iostream>
#include <utility> //std::pair, std::make_pair
#include <locale>
#include <algorithm>
#include <numeric> //iota
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
#include <functional>   // std::function, std::negate std::greater

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

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solutions{
public:
    vector<int> countBits(int num);
    int maxDepth(TreeNode* root);
    void moveZeroes(vector<int>& nums);
    void deleteNode(ListNode* node);
    vector<int> productExceptSelf(vector<int>& nums);
    vector<vector<int>> permute(vector<int>& nums);
    vector<string> generateParenthesis(int n);
    TreeNode* invertTree(TreeNode* root);
    vector<int> singleNumberIII(vector<int>& nums);
    bool isSameTree(TreeNode* p, TreeNode* q);
    vector<int> topKFrequent(vector<int>& nums, int k);
    int maxProfit(vector<int>& prices);
    int maxProfitII(vector<int>& prices);
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
	vector<vector<int>> threeSum(vector<int>& nums);
	string multiply(string num1, string num2);
	bool isValidBST(TreeNode* root);
    int totalHammingDistance(vector<int>& nums);
	vector<int> maxSlidingWindow(vector<int>& nums, int k);
	int divide(int dividend, int divisor);
	int longestConsecutive(vector<int>& nums);
    vector<string> removeInvalidParentheses(string s);
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval);
    ListNode* reverseList(ListNode* head);
    string countAndSay(int n);
    vector<string> letterCombinations(string digits);
    string minWindow(string s, string t);
    bool wordBreak(string s, vector<string>& wordDict);
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);
    string numberToWords(int num);
    string addBinary(string a, string b) ;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
    void nextPermutation(vector<int>& nums);
    string decodeString(string s);
    vector<string> binaryTreePaths(TreeNode* root);
    ListNode* mergeKLists(vector<ListNode*>& lists);
    bool isOneEditDistance(string s, string t);
    string longestPalindrome(string s);
    bool canAttendMeetings(vector<Interval>& intervals);
    int minMeetingRooms(vector<Interval>& intervals);
    void sortColors(vector<int>& nums);
    bool isValid(string s);
    vector<vector<int>> subsets(vector<int>& nums);
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
    int findKthLargest(vector<int>& nums, int k);
    TreeNode* ConstructFromInorder(vector<int>& inorder);
    int maxSubArrayLen(vector<int>& nums, int k);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
    bool isMatchWildcard(string s, string p);
	vector<int> twoSum(vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(string s);
	int trap(vector<int>& height);
	void rotate(vector<vector<int>>& matrix);
	vector<vector<string>> groupAnagrams(vector<string>& strs);
	vector<int> grayCode(int n);
    bool canFindZero(vector<int>& nums, int index);
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
    int findCircleNum(vector<vector<int>>& M);
    int singleNumberII(vector<int>& nums);
    int coinChange(vector<int>& coins, int amount);
    int minDistance(string word1, string word2);
    vector<string> findItinerary(vector<pair<string, string>> tickets);
    bool isValidSerialization(string preorder);
    int longestIncreasingPath(vector<vector<int>>& matrix);
    bool isPowerOfThree(int n);
    void wiggleSortII(vector<int>& nums);
    int countComponents(int n, vector<pair<int,int>>& edges);
    int maxProductWordLength(vector<string>& words);
    vector<vector<int>> verticalOrder(TreeNode* root);
    vector<string> generateAbbreviations(string word);
    bool isUgly(int num);
    int nthUglyNumber(int n);
    int nthSuperUglyNumber(int n, vector<int>& primes);
    TreeNode* deleteNode(TreeNode* root, int key);
    void gameOfLife(vector<vector<int>>& board);
    int maxProfitWithCD(vector<int>& prices);
    vector<int> LCS(vector<int> a, vector<int> b);
    int longestPalindromeSubseq(string s);
    int findLUSlength(string a, string b);
    int findLHS(vector<int>& nums);
    bool isSubsequence(string s, string t);
    bool find132pattern(vector<int>& nums);
    int calculate(string s);
    bool isMatchRegE(string s, string p);
    vector<string> findMissingRanges(vector<int> nums, int lower, int upper);
    int trapRainWaterII(vector<vector<int>>& heightMap);
    int findPeakElement(vector<int>& nums);
    int kthSmallest(TreeNode* root, int k);
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges);
    ListNode* rotateRight(ListNode* head, int k);
    string getPermutation(int n, int k);
    vector<string> restoreIpAddresses(string s);
    void solve(vector<vector<char>>& board);
    vector<vector<string>> partition(string s);
    ListNode* reverseBetween(ListNode* head, int m, int n);
    void reorderList(ListNode* head);
    ListNode* sortList(ListNode* head);
    string largestNumber(vector<int>& nums);
    int rangeBitwiseAnd(int m, int n);
    bool containsDuplicate(vector<int>& nums);
    bool containsNearbyDuplicate(vector<int>& nums, int k);
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t);
    int countNodes(TreeNode* root);
    int majorityElementI(vector<int>& nums);
    vector<int> majorityElementII(vector<int>& nums);
    int findDuplicate(vector<int>& nums);
    string getHint(string secret, string guess);
    bool isAdditiveNumber(string num);
    bool canMeasureWater(int x, int y, int z);
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);
    vector<int> largestDivisibleSubset(vector<int>& nums);
    int superPow(int a, vector<int>& b);
    int lengthLongestPath(string input);
    int lastRemaining(int n);
    bool validUtf8(vector<int>& data);
    int longestSubstring(string s, int k);
    int integerReplacement(int n);
    string removeKdigits(string num, int k);
    int findPoisonedDuration(vector<int>& timeSeries, int duration);
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people);
    int numberOfArithmeticSlices(vector<int>& A);
    bool canPartition(vector<int>& nums);
    int findMaximumXOR(vector<int>& nums);
    string originalDigits(string s);
    int characterReplacement(string s, int k);
    int eraseOverlapIntervals(vector<Interval>& intervals);
    vector<int> findRightInterval(vector<Interval>& intervals);
    vector<int> findDuplicates(vector<int>& nums);
    string frequencySort(string s);
    int findMinArrowShots(vector<pair<int, int>>& points);
    vector<vector<int>> fourSum(vector<int>& nums, int target);
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);
    int minMoves(vector<int>& nums);
    int minMoves2(vector<int>& nums);
    vector<int> findAnagrams(string s, string p);
    ListNode* removeElements(ListNode* head, int val);
    bool isHappy(int n);
    int evalRPN(vector<string>& tokens);
};


#endif /* Solutions_hpp */
