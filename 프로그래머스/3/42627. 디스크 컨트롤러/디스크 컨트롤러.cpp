#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct work {
    int id;     // 번호
    int request;  // 요청 시각
    int time;   // 소요 시간
};

// 소요 시간이 짧은 것, 요청 시각이 빠른 것, 번호가 작은 것 순으로 정렬
struct compare {
    bool operator() (const work &a, const work &b) {
        if(a.time == b.time) {
            if(a.request == b.request) {
                return a.id > b.id;
            }
            return a.request > b.request;
        }
        return a.time > b.time;
    }
};

// 요청 시각이 빠른 순으로 정렬
bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<work, vector<work>, compare> diskController;

    sort(jobs.begin(), jobs.end(), cmp);

    int current_time = 0; // 현재 시각
    int size = jobs.size();
    int idx = 0; // jobs의 인덱스

    while(idx < size || !diskController.empty()) {
        // 큐가 비어있고, 현재 시각이 다음 작업의 요청 시각보다 빠른 경우
        // 현재 시각을 다음 작업의 요청 시각으로 이동
        if(diskController.empty() && idx < size && current_time < jobs[idx][0]) {
            current_time = jobs[idx][0];
        }

        // 현재 시각까지 요청된 작업들을 우선순위 큐에 넣음
        while (idx < size && jobs[idx][0] <= current_time) {
            diskController.push({idx, jobs[idx][0], jobs[idx][1]});
            idx++;
        }

        // 우선순위 큐에서 작업을 꺼내어 처리
        if(!diskController.empty()) {
            work current_work = diskController.top();
            diskController.pop();
            
            current_time += current_work.time;
            answer += current_time - current_work.request;
        }
    }
    return answer / size;
}