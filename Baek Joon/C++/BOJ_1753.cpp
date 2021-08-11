#include <iostream>
#include <vector>
#include <queue>
#define	INF 999999999
using namespace std;

vector<pair<int, int>> graph[20001];
int dist[20001];
int vertex, edge;

void dijkstra(int start) {
	for (int i = 1; i <= vertex; i++)
		dist[i] = INF;
	dist[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(dist[start], start));

	while (!pq.empty()) {
		int cur_vertex = pq.top().second;
		int cur_dist = -1 * pq.top().first;
		pq.pop();

		if (dist[cur_vertex] < cur_dist)
			continue;

		for (int i = 0; i < graph[cur_vertex].size(); i++) {
			int next_vertex = graph[cur_vertex][i].second;
			int next_dist = cur_dist + graph[cur_vertex][i].first;
			if (next_dist < dist[next_vertex]) {
				dist[next_vertex] = next_dist;
				pq.push(make_pair(-1 * next_dist, next_vertex));
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int start;
	cin >> vertex >> edge >> start;
	for (int i = 0; i < edge; i++) {
		int s, d, w;
		cin >> s >> d >> w;
		graph[s].push_back(make_pair(w, d));
	}

	dijkstra(start);

	for (int i = 1; i <= vertex; i++) {
		if (i == start)
			cout << "0" << "\n";
		else if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}