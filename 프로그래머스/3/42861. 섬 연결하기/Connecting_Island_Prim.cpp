#include <iostream>
#include <string>
#include <vector>
#define INT_MAX 987654321
using namespace std;


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < costs.size(); i++)
    {
        graph[costs[i][0]][costs[i][1]] = costs[i][2];
        graph[costs[i][1]][costs[i][0]] = costs[i][2];
    }

    vector<int> visited;
    vector<int> unvisited;

	visited.push_back(0); // 시작 정점만
	for (int i = 1; i < n; i++)
		unvisited.push_back(i); // 아직 방문하지 않은 정점들

	for (int i = 1; i < n; i++)	// 시작 정점을 제외한 나머지 정점 선택 과정
	{
		int min = INT_MAX;
		int min_index = 0;

		for (int j = 0; j < i; j++)	// visited 순회
		{
			for (int k = 0; k < n - i; k++)	// unvisited 순회
			{
				if (graph[visited[j]][unvisited[k]] > 0 && min > graph[visited[j]][unvisited[k]])
				{
					min = graph[visited[j]][unvisited[k]];
					min_index = k;
				}
			}
		}

		visited.push_back(unvisited[min_index]);
		unvisited.erase(unvisited.begin() + min_index);
		answer += min;
	}

    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> costs = { {0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {2,3,8} };
    int result = solution(n, costs);
    cout << "result : " << result;
    return 0;
}