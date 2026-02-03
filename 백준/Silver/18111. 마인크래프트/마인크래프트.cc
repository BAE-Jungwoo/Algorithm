#include <iostream>
#include <climits>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, block; // 세로, 가로, 보유한 블록
	cin >> n >> m >> block;

	int arr[501][501];
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int minTime = INT_MAX;
	int maxHeight = 0;
	for (int h = 0; h <= 256; h++) {
		int time = 0;
		int inventory = block;
		bool max = true;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > h) {			// 블록 제거
					int remove = arr[i][j] - h;
					time += remove * 2;
					inventory += remove;
				}
				else if (arr[i][j] < h) {		// 블록 쌓기
					int add = h - arr[i][j];
					time += add;
					inventory -= add;
				}
			}
		}
		if (inventory < 0)						// 블록이 부족한 경우
			max = false;

		if (max) {
			if (minTime > time) {				// 시간이 같으면 더 높은 높이 선택
				minTime = time;
				maxHeight = h;
			}
			else if(minTime == time && maxHeight < h) {
				maxHeight = h;
			}
		}
	}

	cout << minTime << " " << maxHeight;
	return 0;
}