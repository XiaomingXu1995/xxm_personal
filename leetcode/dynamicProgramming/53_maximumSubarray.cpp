/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 *Example:
 *
 *Input: [-2,1,-3,4,-1,2,1,-5,4],
 *Output: 6
 *Explanation: [4,-1,2,1] has the largest sum = 6.
 *Follow up:
 *
 *If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 */

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int> & nums){
	int currentMax = nums[0];
	int finalMax = nums[0];
	for(int i = 1; i < nums.size(); i++){
		currentMax = max(currentMax+nums[i], nums[i]);
		finalMax = max(currentMax, finalMax);
	}

	return finalMax;
}

int main(){

	int n;
	vector<int> num;
	num.push_back(-2);
	num.push_back(1);
	num.push_back(-3);
	num.push_back(4);
	num.push_back(-1);
	num.push_back(2);
	num.push_back(1);
	num.push_back(-5);
	num.push_back(4);

	int result = maxSubArray(num);
	cout << result << endl;

	return 0;
}
	
