#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> prg, spd;

    for(int i = 0; i < progresses.size(); i++) {
        prg.push(progresses[i]);
        spd.push(speeds[i]);
    }


    while(!prg.empty()) {
        int cnt = 0, result = 0;

        while (prg.front() < 100) {
            prg.front() += spd.front();
            cnt++;
        }
        prg.pop(); spd.pop();
        result++;

        while (!prg.empty()) {
            if((prg.front() + (cnt * spd.front())) >= 100) {
                prg.pop(); spd.pop();
                result++;
            }
            else break;
        }
        answer.push_back(result);
    }
    return answer;
}