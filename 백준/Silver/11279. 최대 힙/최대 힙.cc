#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	priority_queue<int, vector<int>, less<>> maxHeap;
	vector<int> result;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		if (x > 0) {
			maxHeap.push(x);
		}
		else if (x == 0) {
			if (maxHeap.empty()) {
				result.push_back(0);
				continue;
			}
			result.push_back(maxHeap.top());
			maxHeap.pop();
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}
	return 0;
}