#include "../Solutions.hpp"

using namespace std;

/***************** Best Time to Buy and Sell Stock with Cooldown *****************/
/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
 
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 Example:
 
 prices = [1, 2, 3, 0, 2]
 maxProfit = 3
 transactions = [buy, sell, cooldown, buy, sell]
 */

int Solutions::maxProfitWithCD(vector<int>& prices) {
    if (prices.empty()) return 0;
    
    int has0_rest = 0;
    int has1_rest = -prices[0];
    int buy = -prices[0];
    int sell = 0;
    
    for (int i=1;i<prices.size();i++) {
        int prev_buy = buy;
        int prev_sell = sell;
        buy = has0_rest-prices[i];
        sell = max(has1_rest, prev_buy) + prices[i];
        has0_rest = max(has0_rest, prev_sell);
        has1_rest = max(has1_rest, prev_buy);
    }
    
    return max(sell, has0_rest);
}
