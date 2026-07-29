#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
		int cnt = 0; 
		int endIdx = 0; // 현재 점프로 갈 수 있는 범위의 끝 인덱스
		int maxIdx = 0; // 지금까지 확인한 위치들 중 도달 가능한 최대 인덱스

		for (int i = 0; i < nums.size() - 1; i++) {
			maxIdx = max(maxIdx, i + nums[i]);
			if (i == endIdx) {
				cnt++;
				endIdx = maxIdx;
			}
			if (endIdx >= nums.size() - 1) break;
		}
		return cnt;
    }
};