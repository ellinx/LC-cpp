#include "../Solutions.hpp"

using namespace std;

/***************** Best Time to Buy and Sell Stock II *****************/
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int Solutions::maxProfitII(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int res = 0;
    int buyPrice = prices[0];
    bool toBuy=true;
    for (int i=1;i<prices.size();i++) {
        if (toBuy) {
            if (prices[i-1]<prices[i]) {
                buyPrice = prices[i-1];
                toBuy = false;
            }
        } else {
            if (prices[i-1]>prices[i]) {
                res += prices[i-1]-buyPrice;
                toBuy = true;
            }
        }
    }
    if (!toBuy && prices.back()>buyPrice) res += prices.back()-buyPrice;
    return res;
}
