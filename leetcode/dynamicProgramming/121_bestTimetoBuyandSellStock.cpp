/*Say you have an array for which the ith element is the price of a given stock on day i.
 *
 *If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 *Note that you cannot sell a stock before you buy one.
 *
 *Example 1:
 *
 *Input: [7,1,5,3,6,4]
 *Output: 5
 *Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
 *             Not 7-1 = 6, as selling price needs to be larger than buying price.
 *Example 2:
 *
 *Input: [7,6,4,3,1]
 *Output: 0
 *Explanation: In this case, no transaction is done, i.e. max profit = 0.

 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> & prices){
	if(prices.size() == 0) return 0;
	int finalProfit = 0;
	int currentMinPrice = prices[0];
	int currentMaxProfit = 0;

	for(int i = 1; i < prices.size(); i++){
		currentMinPrice = min(currentMinPrice, prices[i]);
		currentMaxProfit = max(currentMaxProfit, prices[i]-currentMinPrice);
		finalProfit = max(finalProfit, currentMaxProfit);
		}

	return finalProfit;
	}



int main(){
	vector<int> num;
	num.push_back(7);
	num.push_back(1);
	num.push_back(5);
	num.push_back(3);
	num.push_back(6);
	num.push_back(4);

	int result = maxProfit(num);

	cout << result << endl;

	return 0;
}
