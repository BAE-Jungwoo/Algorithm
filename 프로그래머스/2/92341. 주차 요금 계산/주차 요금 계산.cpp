#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> inTime, totalTime;
    for(int i = 0; i < records.size(); i++) {
        if (records[i][11] == 'I') { // 입차
            inTime[records[i].substr(6, 4)] 
                = 600*(records[i][0]-'0') + 60*(records[i][1]-'0') + 10*(records[i][3]-'0') + (records[i][4]-'0');
        }
        else { // 출차
            totalTime[records[i].substr(6, 4)] 
                += 600*(records[i][0]-'0') + 60*(records[i][1]-'0') + 10*(records[i][3]-'0') + (records[i][4]-'0') 
                - inTime[records[i].substr(6, 4)];
            inTime.erase(records[i].substr(6, 4));
        }
    }
    
    for(auto& entry : inTime) { // 23:59까지 출차 안한 차량
        totalTime[entry.first] += 1439 - entry.second;
    }
    
    for(auto& entry : totalTime) {
        int total = entry.second;
        int cost = fees[1];
        int extra = total - fees[0]; // 기본 시간 초과
        
        if(extra > 0) {
            cost += ((extra + fees[2] - 1) / fees[2]) * fees[3];
        }    
        answer.push_back(cost);
    }
    return answer;
}
