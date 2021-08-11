#include <iostream>
using namespace std;

int n, m, x, y, k;
int board[20][20];
int order[1000];
int direction[4][2] = { {0, 1} ,{0, -1},{-1, 0},{1, 0} };
int dice[4][3];

void solve() {
	int dice_bot_r = 1, dice_bot_c = 1, dice_top_r = 3, dice_top_c = 1;
	
	for (int i = 0; i < k; i++) {
		x += direction[order[i]-1][0], y += direction[order[i]-1][1];

		if (x < 0 || x >= n || y < 0 || y >= m) {
			x -= direction[order[i]-1][0], y -= direction[order[i]-1][1];
			continue;
		}
		else {
			if (order[i] == 1) {
				int temp1 = dice[1][0], temp2 = dice[1][2];
				dice[1][0] = dice[1][1], dice[1][2] = dice[3][1];
				dice[3][1] = temp1, dice[1][1] = temp2;
			}
			else if (order[i] == 2) {
				int temp1 = dice[1][0], temp2 = dice[1][2];
				dice[1][0] = dice[3][1], dice[1][2] = dice[1][1];
				dice[3][1] = temp2, dice[1][1] = temp1;
			}
			else if (order[i] == 3) {
				int temp = dice[3][1];
				for (int i = 3; i > 0; i--)
					dice[i][1] = dice[i - 1][1];
				dice[0][1] = temp;
			}
			else if (order[i] == 4) {
				int temp = dice[0][1];
				for (int i = 0; i < 3; i++)
					dice[i][1] = dice[i + 1][1];
				dice[3][1] = temp;
			}

			if (board[x][y] == 0) {
				board[x][y] = dice[dice_bot_r][dice_bot_c];
			}
			else if (board[x][y] != 0) {
				dice[dice_bot_r][dice_bot_c] = board[x][y];
				board[x][y] = 0;
			}

			cout << dice[dice_top_r][dice_top_c] << " ";
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < k; i++)
		cin >> order[i];

	solve();
}