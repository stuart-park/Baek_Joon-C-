#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
vector<string> apt;
bool visited[25][25] = { false, };

int n, num = 0;

void dfs(int a, int b) {
	visited[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int x = a + dx[i];
		int y = b + dy[i];
		if (x >= 0 && x < n && y >= 0 && y < n)
			if (apt[x].at(y) == '1' && visited[x][y] == false)
				dfs(x, y);
	}

	num++;
	return;
}

int main() {
	std::ios::sync_with_stdio(false);

	cin >> n;

	vector<int> ans;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		apt.push_back(temp);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == false && apt[i].at(j) == '1') {
				dfs(i, j);
				ans.push_back(num);
				num = 0;
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}