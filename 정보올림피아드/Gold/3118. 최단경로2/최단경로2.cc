#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 987654321
using namespace std;

int N, M; // 정점의 개수, 간선의 개수
int dist[1000001];
vector<pair<int, int>> graph[1000001]; // 비용, 목적지 노드

void dijkstra(int start)
{
    priority_queue<pair<int, int>, 
                   vector<pair<int, int>>, 
                   greater<pair<int, int>>> pq;

    pq.push({ 0, start }); // 비용, 목적지 노드
    dist[start] = 0;

    while (!pq.empty())
    {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist[node] < d)
            continue;

        for (auto& edge : graph[node]) {
            int cost = edge.first;
            int next = edge.second;

            if (dist[next] > d + cost) {
                dist[next] = d + cost;
                pq.push({ dist[next], next });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M; // 정점의 수, 간선의 수


    fill(dist, dist + N + 1, INF);

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ c, b });
    }

    dijkstra(1);
    cout << dist[N];

    return 0;
}