#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 9999999
using namespace std;

int v, farest_vertex = 0, max_dist = 0;
int dist[100001];
bool visited[100001];
vector<pair<int, int>> graph[100001];

void dfs(int vertex, int dist) {
	visited[vertex] = true;

	if (max_dist < dist) {
		max_dist = dist;
		farest_vertex = vertex;
	}

	for (int i = 0; i < graph[vertex].size(); i++) {
		if (!visited[graph[vertex][i].first]) {
			dfs(graph[vertex][i].first, graph[vertex][i].second + dist);
		}
	}
}

int main() {
	cin >> v;

	for (int i = 0; i < v; i++) {
		int num;
		cin >> num;
		while (1) {
			int vertex, edge;
			cin >> vertex;
			if (vertex == -1)
				break;
			else {
				cin >> edge;
				graph[num].push_back(make_pair(vertex, edge));
			}
		}
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	max_dist = 0;
	dfs(farest_vertex, 0);

	cout << max_dist << "\n";
}