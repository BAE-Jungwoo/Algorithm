#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int result = 0;
	int num = 0;
	bool minus = false;

	for (char c : s) {
		if (c == '-' || c == '+') {
			if (minus) {
				result -= num;
			}
			else {
				result += num;
			}
			num = 0;

			if(c == '-') // -를 만나면 이후 모든 숫자들 빼기
				minus = true;
		}
		else {
			num = num * 10 + (c - '0');
		}
	}

	// 마지막 숫자 처리
	if (minus) {
		result -= num;
	}
	else {
		result += num;
	}
	
	cout << result << '\n';
	return 0;
}