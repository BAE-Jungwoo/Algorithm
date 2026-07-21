#include <vector>
#include <queue>
using namespace std;

bool visited[101][101] = { false, };
int dist[101][101] = { 0, };
int dy[4] = { 0, 0, -1, 1 };    // 상, 하
int dx[4] = { -1, 1, 0, 0 };    // 좌, 우

// N x M 크기의 맵
int solution(vector<vector<int> > maps)
{
    // (1, 1)에서 시작하기 위해
    vector<vector<int>> map(maps.size() + 1, vector<int>(maps[0].size() + 1));
    for (int i = 1; i <= maps.size(); i++) {
        for (int j = 1; j <= maps[0].size(); j++) {
            map[i][j] = maps[i - 1][j - 1];
        }
    }

    int N = map.size(), M = map[0].size(); // 행, 열
    queue<pair<int, int>> path;
    path.push({ 1, 1 }); // 시작점 (y, x)
    visited[1][1] = true;
    dist[1][1] = 1;

    while (!path.empty()) {
        pair<int, int> temp = path.front();
        path.pop();

        for (int i = 0; i < 4; i++) {   // 좌, 우, 상, 하
            int ny = temp.first + dy[i];
            int nx = temp.second + dx[i];

            if (nx >= 1 && nx < M && ny >= 1 && ny < N) {
                if (map[ny][nx] == 1 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    path.push({ ny, nx });
                    dist[ny][nx] = dist[temp.first][temp.second] + 1;

                    if (ny == N - 1 && nx == M - 1)
                        return dist[ny][nx];
                }
            }
        }
    }
    return -1;
}