#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int left_idx = 0;
		int right_idx = height.size() - 1;
		int max_area = 0;

		while (left_idx < right_idx) {
			int current_area = min(height[left_idx], height[right_idx]) * (right_idx - left_idx);
			max_area = max(max_area, current_area);

			if (height[left_idx] < height[right_idx])
				left_idx++;
			else
				right_idx--;
		}

		return max_area;
    }
};