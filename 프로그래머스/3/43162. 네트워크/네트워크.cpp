#include <string>
#include <vector>
using namespace std;

int visited[200] = { 0, };

void dfs(vector<vector<int>>& computers, int start) {
    int size = computers.size();
    
    visited[start] = 1;
    for (int i = 0; i < size; i++) {
        if (computers[start][i] == 1 && start != i) {
            int next = i;
            if(!visited[next])
                dfs(computers, next);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0; // 네트워크 개수

    for (int i = 0; i < computers.size(); i++) {
        if (visited[i] == 0) {
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}