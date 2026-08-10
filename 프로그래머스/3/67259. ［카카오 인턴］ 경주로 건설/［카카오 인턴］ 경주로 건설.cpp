#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int INF = 987654321;
int HORIZONTAL = 0; 
int VERTICAL = 1;   

int dy[4] = { 0, 0, -1, 1 }; // 상, 하
int dx[4] = { -1, 1, 0, 0 }; // 좌, 우

int horizCost[25][25]; // 가로로 들어왔을 때의 최소 비용
int vertCost[25][25];  // 세로로 들어왔을 때의 최소 비용

int bfs(vector<vector<int>>& board) {
	int n = board.size();

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			horizCost[y][x] = INF;
			vertCost[y][x] = INF;
		}
	}

	queue<pair<int, int>> path;
	queue<int> axis;

	// 시작점
	horizCost[0][0] = 0;
	vertCost[0][0] = 0;
	path.push({ 0, 0 });	
	axis.push(-1);

	while (!path.empty()) {
		int y = path.front().first;
		int x = path.front().second;
		int nowAxis = axis.front();
		path.pop();	axis.pop();

		int nowCost;
		if (nowAxis == HORIZONTAL)
			nowCost = horizCost[y][x];
		else if (nowAxis == VERTICAL)
			nowCost = vertCost[y][x];
		else
			nowCost = 0; // 시작점

		// 좌 → 우 → 상 → 하
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (board[ny][nx] == 1) continue;

			int nextAxis;
			if (i < 2)	// 좌, 우
				nextAxis = HORIZONTAL;
			else		// 상, 하
				nextAxis = VERTICAL;

			int nextCost = nowCost + 100;
			if (nowAxis != -1 && nextAxis != nowAxis)
				nextCost += 500;

			// 다음 칸에 지금까지 기록된 비용
			int bestCost;
			if (nextAxis == HORIZONTAL)
				bestCost = horizCost[ny][nx];
			else
				bestCost = vertCost[ny][nx];

			// 더 싸질 때만 갱신하고 다시 탐색
			if (nextCost < bestCost) {
				if (nextAxis == HORIZONTAL)
					horizCost[ny][nx] = nextCost;
				else
					vertCost[ny][nx] = nextCost;

				path.push({ ny, nx });
				axis.push(nextAxis);
			}
		}
	}
	return min(horizCost[n - 1][n - 1], vertCost[n - 1][n - 1]);
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	answer = bfs(board);
	return answer;
}