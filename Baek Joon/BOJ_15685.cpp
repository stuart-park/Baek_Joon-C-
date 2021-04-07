#include <iostream>
#include <deque>
using namespace std;

int N, ans = 0;
int info[20][4];
int board[101][101];

int dir[4][2] = { {0, 1},{-1,0},{0,-1},{1,0} };
int change_dir[4] = { 1,2,3,0 };

void solve() {
	for (int i = 0; i < N; i++) {
		int gen = info[i][3];
		int cur_x = info[i][0], cur_y = info[i][1];
		board[cur_x][cur_y] = 1;

		cur_x += dir[info[i][2]][0];
		cur_y += dir[info[i][2]][1];
		board[cur_x][cur_y] = 1;

		deque <int> back_dir;
		back_dir.push_back(info[i][2]);

		for (int j = 1; j <=gen; j++) {
			deque <int> temp;
			temp = back_dir;
			while (!temp.empty()) {
				int cur_dir = temp.back();
				temp.pop_back();

				int next_x = cur_x + dir[change_dir[cur_dir]][0];
				int next_y = cur_y + dir[change_dir[cur_dir]][1];

				if (next_x < 0 || next_x >100 || next_y < 0 || next_y>100)
					continue;
				board[next_x][next_y] = 1;
				back_dir.push_back(change_dir[cur_dir]);
				cur_x = next_x, cur_y = next_y;
			}
		}
	}

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (board[i][j] == 1 && board[i][j + 1] == 1 &&
				board[i + 1][j] == 1 && board[i + 1][j + 1] == 1)
				ans++;

}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> info[i][1] >> info[i][0] >> info[i][2] >> info[i][3];

	solve();

	cout << ans << "\n";
}