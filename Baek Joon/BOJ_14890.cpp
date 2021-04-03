#include <iostream>
using namespace std;

int board[100][100], ans = 0;
int N, L;

int abs(int a, int b) {
	return a > b ? a - b : b - a;
}

void solve() {
	//check row
	for (int i = 0; i < N; i++) {
		int prev = board[i][0];
		int length = 1;
		int road = 1;
		bool flag = false;
		for (int j = 1; j < N; j++) {
			if (flag) {
				if (board[i][j] > prev) {
					length = -1;
					break;
				}
				else if (length == L) {
					road++;
					length = 1;
					if (board[i][j] == prev)
						flag = false;
					prev = board[i][j];
				}
				else if (length < L && prev == board[i][j]) {
					road++;
					length++;
					prev = board[i][j];
				}
				else
					break;
			}
			else {
				if (board[i][j] == prev) {
					road++;
					length++;
					prev = board[i][j];
				}
				else if (abs(board[i][j] - prev) == 1) {
					if (prev > board[i][j]) {
						flag = true;
						road++;
						length = 1;
						prev = board[i][j];
					}
					else {
						if (length >= L) {
							road++;
							length = 1;
							prev = board[i][j];
						}
						else 
							break;
					}
				}
				else
					break;
			}
		}
		if (road == N && (flag == false || (flag == true && length == L)))
			ans++;
	}
	//check col
	for (int i = 0; i < N; i++) {
		int prev = board[0][i];
		int length = 1;
		int road = 1;
		int flag = false;
		for (int j = 1; j < N; j++) {
			if (flag) {
				if (board[j][i] > prev) {
					length = -1;
					break;
				}
				else if (length == L) {
					road++;
					length = 1;
					if (board[j][i] == prev)
						flag = false;
					prev = board[j][i];
				}
				else if (length < L && prev == board[j][i]) {
					road++;
					length++;
					prev = board[j][i];
				}
				else
					break;
			}
			else {
				if (board[j][i] == prev) {
					road++;
					length++;
					prev = board[j][i];
				}
				else if (abs(board[j][i] - prev) == 1) {
					if (prev > board[j][i]) {
						flag = true;
						road++;
						length = 1;
						prev = board[j][i];
					}
					else {
						if (length >= L) {
							road++;
							length = 1;
							prev = board[j][i];
						}
						else
							break;
					}
				}
				else
					break;
			}
		}
		if (road == N && (flag == false || (flag == true && length == L)))
			ans++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	solve();

	cout << ans << "\n";
}