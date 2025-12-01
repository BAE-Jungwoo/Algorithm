#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int dp[50001] = {0, };
	for (int i = 1; i <= n; i++) {
		dp[i] = 4; // 최대 4개의 제곱수의 합으로 표현 가능

		// 제곱수의 합을 구하는 점화식
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}