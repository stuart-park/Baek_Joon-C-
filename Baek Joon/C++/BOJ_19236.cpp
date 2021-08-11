#include <iostream>
using namespace std;

int board[4][4];
int fish_info[16];
int fish_pos[16][2];
bool isEaten[16] = { false, };
int direction[8][2] = { {-1, 0},{-1, -1},{0, -1},{1, -1},{1, 0},{1, 1},{0, 1},{-1, 1} };
int ans = 0;

void moveFish() {
	for (int i = 0; i < 16; i++) {
		if (!isEaten[i]) {
			for (int j = 0; j < 8; j++) {
				int next_x = fish_pos[i][0] + direction[fish_info[i]][0];
				int next_y = fish_pos[i][1] + direction[fish_info[i]][1];
				if (next_x < 0 || next_x >= 4 || next_y < 0 || next_y >= 4)
					fish_info[i] = (fish_info[i] + 1) % 8;
				else if (board[next_x][next_y] == -1)
					fish_info[i] = (fish_info[i] + 1) % 8;
				else {
					if (board[next_x][next_y] == 0) {
						board[fish_pos[i][0]][fish_pos[i][1]] = 0;
						fish_pos[i][0] = next_x, fish_pos[i][1] = next_y, board[next_x][next_y] = i + 1;
					}
					else {
						int temp = board[next_x][next_y], temp_x = fish_pos[temp - 1][0], temp_y = fish_pos[temp - 1][1];
						board[next_x][next_y] = i + 1;
						board[fish_pos[i][0]][fish_pos[i][1]] = temp;
						fish_pos[temp - 1][0] = fish_pos[i][0], fish_pos[temp - 1][1] = fish_pos[i][1];
						fish_pos[i][0] = temp_x, fish_pos[i][1] = temp_y;
					}
					break;
				}
			}
		}
	}
}

void solve(int s_x, int s_y, int total_sum ) {
	if (s_x < 0 || s_x >= 4 || s_y < 0 || s_y >= 4) {
		if (total_sum > ans)
			ans = total_sum;
		return;
	}
	if (board[s_x][s_y] == 0) {
		if (total_sum > ans)
			ans = total_sum;
		return;
	}

	int temp_board[4][4], temp_fish_info[16], temp_fish_pos[16][2];
	int s_dir = fish_info[board[s_x][s_y] - 1];
	int fish_num = board[s_x][s_y];
	isEaten[board[s_x][s_y] - 1] = true, board[s_x][s_y] = -1;
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			temp_board[i][j] = board[i][j];
	for (int i = 0; i < 16; i++) {
		temp_fish_info[i] = fish_info[i];
		temp_fish_pos[i][0] = fish_pos[i][0], temp_fish_pos[i][1] = fish_pos[i][1];
	}

	moveFish();

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";*/

	for (int i = 1; i < 4; i++) {
		int next_x = s_x + direction[s_dir][0] * i;
		int next_y = s_y + direction[s_dir][1] * i;
		
		board[s_x][s_y] = 0;
		solve(next_x, next_y, total_sum + fish_num);
		board[s_x][s_y] = -1;
	}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			board[i][j] = temp_board[i][j];
	for (int i = 0; i < 16; i++) {
		fish_info[i] = temp_fish_info[i];
		fish_pos[i][0] = temp_fish_pos[i][0], fish_pos[i][1] = temp_fish_pos[i][1];
	}
	board[s_x][s_y] = fish_num;
	isEaten[board[s_x][s_y] - 1] = false;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			board[i][j] = a, fish_info[a - 1] = b - 1;
			fish_pos[a - 1][0] = i, fish_pos[a - 1][1] = j;
		}
	}

	solve(0, 0, 0);

	cout << ans << "\n";
}