#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start_x, int start_y, vector<vector<char>>& campus) {
	int n = campus.size();
	int m = campus[0].size();
	bool visited[601][601] = { false };

	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = true;
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	int count = 0;

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = current.first + dx[i];
			int ny = current.second + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (!visited[nx][ny] && campus[nx][ny] != 'X') {
					visited[nx][ny] = true;
					q.push({ nx, ny });
					if (campus[nx][ny] == 'P') {
						count++;
					}
				}
			}
		}
	}
	if(count == 0)
		cout << "TT";
	else
		cout << count;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> campus(n);

	int start_x = 0, start_y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char ch;
			cin >> ch;
			if(ch == 'I')
				start_x = i, start_y = j;
			campus[i].push_back(ch);
		}
	}

	bfs(start_x, start_y, campus);
	return 0;
}