#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long k, n;	// k: 가지고 있는 랜선의 개수, n: 필요한 랜선의 개수
	cin >> k >> n;

	long long sum = 0;
	vector<long long> length;
	for (int i = 0; i < k; i++) {
		long long len;
		cin >> len;
		length.push_back(len);
		sum += len;
	}

	long long left = 1, right = sum / n;		// left: 랜선의 최소 길이, right: 랜선의 최대 길이
	long long result = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;	// 랜선의 중간 길이
		long long cnt = 0;					// mid 길이로 자른 랜선의 개수

		for (int i = 0; i < length.size(); i++) {
			cnt += length[i] / mid;
		}

		if (cnt >= n) {					// 필요한 랜선의 개수보다 많이 자를 수 있는 경우
			result = mid;
			left = mid + 1;				// 더 긴 랜선을 자를 수 있는지 확인
		}
		else {							// 필요한 랜선의 개수보다 적게 자를 수 있는 경우
			right = mid - 1;			// 더 짧은 랜선을 자를 수 있는지 확인
		}
	}
	cout << result;
	return 0;
}