#include <iostream>
using namespace std;

int N, ans = 99999999;
int board[20][20];
int board_div[20][20] = { 0, };

void reset_board() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board_div[i][j] = 0;
}

void divide_board(int x, int y, int d1, int d2){
	for (int i = 0; i <= d1; i++) {
		board_div[x + i][y - i] = 5;
		board_div[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		board_div[x + i][y + i] = 5;
		board_div[x + d1 + i][y - d1 + i] = 5;
	}
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i == x && j == y) || (i == x + d1 + d2 && j == y - d1 + d2))
				continue;
			else if (board_div[i][j] == 5){
				if (!flag)
					flag = true;
				else
					flag = false;
				continue;
			}
			else {
				if (i >= 0 && i < x + d1 && j >= 0 && j <= y) {
					if (flag) board_div[i][j] = 5;
					else board_div[i][j] = 1;
				}
				else if (i >= 0 && i <= x + d2 && j > y && j <= N - 1) {
					if (flag)board_div[i][j] = 5;
					else board_div[i][j] = 2;
				}
				else if (x + d1 <= i && i <= N - 1 && j >= 0 && j < y - d1 + d2) {
					if (flag) board_div[i][j] = 5;
					else board_div[i][j] = 3;
				}
				else {
					if (flag) board_div[i][j] = 5;
					else board_div[i][j] = 4;
				}
			}
		}
	}
}

bool check(int x, int y, int d1, int d2) {
	if (x + d1 + d2 >= N || y - d1 < 0 || y + d2 >= N)
		return false;
	return true;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x = i, y = j; 
			for (int k = 1; k <= y; k++) {
				for (int l = 1; l < N - y; l++) {
					int d1 = k, d2 = l;
					if (!check(x, y, d1, d2))
						continue;

					reset_board();
					divide_board(x, y, d1, d2);
					
					int total_sum[5] = { 0, }, min_total = 9999999, max_total = 0;
					for (int a = 0; a < N; a++)
						for (int b = 0; b < N; b++) 
							total_sum[board_div[a][b] - 1] += board[a][b];
	
					for (int a = 0; a < 5; a++) {
						if (min_total > total_sum[a]) 
							min_total = total_sum[a];
						if (max_total < total_sum[a])
							max_total = total_sum[a];
					}
					int temp = max_total - min_total;
					if (temp < ans)
						ans = temp;
				}
			}
		}
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