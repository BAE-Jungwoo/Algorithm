#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0, cnt = 0;
	sort(people.begin(), people.end(), greater<int>());

    while (people.size() > cnt) {
        if (people[cnt] + people.back() <= limit) {
            answer++;
			cnt++;
			people.pop_back();
		}
        else {
			answer++;
			cnt++;
		}
    }
    return answer;
}