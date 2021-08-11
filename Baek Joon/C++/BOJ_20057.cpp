#include <iostream>
using namespace std;

int N, ans = 0;
int board[500][500];
int dir[4][2] = { {0, -1},{1, 0},{0 ,1},{-1, 0} };

int left_move[10][2] = { {-2, 0},{-1, -1},{-1, 0},{-1, 1},{0, -2},{1, -1},{1, 0},{1, 1},{2, 0} };
int down_move[10][2] = { {0, -2},{1, -1},{0, -1},{-1, -1},{2, 0},{1, 1},{0, 1},{-1, 1},{0, 2} };
int right_move[10][2] = { {-2, 0},{-1, 1},{-1, 0},{-1, -1},{0, 2},{1, 1},{1, 0},{1, -1},{2, 0} };
int up_move[10][2] = { {0, -2} ,{-1, -1} ,{0, -1} ,{1, -1} ,{-2, 0} ,{-1, 1} ,{0, 1} ,{1,1} ,{0, 2} };
double sand_ratio[10] = { 0.02, 0.1, 0.07, 0.01, 0.05, 0.1, 0.07, 0.01, 0.02 };

void solve() {
	int t_x = N / 2, t_y = N / 2; //시작점
	int i = 0;//방향 변수
	int j = 1;//이동 칸 변수
	while (1) {
		int move_num = 0;

		while (move_num < j) {
			if (t_x == 0 && t_y == 0)
				return;

			t_x += dir[i][0];
			t_y += dir[i][1];

			if (i == 0) { //left
				int total = board[t_x][t_y];

				for (int j = 0; j < 9; j++) {
					int next_x = t_x + left_move[j][0];
					int next_y = t_y + left_move[j][1];

					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
						ans += (int)(board[t_x][t_y] * sand_ratio[j]);
					else
						board[next_x][next_y] += (int)(board[t_x][t_y] * sand_ratio[j]);

					total -= (int)(board[t_x][t_y] * sand_ratio[j]);
				}
				if (t_y - 1 < 0)
					ans += total;
				else
					board[t_x][t_y - 1] += total;
				board[t_x][t_y] = 0;
			}
			else if (i == 1) { //down
				int total = board[t_x][t_y];

				for (int j = 0; j < 9; j++) {
					int next_x = t_x + down_move[j][0];
					int next_y = t_y + down_move[j][1];

					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
						ans += (int)(board[t_x][t_y] * sand_ratio[j]);
					else
						board[next_x][next_y] += (int)(board[t_x][t_y] * sand_ratio[j]);

					total -= (int)(board[t_x][t_y] * sand_ratio[j]);
				}
				if (t_x + 1 >= N)
					ans += total;
				else
					board[t_x + 1][t_y] += total;
				board[t_x][t_y] = 0;
			}
			else if (i == 2) { // right
				int total = board[t_x][t_y];

				for (int j = 0; j < 9; j++) {
					int next_x = t_x + right_move[j][0];
					int next_y = t_y + right_move[j][1];

					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
						ans += (int)(board[t_x][t_y] * sand_ratio[j]);
					else
						board[next_x][next_y] += (int)(board[t_x][t_y] * sand_ratio[j]);

					total -= (int)(board[t_x][t_y] * sand_ratio[j]);
				}
				if (t_y + 1 >= N)
					ans += total;
				else
					board[t_x][t_y + 1] += total;
				board[t_x][t_y] = 0;
			}
			else if (i == 3) { //up
				int total = board[t_x][t_y];

				for (int j = 0; j < 9; j++) {
					int next_x = t_x + up_move[j][0];
					int next_y = t_y + up_move[j][1];

					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
						ans += (int)(board[t_x][t_y] * sand_ratio[j]);
					else
						board[next_x][next_y] += (int)(board[t_x][t_y] * sand_ratio[j]);

					total -= (int)(board[t_x][t_y] * sand_ratio[j]);
				}
				if (t_x - 1 < 0)
					ans += total;
				else
					board[t_x - 1][t_y] += total;
				board[t_x][t_y] = 0;
			}

			move_num++;
		}

		i = (i + 1) % 4;
		if (i % 2 == 0)
			j += 1;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	solve();

	cout << ans << "\n";

}