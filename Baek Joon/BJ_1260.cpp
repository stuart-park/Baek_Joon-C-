#include <vector>
#include <iostream>
#include <queue>

int graph[1000][1000];
bool visited[1000] = { false };
int n, m, s, u, v;

using namespace std;

void reset() {
	for (int i = 0; i < n; i++)
		visited[i] = false;
}

void DFS(int u) {
	visited[u] = true;
	cout << u + 1 << ' ';
	for (int i = 0; i < n; i++)
		if (graph[u][i] == 1 && visited[i] == false)
			DFS(i);

}

void BFS() {
	queue<int> pos;
	pos.push(s - 1);
	visited[s - 1] = true;

	while (pos.empty() == false) {
		int temp = pos.front();
		cout << temp + 1 << ' ';
		pos.pop();
		for (int i = 0; i < n; i++) {
			if (graph[temp][i] == 1 && visited[i] == false) {
				pos.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u - 1][v - 1] = 1;
		graph[v - 1][u - 1] = 1;
	}
	reset();
	DFS(s - 1);
	reset();
	cout << endl;
	BFS();
}