#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[20001]; // 방문 여부
int furthest[20001] = { 0 }; // furthest[i] = i번째 노드까지의 거리
int count = 0;
int max_distance = 0;

void bfs(int start, int n, const vector<vector<int>>& arr) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 2; i <= n; i++) {
            if (arr[current][i] == 0) continue; // 연결되어 있지 않으면 패스
            if (visited[i] == 1) continue; // 이미 방문했으면 패스

            visited[i] = 1;
            furthest[i] = furthest[current] + 1; // 현재 노드까지의 거리 + 1
            q.push(i);

            if (furthest[i] > max_distance) {
                max_distance = furthest[i];
                count = 1; // 새로운 최대 거리 발견 시 카운트 초기화
            } 
            else if (furthest[i] == max_distance) {
                count++; // 최대 거리와 같은 노드 발견 시 카운트 증가
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= edge.size(); i++) {
        arr[edge[i - 1][0]][edge[i - 1][1]] = 1;
        arr[edge[i - 1][1]][edge[i - 1][0]] = 1;
    }

    bfs(1, n, arr);
    answer = count;
    return answer;
}