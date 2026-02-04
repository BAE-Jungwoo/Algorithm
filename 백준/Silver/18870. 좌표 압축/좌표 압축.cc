#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> arr;
	vector<int> sorted_arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
		sorted_arr.push_back(x);
	}

	sort(sorted_arr.begin(), sorted_arr.end());
	sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		cnt = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin();
		cout << cnt << " ";
	}
	return 0;
}