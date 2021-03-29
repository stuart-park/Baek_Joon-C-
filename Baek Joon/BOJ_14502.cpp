#include <iostream>
#include <queue>
using namespace std;

int n, m, ans = 0;
int board[8][8];
int temp[8][8];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int count_save_zone() {
	int safe_zone = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (temp[i][j] == 0)
				safe_zone++;
	
	return safe_zone;
}

void BFS() {
	queue<pair<int, int>> virus;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			temp[i][j] = board[i][j];
			if (board[i][j] == 2)
				virus.push(make_pair(i, j));
		}

	while (!virus.empty()) {
		int cur_x = virus.front().first;
		int cur_y = virus.front().second;

		virus.pop();

		for (int i = 0; i < 4; i++) {
			int new_x = cur_x + dx[i];
			int new_y = cur_y + dy[i];

			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && temp[new_x][new_y] == 0) {
				temp[new_x][new_y] = 2;
				virus.push(make_pair(new_x, new_y));
			}
		}
	}

	int safe = count_save_zone();
	if (ans < safe)
		ans = safe;
}

void make_wall(int cnt) {
	if (cnt == 3) {
		BFS();
		return;
	}

	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == 0) {
					board[i][j] = 1;
					make_wall(cnt + 1);
					board[i][j] = 0;
				}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> board[i][j];

	make_wall(0);

	cout << ans << "\n";
}