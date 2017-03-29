#include "../Solutions.hpp"
using namespace std;
/******* Counting Bits *************/
/*
 Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

 Example:
 For num = 5 you should return [0,1,1,2,1,2].
*/
vector<int> Solutions::countBits(int num) {
        vector<int> res;
        for (int i = 0; i <= num; i++) {
            int count = 0;

            for (int j=0; j<32; j++) {
                count += (i >> j) & 0x1;
            }
            res.push_back(count);
        }
    return res;
}
