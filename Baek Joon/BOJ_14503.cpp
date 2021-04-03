#include <iostream>
#include <queue>
using namespace std;

int n, m, r, c, dir, ans = 1;
int board[50][50];
bool visited[50][50];
int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1,0} };
int back[4][2] = { {1, 0},{0, 1},{-1, 0},{0, -1} };

void solve(int cur_r, int cur_c, int cur_dir){
	visited[cur_r][cur_c] = true;

	while (1) {
		for (int i = 0; i < 4; i++) {
			int new_x = cur_r + direction[cur_dir][0];
			int new_y = cur_c + direction[cur_dir][1];

 			if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && visited[new_x][new_y] == false && board[new_x][new_y] != 1) {
				cur_r += direction[cur_dir][0], cur_c += direction[cur_dir][1];
				visited[new_x][new_y] = true;
				cur_dir = (cur_dir + 1) % 4;
				ans++;
				i = -1;
			}
			else
				cur_dir = (cur_dir + 1) % 4;
		}

		cur_r = cur_r + back[cur_dir][0];
		cur_c = cur_c + back[cur_dir][1];

		if (board[cur_r][cur_c] == 1)
			break;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r >> c >> dir;
	// dir-> 0: North, 1: West, 2: South, 3: East
	if (dir == 1)
		dir = 3;
	else if (dir == 3)
		dir = 1;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
 			cin >> board[i][j];

	solve(r, c, dir);

	cout << ans << "\n";
}