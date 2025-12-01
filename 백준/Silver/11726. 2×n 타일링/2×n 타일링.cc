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
	
	for (int i = 0; i < n - 2; i++) {
		dp[i + 3] = (dp[i + 1] + dp[i + 2]) % 10007;
	}
	cout << dp[n] << "\n";
	return 0;
}