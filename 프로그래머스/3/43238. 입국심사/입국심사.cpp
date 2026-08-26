#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
	long long left = 1;	 // 최소시간
	long long right = (long long)*max_element(times.begin(), times.end()) * n; // 최대시간
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long total = 0;  // mid 시간동안 처리할 수 있는 사람 수
        for (int i = 0; i < times.size(); i++) {
			total += mid / times[i];  // mid 시간동안 처리할 수 있는 사람 수
		}
		if (total >= n) {
			answer = mid;
            right = mid - 1;
		} 
        else {
			left = mid + 1;
		}
	}
	return answer;
}