#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
int component = 0;

void dfs(int node) {
	stack<int> s;
	s.push(node);
	visited[node] = true;

	while (!s.empty()) {
		int current = s.top();
		s.pop();

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (!visited[next]) {
				visited[next] = true;
				s.push(next);
			}
		}
	}
	component++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	cout << component << "\n";
	return 0;
}