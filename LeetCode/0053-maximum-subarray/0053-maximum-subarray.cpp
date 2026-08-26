#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
	int maxSubArray(vector<int>& nums) {
		int maxCurr, maxSum;
		maxCurr = nums[0];
		maxSum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			maxCurr = max(nums[i], maxCurr + nums[i]);
			maxSum = max(maxSum, maxCurr);
		}
		return maxSum;
	}
};