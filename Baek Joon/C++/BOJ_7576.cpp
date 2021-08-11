#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tomato[1000][1000];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0 , 0, 1, -1 };

int main() {
	std::ios_base::sync_with_stdio(false);

	int m, n, day;
	cin >> m >> n;

	queue<pair<pair<int, int>,int>> ripe;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if(tomato[i][j]==1)
				ripe.push(make_pair(make_pair(i, j), 0));
		}


	while (!ripe.empty()) {
		int x = ripe.front().first.first;
		int y = ripe.front().first.second;
		day = ripe.front().second;

		ripe.pop();

		for (int i = 0; i < 4; i++) {
			int _x = x + dx[i];
			int _y = y + dy[i];

			if (_x >= 0 && _x < n && _y >= 0 && _y < m && tomato[_x][_y]==0) {
				tomato[_x][_y] = 1;
				ripe.push(make_pair(make_pair(_x, _y), day + 1));
			}
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (tomato[i][j] == 0) {
				cout << "-1" << '\n';
				return 0;
			}

	cout << day << '\n';
}