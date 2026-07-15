#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[51] = {
    false,
};

void bfs(int &answer, string begin, string &target, vector<string> &words)
{
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while (!q.empty())
    {
        string current = q.front().first;
        int count = q.front().second;
        q.pop();

        if (current == target)
        {
            answer = count;
            return;
        }

        for (int i = 0; i < words.size(); i++)
        {
            if (!visited[i])
            {
                int diff = 0;
                for (int j = 0; j < current.size(); j++)
                {
                    if (current[j] != words[i][j])
                        diff++;
                }
                if (diff == 1)
                {
                    visited[i] = true;
                    q.push({words[i], count + 1});
                }
            }
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    bool found = false;
    int len = words[0].size();
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
            found = true;
    }
    if (!found)
        return answer;
    else
        bfs(answer, begin, target, words);

    return answer;
}