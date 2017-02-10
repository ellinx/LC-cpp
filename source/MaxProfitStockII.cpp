#include "../Solutions.hpp"
using namespace std;

/*************** Best Time to Buy and Sell Stock II ****************/
/*
 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int Solutions::maxProfit(vector<int>& prices) {
    if (prices.size() <= 1 ) {
        return 0;
    }
    int in_price=0;
    bool already_in = false;
    int profit = 0;
    for (int i=1;i<prices.size();i++) {
        if (prices[i] > prices[i-1]) {
            if (!already_in) {
                in_price = prices[i-1];
                already_in = true;
            }
            if (i == prices.size()-1){
                profit += prices[i] - in_price;
            }
        } else if (prices[i] < prices[i-1]) {
            if (already_in) {
                profit += prices[i-1] - in_price;
                already_in = false;
            }
        } else {
            if (already_in && (i==prices.size()-1)) {
                profit += prices[i] - in_price;
            }
        }
    }
    return profit;
}
