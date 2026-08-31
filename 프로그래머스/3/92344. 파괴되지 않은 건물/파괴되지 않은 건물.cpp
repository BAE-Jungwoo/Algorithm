#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
	int N = board.size();
	int M = board[0].size();
	vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));

	// 누적합
	for (int i = 0; i < skill.size(); i++) {
		if(skill[i][0] == 1) // type1은 공격
			skill[i][5] *= -1;
		sum[skill[i][1]][skill[i][2]] += skill[i][5];
		sum[skill[i][1]][skill[i][4] + 1] -= skill[i][5];
		sum[skill[i][3] + 1][skill[i][2]] -= skill[i][5];
		sum[skill[i][3] + 1][skill[i][4] + 1] += skill[i][5];
	}

	// 가로 누적합
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			sum[i][j] += sum[i][j - 1];
	}

	// 세로 누적합
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++)
			sum[i][j] += sum[i - 1][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] += sum[i][j];
			if(board[i][j] > 0) 
				answer++;
		}
	}
	return answer;
}