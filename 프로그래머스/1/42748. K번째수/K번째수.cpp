#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, temp, v;
    int i, j;
    
    for(i = 0; i < commands.size(); i++) {
        temp.clear(); v.clear();
        for(j = 0; j < commands[0].size(); j++) {
            temp.push_back(commands[i][j]);
        }
        for(int k = temp[0] - 1; k < temp[1]; k++) {
            v.push_back(array[k]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[temp[2] - 1]);
    }
    return answer;
}