#include <iostream>
using namespace std;

int R, C, T, ac_x, ans = 0;
int board[50][50];
int dir[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };

void solve(){
	for (int i = 0; i < T; i++) {
		int board_copy[50][50] = { 0, };
		board_copy[ac_x][0] = -1, board_copy[ac_x + 1][0] = -1;

		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (board[j][k] == -1 || board[j][k] == 0)
					continue;
				int spread_num = 0;
				for (int l = 0; l < 4; l++) {
					int next_x = j + dir[l][0];
					int next_y = k + dir[l][1];
					if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C)
						continue;
					if (board[next_x][next_y] == -1)
						continue;
					board_copy[next_x][next_y] += board[j][k] / 5;
					spread_num++;
				}
				board_copy[j][k] += board[j][k] - ((board[j][k] / 5) * spread_num);
			}
		}

		for (int j = 0; j < R; j++)
			for (int k = 0; k < C; k++)
				board[j][k] = board_copy[j][k];

		for (int j = ac_x - 1; j >= 1; j--)
			board[j][0] = board[j - 1][0];
		for (int j = 0; j < C - 1; j++)
			board[0][j] = board[0][j + 1];
		for (int j = 0; j < ac_x; j++)
			board[j][C - 1] = board[j + 1][C - 1];
		for (int j = C-1; j >= 2; j--)
			board[ac_x][j] = board[ac_x][j - 1];
		board[ac_x][1] = 0;


		for (int j = ac_x + 2; j < R - 1; j++)
			board[j][0] = board[j + 1][0];
		for (int j = 0; j < C - 1; j++)
			board[R - 1][j] = board[R - 1][j + 1];
		for (int j = R - 1; j >= ac_x + 2; j--)
			board[j][C - 1] = board[j - 1][C - 1];
		for (int j = C - 1; j >= 2; j--)
			board[ac_x + 1][j] = board[ac_x + 1][j - 1];
		board[ac_x + 1][1] = 0;
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			if (board[i][j] != -1)
				ans += board[i][j];
		}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag = false;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1 && !flag)
				ac_x = i, flag = true;
		}

	solve();

	cout << ans << "\n";
}