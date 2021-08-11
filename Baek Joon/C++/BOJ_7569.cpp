#include <iostream>
#include <queue>
using namespace std;


int tomato[100][100][100];

int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0,0, 1, -1 };

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n, h, day, not_ripe=0;
	cin >> m >> n >> h;

	queue <pair<int, int>> ripe1;
	queue<pair<int, int>> ripe2;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					ripe1.push(make_pair(i, j));
					ripe2.push(make_pair(k, 0));
				}
				if (tomato[i][j][k] == 0)
					not_ripe++;
			}
		}
	}

	while (!ripe1.empty()) {
		int x = ripe1.front().first;
		int y = ripe1.front().second;
		int z = ripe2.front().first;
		day = ripe2.front().second;

		ripe1.pop();
		ripe2.pop();

		for (int i = 0; i < 6; i++) {
			int _x = x + dx[i];
			int _y = y + dy[i];
			int _z = z + dz[i];

			if (_x >= 0 && _x < h && _y >= 0 && _y < n && _z >= 0 && _z < m && tomato[_x][_y][_z] == 0) {
				tomato[_x][_y][_z] = 1;
				not_ripe--;
				ripe1.push(make_pair(_x, _y));
				ripe2.push(make_pair(_z, day + 1));
			}
		}
	}

	if (not_ripe == 0)
		cout << day << '\n';
	else
		cout << "-1" << '\n';
}