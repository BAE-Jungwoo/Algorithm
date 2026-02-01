#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long tree, length, height; // 나무의 수, 나무의 길이, 나무의 높이
	cin >> tree >> length;

	vector<long long> v;
	int max = 0;
	for (int i = 0; i < tree; i++) {
		cin >> height;
		if(height >= max)
			max = height;
		v.push_back(height);
	}

	long long  left = 0, right = max;
	long long result = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;	// 절단기 높이
		long long sum = 0;

		for (int i = 0; i < tree; i++) {
			if (v[i] > mid) {
				sum += v[i] - mid;
			}
		}

		if (sum >= length) {
			if (result < mid)
				result = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << result;
	return 0;
}