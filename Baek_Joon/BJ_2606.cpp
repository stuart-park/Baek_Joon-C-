#include <iostream>
using namespace std;

int graph[100][100] = { 0 };
int n, e, c=-1;
bool visited[100] = { false };

void DFS(int u) {
	visited[u] = true;
	c++;
	for (int i = 0; i < n; i++)
		if (graph[u][i] == 1 && visited[i] == false)
			DFS(i);

}

int main() {
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1 - 1][n2 - 1] = 1;
		graph[n2 - 1][n1 - 1] = 1;
	}
	DFS(0);
	cout << c << endl;
}