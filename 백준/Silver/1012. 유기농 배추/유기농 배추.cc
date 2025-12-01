#include <iostream>
#include <cstring>
using namespace std;

int field[50][50];

void dfs(int row, int col) {
	// 인덱스 범위 체크
	if (row < 0 || row >= 50) return;
	if (col < 0 || col >= 50) return;

	// 방문 여부 체크
	if (field[row][col] == 0) return;

	// 방문 처리
	field[row][col] = 0;

	// 상하좌우 탐색
	dfs(row + 1, col);
	dfs(row - 1, col);
	dfs(row, col + 1); 
	dfs(row, col - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int M, N, K;
		cin >> M >> N >> K;
		memset(field, 0, sizeof(field)); // 필드 초기화

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[x][y] = 1;
		}

		int count = 0;
		for (int row = 0; row < M; row++) {
			for (int col = 0; col < N; col++) {
				// 배추가 심어져 있는 경우
				if (field[row][col] == 1) {
					count++; 
					dfs(row, col); // 연결된 모든 배추 방문 처리
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}