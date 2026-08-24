#include <queue>
#include <tuple>
#include <vector>
#include <climits>
using namespace std;

class Solution {
   public:
	vector<pair<int, int>> graph[101];
	int dist[101][101];

	void dijkstra(int& src, int& n, int& dst, int& k) {
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		pq.push({0, src, 0});  // <비용, 도시, 경유지 수>
		dist[src][0] = 0;	   // <도시, 경유지 수>

		while (!pq.empty()) {
			int price = get<0>(pq.top());
			int city = get<1>(pq.top());
			int stop = get<2>(pq.top());
			pq.pop();

			if (city == dst) return;
			if (stop > k) continue;

			for (auto& next : graph[city]) {
				int nextCity = get<0>(next);
				int nextPrice = get<1>(next);
				if (dist[nextCity][stop + 1] > price + nextPrice) {
					dist[nextCity][stop + 1] = price + nextPrice;
					pq.push({dist[nextCity][stop + 1], nextCity, stop + 1});
				}
			}
		}
	}

	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k + 1; j++) {
				dist[i][j] = INT_MAX;
			}
		}

		for (auto& flight : flights) {
			int from = flight[0], to = flight[1], price = flight[2];
			graph[from].push_back({to, price});
		}

		dijkstra(src, n, dst, k);

		int answer = INT_MAX;
		for (int i = 0; i <= k + 1; i++) {
			answer = min(answer, dist[dst][i]);
		}

		if (answer == INT_MAX) return -1;
		return answer;
	}
};