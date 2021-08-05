#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int v, ans = 0;
int visited[100001] = { false, };
vector<pair<int, int>> graph[100001];

void dfs(int vertex, int total_dist) {
	for (int i = 0; i < graph[vertex].size(); i++) {
		if (!visited[graph[vertex][i].first]) {
			visited[graph[vertex][i].first] = true;
			dfs(graph[vertex][i].first, total_dist + graph[vertex][i].second);
		}
	}

	if (total_dist > ans)
		ans = total_dist;
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

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			visited[i] = true;
			for (int j = 0; j < graph[i].size(); j++) {
				if (!visited[graph[i][j].first]) {
					visited[graph[i][j].first] = true;
					dfs(graph[i][j].first, graph[i][j].second);
				}
			}
		}
		memset(visited, false, sizeof(visited));
	}

	cout << ans << "\n";
}