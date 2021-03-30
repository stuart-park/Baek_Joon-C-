#include <iostream>	
#include <vector>

int dx[] = { 1, -1, 0,0 };
int dy[] = { 0, 0, 1, -1 };

using namespace std;

void DFS(vector<vector<int>>& arr, vector<vector<bool>>& visited, int j, int k, int m , int n) {
	visited[j][k] = true;

	for (int a = 0; a < 4; a++)
		if (j + dx[a] < n && k + dy[a] < m && j+dx[a]>=0 && k+dy[a]>=0)
			if (arr[j + dx[a]][k + dy[a]] == 1 && visited[j+dx[a]][k+dy[a]]==false)
				DFS(arr, visited, j + dx[a], k + dy[a], m, n);
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int m, n, k, ans = 0;
		cin >> m >> n >> k;
		vector<vector<int>> arr(n, vector<int>(m, 0));
		vector<vector<bool>> visited(n, vector<bool>(m, false));

		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (visited[j][k] == false && arr[j][k] == 1) {
					DFS(arr, visited, j, k,m , n);
					ans++;
				}
			}
		}

		cout << ans << endl;
	}

}
