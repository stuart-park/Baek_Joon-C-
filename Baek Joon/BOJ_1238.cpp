#include <iostream>
#include <queue>
#include <vector>

#define INF 999999999

using namespace std;

int N, M, X;
int dist_to_X[1001];
int dist_from_X[1001];
vector<pair<int, int>> arr[1001];

int dijkstra(int start) {
	for (int i = 0; i <= N; i++)
		dist_to_X[i] = INF;

	dist_to_X[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, dist_to_X[start]));

	while (!pq.empty()) {
		int cur_pos = pq.top().first;
		int cur_dist = pq.top().second;
		pq.pop();

		if (dist_to_X[cur_pos] < cur_dist)
			continue;

		for (int i = 0; i < arr[cur_pos].size(); i++) {
			int next_pos = arr[cur_pos][i].first;
			int next_dist = cur_dist + arr[cur_pos][i].second;

			if (next_dist < dist_to_X[next_pos]) {
				dist_to_X[next_pos] = next_dist;
				pq.push(make_pair(next_pos, next_dist));
			}
		}
	}

	return dist_to_X[X];
}

int main() {
	std::ios_base::sync_with_stdio(false);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int start, dest, cost;
		cin >> start >> dest >> cost;
		arr[start].push_back(make_pair(dest, cost));
	}

	int ans = 0;
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		dist_from_X[i] = dist_to_X[i];
	}
	for (int i = 1; i <= N; i++) {
		if (i == X)
			continue;
		int d = dijkstra(i) + dist_from_X[i];

		if (ans < d)
			ans = d;
	}

	cout << ans << "\n";
}