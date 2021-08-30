#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

vector<pair<int, int>> graph[10001];
vector<int> dist;
vector<bool> isMST;

int main() {
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	for (int i = 0; i <= V; i++) {
		dist.push_back(INF);
		isMST.push_back(false);
	}

	dist[1] = 0;
	int result = 0;

	for (int i = 1; i <= V; i++) {
		int minDist = INF;
		int minVertex = -1;
		for (int j = 1; j <= V; j++) {
			if (!isMST[j] && minDist > dist[j]) {
				minDist = dist[j];
				minVertex = j;
			}
		}

		isMST[minVertex] = true;
		result += minDist;

		for (int j = 0; j < graph[minVertex].size(); j++) {
			if (!isMST[graph[minVertex][j].first] && graph[minVertex][j].second < dist[graph[minVertex][j].first])
				dist[graph[minVertex][j].first] = graph[minVertex][j].second;
		}
	}


	cout << result << "\n";
}