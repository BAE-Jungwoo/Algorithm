#include <iostream>
#include <cstring>
using namespace std;

int M, N; // 가로 M, 세로 N
int field[50][50];

void dfs(int y, int x) {
	// 인덱스 범위 체크
	if (y < 0 || y >= N) return;
	if (x < 0 || x >= M) return;

	// 방문 여부 체크
	if (field[y][x] == 0) return;

	// 방문 처리
	field[y][x] = 0;

	// 상하좌우 탐색
	dfs(y + 1, x); // 아래
	dfs(y - 1, x); // 위
	dfs(y, x + 1); // 오른쪽
	dfs(y, x - 1); // 왼쪽
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> M >> N >> K;
		memset(field, 0, sizeof(field)); // 필드 초기화

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1; // y = row, x = col
		}

		int count = 0;
		for (int y = 0; y < N; y++) { // 세로 N
			for (int x = 0; x < M; x++) { // 가로 M
				// 배추가 심어져 있는 경우
				if (field[y][x] == 1) {
					count++; 
					// (y,x)에서 시작해 상하좌우로 연결된 배추를 모두 0으로
					dfs(y, x); // 연결된 모든 배추 방문 처리
				}
			}
		}
		cout << count << "\n";
	}
	return 0;
}
