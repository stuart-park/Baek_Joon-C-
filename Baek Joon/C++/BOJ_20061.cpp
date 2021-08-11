#include <iostream>
#include <queue>
using namespace std;

int N, point = 0, tile_num = 0;
int board[10][10] = { 0, };
int block_input[10000][3];

void movetoGreen(int a, int b, int block_type) {
	queue<pair<int, int>> pos;
	pos.push(make_pair(a, b));
	int final_x = -1, final_y = -1;

	while (!pos.empty()) { // Move to blue area
		int cur_x = pos.front().first;
		int cur_y = pos.front().second;

		pos.pop();

		int next_x = cur_x + 1;
		int next_y = cur_y;

		if (next_x < 10 && block_type == 1 && board[next_x][next_y] == 0)
			pos.push(make_pair(next_x, next_y)), final_x = next_x, final_y = next_y;
		else if (next_x < 10 && block_type == 2 && board[next_x][next_y] == 0 && board[next_x][next_y + 1] == 0)
			pos.push(make_pair(next_x, next_y)), final_x = next_x, final_y = next_y;
		else if (next_x < 9 && block_type == 3 && board[next_x][next_y] == 0 && board[next_x + 1][next_y] == 0)
			pos.push(make_pair(next_x, next_y)), final_x = next_x, final_y = next_y;
	}

	if (block_type == 1)
		board[final_x][final_y] = 1;
	else if (block_type == 2)
		board[final_x][final_y] = 1, board[final_x][final_y + 1] = 1;
	else if (block_type == 3)
		board[final_x][final_y] = 1, board[final_x + 1][final_y] = 1;
}

void movetoBlue(int a, int b, int block_type) {
	queue<pair<int, int>> pos;
	pos.push(make_pair(a, b));
	int final_x = -1, final_y = -1;

	while (!pos.empty()) { // Move to blue area
		int cur_x = pos.front().first;
		int cur_y = pos.front().second;

		pos.pop();

		int next_x = cur_x;
		int next_y = cur_y + 1;

		if (next_y < 10 && block_type == 1 && board[next_x][next_y] == 0)
			pos.push(make_pair(next_x, next_y)), final_x = next_x, final_y = next_y;
		else if (next_y < 9 && block_type == 2 && board[next_x][next_y] == 0 && board[next_x][next_y + 1] == 0)
			pos.push(make_pair(next_x, next_y)), final_x = next_x, final_y = next_y;
		else if (next_y < 10 && block_type == 3 && board[next_x][next_y] == 0 && board[next_x + 1][next_y] == 0)
			pos.push(make_pair(next_x, next_y)), final_x = next_x, final_y = next_y;
	}

	if (block_type == 1)
		board[final_x][final_y] = 1;
	else if (block_type == 2)
		board[final_x][final_y] = 1, board[final_x][final_y + 1] = 1;
	else if (block_type == 3)
		board[final_x][final_y] = 1, board[final_x + 1][final_y] = 1;
}

void searchBlue() {
	int num = 0;
	for (int i = 9; i >= 6; i--) { // blue 영역에서 1열에 타일이 채워졌는지 확인
		for (int j = 0; j < 4; j++)
			num += board[j][i];
		if (num == 4) {
			point += 1;
			for (int j = 0; j < 4; j++)
				board[j][i] = 0;
			for (int j = i; j >= 6; j--)
				for (int k = 0; k < 4; k++)
					board[k][j] = board[k][j - 1];	
			for (int j = 0; j < 4; j++)
				board[j][5] = 0;
			i = 10;
		}
		num = 0;
	}

	for (int i = 4; i < 6; i++) { // 특별 구역에 타일 있는지 확인
		for (int j = 0; j < 4; j++) {
			if (i == 4 && board[j][i] == 1) {
				for (int k = 8; k < 10; k++)
					for (int l = 0; l < 4; l++)
						board[l][k] = 0;
				for (int k = 9; k >= 6; k--)
					for (int l = 0; l < 4; l++)
						board[l][k] = board[l][k - 2];
				for (int k = 4; k < 6; k++)
					for (int l = 0; l < 4; l++)
						board[l][k] = 0;
			}
			else if (i == 5 && board[j][i] == 1) {
				for (int k = 0; k < 4; k++)
					board[k][9] = 0;
				for (int k = 9; k >= 6; k--)
					for (int l = 0; l < 4; l++)
						board[l][k] = board[l][k - 1];
				for (int l = 0; l < 4; l++)
					board[l][5] = 0;
			}
		}
	}
}

void searchGreen() {
	int num = 0;
	for (int i = 9; i >= 6; i--) { // green 영역에서 1행에 타일이 채워졌는지 확인
		for (int j = 0; j < 4; j++)
			num += board[i][j];
		if (num == 4) {
			point += 1;
			for (int j = 0; j < 4; j++)
				board[i][j] = 0;
			for (int j = i; j >= 6; j--)
				for (int k = 0; k < 4; k++)
					board[j][k] = board[j - 1][k];
			for (int j = 0; j < 4; j++)
				board[5][j] = 0;
			i = 10;
		}
		num = 0;
	}

	for (int i = 4; i < 6; i++) { // 특별 구역에 타일 있는지 확인
		for (int j = 0; j < 4; j++) {
			if (i == 4 && board[i][j] == 1) {
				for (int k = 8; k < 10; k++)
					for (int l = 0; l < 4; l++)
						board[k][l] = 0;
				for (int k = 9; k >= 6; k--)
					for (int l = 0; l < 4; l++)
						board[k][l] = board[k - 2][l];
				for (int k = 4; k < 6; k++)
					for (int l = 0; l < 4; l++)
						board[k][l] = 0;
			}
			else if (i == 5 && board[i][j] == 1) {
				for (int k = 0; k < 4; k++)
					board[9][k] = 0;
				for (int k = 9; k >= 6; k--)
					for (int l = 0; l < 4; l++)
						board[k][l] = board[k - 1][l];
				for (int l = 0; l < 4; l++)
					board[5][l] = 0;
			}
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		movetoBlue(block_input[i][1], block_input[i][2], block_input[i][0]);
		movetoGreen(block_input[i][1], block_input[i][2], block_input[i][0]);
		searchBlue();
		searchGreen();
	}

	for (int i = 6; i < 10; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] == 1)
				tile_num++;

	for (int i = 0; i < 4; i++)
		for (int j = 6; j < 10; j++)
			if (board[i][j] == 1)
				tile_num++;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> block_input[i][0] >> block_input[i][1] >> block_input[i][2];

	solve();

	cout << point << "\n" << tile_num;
}

