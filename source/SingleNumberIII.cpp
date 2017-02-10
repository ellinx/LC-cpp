#include "../Solutions.hpp"
using namespace std;

/*************** Single Number III **************/
/*
 Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

 For example:

 Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
*/

vector<int> Solutions::singleNumber(vector<int>& nums) {
    int allXOR = 0;
    for (int num : nums) {
        allXOR ^= num;
    }

    int set_position = 0;
    while ((allXOR & 1) != 1) {
        set_position++;
        allXOR = allXOR >> 1;
    }

    int dif = 1 << set_position;
    vector<int> res{0,0};
    for (int num : nums) {
        if ((num & dif) == 0) {
            res[0] ^= num;
        } else {
            res[1] ^= num;
        }
    }
    return res;
}
