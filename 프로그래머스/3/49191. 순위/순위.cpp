#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    for (auto& iter : results) {
		graph[iter[0]][iter[1]] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] && graph[k][j]) {
                    graph[i][j] = true;
                }
            }
        }
    }

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
            if (i == j)continue;
			if (graph[i][j] || graph[j][i]) {
				cnt++;
			}
		}
		if (cnt == n - 1) {
			answer++;
		}
	}
    return answer;
}