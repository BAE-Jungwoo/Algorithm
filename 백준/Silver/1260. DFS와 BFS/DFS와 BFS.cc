#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visitied[1001];

void bfs(int start) {
	queue<int> q;
	visitied[start] = true;
	q.push(start);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << " ";
		for (int i = 0; i < graph[current].size(); i++) {
			// 정점 번호가 작은 것부터 방문하기 위해 정렬
			if (graph[current].size() > 1) {
				sort(graph[current].begin(), graph[current].end());
			}
			int next = graph[current][i];
			if (!visitied[next]) {
				visitied[next] = true;
				q.push(next);
			}
		}
	}

}

// 재귀 (Stack도 가능)
void dfs(int start) {
	visitied[start] = true;
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		// 정점 번호가 작은 것부터 방문하기 위해 정렬
		if (graph[start].size() > 1) {
			sort(graph[start].begin(), graph[start].end());
		}
		int next = graph[start][i];
		if (!visitied[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, v; // 정점, 간선, 시작 정점
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		// 양방향 간선
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(v);
	cout << "\n";

	fill(visitied, visitied + 1001, false); // 초기화
	bfs(v);

	return 0;
}