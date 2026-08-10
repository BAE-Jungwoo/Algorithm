#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer) {
	for (int i = 0; i < tickets.size(); i++) {
		if (!visited[i] && tickets[i][0] == answer.back()) {
			visited[i] = true;
			answer.push_back(tickets[i][1]);
			dfs(tickets, visited, answer);
			// 모든 티켓을 사용한 경우
			if (answer.size() == tickets.size() + 1) {
				return;
			}
			// 모든 티켓을 사용하지 못한 경우
			visited[i] = false;
			answer.pop_back();
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer = {"ICN"};
	sort(tickets.begin(), tickets.end());
    vector<bool> visited(tickets.size(), false);

    dfs(tickets, visited, answer);
    return answer;
}