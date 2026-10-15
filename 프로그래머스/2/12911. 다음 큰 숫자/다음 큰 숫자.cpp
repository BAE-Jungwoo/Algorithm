#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void conv(int num, int& count) {
	string binary;
    while (num > 0) {
		binary += (num % 2 == 0 ? "0" : "1");
		if (num % 2 == 1) count++;
		num /= 2;
	}
	reverse(binary.begin(), binary.end());
}

int solution(int n) {
	int answer = 0, n_cnt = 0, next_cnt = 0;
	conv(n, n_cnt);

	for (int answer = n + 1; ; answer++) {
		next_cnt = 0;
		conv(answer, next_cnt);
		if (next_cnt == n_cnt) return answer;
	}
}