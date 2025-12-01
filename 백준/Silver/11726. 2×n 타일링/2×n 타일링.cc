#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int dp[1001] = { 0 };
	dp[1] = 1;
	dp[2] = 2;
	
	// 맨 오른쪽에 1x2 타일 1개를 세로로 놓는 경우 → dp[i - 1]개
	// 맨 오른쪽에 2x1 타일 2개를 가로로 놓는 경우 → dp[i - 2]개
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}
	cout << dp[n] << "\n";
	return 0;
}
