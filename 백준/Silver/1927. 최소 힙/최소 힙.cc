#include <iostream>
#include <queue>
#include <functional> // greater<int> 사용
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;
	int n, min = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {		// 배열이 빈 경우
				cout << "0\n";
			}
			else {					// 배열에 원소가 있는 경우
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
	return 0;
}