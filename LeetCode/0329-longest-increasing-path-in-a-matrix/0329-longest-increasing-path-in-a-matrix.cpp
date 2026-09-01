#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dp[201][201] = { 0 }; 
	int dy[4] = {0, 0, -1, 1};  // 상하
	int dx[4] = {-1, 1, 0, 0};  // 좌우

	int dfs(int y, int x, vector<vector<int>>& matrix) {
		// 이미 들렀으면
		if (dp[y][x] != 0) return dp[y][x];

		dp[y][x] = 1;

		// 상하좌우 탐색
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0) continue;
			if (nx >= matrix[0].size() || ny >= matrix.size()) continue;

			if (matrix[ny][nx] > matrix[y][x]) {
				dp[y][x] = max(dp[y][x], dfs(ny, nx, matrix) + 1);
			}
		}
		return dp[y][x];
	}

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int maxPath = 0;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				maxPath = max(maxPath, dfs(i, j, matrix));
			}
		}
		return maxPath;
	}
};