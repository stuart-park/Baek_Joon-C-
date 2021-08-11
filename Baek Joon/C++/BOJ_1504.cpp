#include <iostream>
#include <queue>
#include <vector>
#define INF 99999999
using namespace std;

vector<pair<int, int>> graph[801];
int dist[801];

int dijkstra(int start, int end) {
	for (int i = 0; i < 801; i++)
		dist[i] = INF;

	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, dist[start]));

	while (!pq.empty()) {
		int cur_pos = pq.top().first;
		int cur_dist = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur_pos].size(); i++) {
			int next_pos = graph[cur_pos][i].first;
			int next_dist = cur_dist + graph[cur_pos][i].second;
			if (dist[next_pos] > next_dist) {
				dist[next_pos] = next_dist;
				pq.push(make_pair(next_pos, next_dist));
			}
		}
	}

	return dist[end];
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int N, E, v1, v2;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	int ans = min(dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N), dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N));
	if (ans >= INF)
		cout << "-1" << "\n";
	else
		cout << ans << "\n";
}