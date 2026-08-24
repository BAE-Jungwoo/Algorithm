class Solution {
   public:
	vector<pair<int, int>> graph[101];
	int dist[101][101];	 // <도시, 그 도시까지 탄 비행기 수>

	void dijkstra(int& src, int& dst, int& k) {
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
		pq.push({0, src, 0});  // <누적 비용, 도시, 탄 비행기 수>
		dist[src][0] = 0;

		while (!pq.empty()) {
			int price = get<0>(pq.top());  // 누적 비용
			int city = get<1>(pq.top());   // 현재 도시
			int stop = get<2>(pq.top());   // 탄 비행기 수
			pq.pop();

			if (city == dst) return;
			if (stop > k) continue;

			for (auto& next : graph[city]) {
				int nextCity = get<0>(next);   // 다음 도시
				int nextPrice = get<1>(next);  // 다음 도시까지의 비용
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
			graph[flight[0]].push_back({flight[1], flight[2]});
		}

		dijkstra(src, dst, k);

		int answer = INT_MAX;
		for (int i = 0; i <= k + 1; i++) {
			answer = min(answer, dist[dst][i]);
		}

		if (answer == INT_MAX) return -1;
		return answer;
	}
};