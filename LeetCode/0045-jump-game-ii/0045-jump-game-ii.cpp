#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
		int cnt = 0; 
		int idx = 0;
		int max_idx = 0;
		for (int i = 0; i < nums.size() - 1; i++) {
			max_idx = max(max_idx, i + nums[i]);
			if (i == idx) {
				cnt++;
				idx = max_idx;
			}
		}
		return cnt;
    }
};
