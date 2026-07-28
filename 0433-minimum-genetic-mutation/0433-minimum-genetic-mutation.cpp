#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void bfs(int& answer, string& startGene, string& endGene, vector<string>& bank, vector<bool>& visited) {
        queue<pair<string, int>> q;
        q.push({ startGene, 0 });

        while (!q.empty()) {
            string current = q.front().first;
            int count = q.front().second;
            q.pop();

            if (current == endGene) { 
                answer = count;
                return; 
            }

            for (int i = 0; i < bank.size(); i++) {
                if (!visited[i]) {
                    int diff = 0;
                    for (int j = 0; j < current.size(); j++) {
                        if (current[j] != bank[i][j]) 
                            diff++;
                    }

                    if (diff == 1) {
                        visited[i] = true;
                        q.push({ bank[i], count + 1 });
                    }
                }
            }
        }
        answer = -1;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int answer = 0;
        bool found = false;
        vector<bool> visited(bank.size(), false);

        for (int i = 0; i < bank.size(); i++) {
            if (endGene == bank[i]) {
                found = true;
                break;
            }
        }
        if (!found)
            return -1;

        bfs(answer, startGene, endGene, bank, visited);
        return answer;
    }
};