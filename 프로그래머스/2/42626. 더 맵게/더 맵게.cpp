#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    /*
    sort(scoville.begin(), scoville.end());
    while(scoville[0] < K) {
        if(scoville.size() < 2) {
            return -1;
        }
        scoville[0] = scoville[0] + (scoville[1] * 2);
        scoville.erase(scoville.begin() + 1);
        answer++;
        sort(scoville.begin(), scoville.end());
    }
    */
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.top() < K) {
        if(pq.size() < 2) {
            return -1;
        }
        int first = pq.top(); 
        pq.pop();
        int second = pq.top(); 
        pq.pop();
        pq.push(first + (second * 2));
        answer++;
    }
    return answer;
}