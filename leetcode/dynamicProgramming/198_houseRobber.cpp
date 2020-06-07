/*  You are a professional robber planning to rob houses along a street. 
 *  Each house has a certain amount of money stashed, the only constraint 
 *  stopping you from robbing each of them is that adjacent houses have 
 *  security system connected and it will automatically contact the police 
 *  if two adjacent houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money 
 * of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 *  
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 *              Total amount you can rob = 1 + 3 = 4.
 * Example 2:
 * 
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 *              Total amount you can rob = 2 + 9 + 1 = 12.
 *  
 * 
 * Constraints:
 * 
 * 0 <= nums.length <= 100
 * 0 <= nums[i] <= 400
*/
#include <iostream>
#include <vector>

using namespace std;

//answer from the others
//int rob(vector<int>& nums){
//    int n = nums.size();
//    int dp[n+1];
//    if(n == 0){
//        return 0;
//    }
//    dp[0] = 0;
//    if(n == 1){
//        return nums[0];
//    }
//    dp[1] = nums[0];
//    if(n >= 2){
//        dp[2] = max(nums[0], nums[1]);
//    }
//    for(int i = 3; i <= n; i++){
//        dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
//    }
//    return dp[n];
//}


int rob(vector<int>& nums){
	if(nums.size()==0) return 0;
	int currentMaxRob0 = nums[0];
	int currentMaxRob1= 0;
	int finalMaxRob = nums[0];
	for(int i = 1; i <nums.size(); i++){
		if(i % 2 == 1)
			currentMaxRob1 = max(currentMaxRob0, currentMaxRob1+nums[i]);
		else
			currentMaxRob0 = max(currentMaxRob1, currentMaxRob0+nums[i]);
		finalMaxRob = max(finalMaxRob, currentMaxRob0);
		finalMaxRob = max(finalMaxRob, currentMaxRob1);
	}

		return finalMaxRob;
}



int main(){
	vector<int> num;
	num.push_back(2);
	num.push_back(7);
	num.push_back(9);
	num.push_back(3);
	num.push_back(1);
	num.push_back(14);
	num.push_back(1);

	int result = rob(num);

	cout << result << endl;
	







	return 0;
}

