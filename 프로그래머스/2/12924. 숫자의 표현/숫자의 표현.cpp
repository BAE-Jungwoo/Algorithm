#include <string>
#include <vector>
using namespace std;

int solution(int n) {
	int answer = 0;
	int start = 1, end = 1;
	while (end <= n) {
		int sum = (end - start + 1) * (end + start) / 2;

		if (sum == n) {
			answer++;
			end++;
		} 
		else if (sum > n)
			start++;
		else
			end++;
	}
	return answer;
}