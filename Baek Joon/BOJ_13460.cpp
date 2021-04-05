#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N, M, r_x, r_y, b_x, b_y, out_x, out_y, ans = -1;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool visited[10][10][10][10] = { false, };
vector<string> board;

void solve() {
	queue<pair<int, int>> red;
	queue<pair<int, int>> blue;
	queue<int> move_num;
	red.push(make_pair(r_x, r_y));
	blue.push(make_pair(b_x, b_y));
	move_num.push(0);

	visited[r_x][r_y][b_x][b_y] = true;

	while (!red.empty()) {
		int cur_r_x = red.front().first;
		int cur_r_y = red.front().second;
		int cur_b_x = blue.front().first;
		int cur_b_y = blue.front().second;
		int cur_move = move_num.front();

		red.pop();
		blue.pop();
		move_num.pop();

		if (cur_move > 10)
			break;
		if (cur_r_x == out_x && cur_r_y == out_y) {
			ans = cur_move;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_r_x = cur_r_x, next_r_y = cur_r_y, next_b_x = cur_b_x, next_b_y = cur_b_y;
			while (1) {
				next_r_x += dx[i];
				next_r_y += dy[i];
				if (board[next_r_x][next_r_y] == '#'){
					next_r_x -= dx[i];
					next_r_y -= dy[i];
					break;
				}
				else if (board[next_r_x][next_r_y] == 'O')
					break;

			}
			while (1) {
				next_b_x += dx[i];
				next_b_y += dy[i];
				if (board[next_b_x][next_b_y] == '#') {
					next_b_x -= dx[i];
					next_b_y -= dy[i];
					break;
				}
				else if (board[next_b_x][next_b_y] == 'O')
					break;
			}

			if (next_b_x == out_x && next_b_y == out_y)
				continue;

			if (next_r_x == next_b_x && next_r_y == next_b_y) {
				switch (i) {
				case 0:
					cur_r_x > cur_b_x ? next_b_x-- : next_r_x--;
					break;
				case 1:
					cur_r_x > cur_b_x ? next_r_x++ : next_b_x++;
					break;
				case 2:
					cur_r_y > cur_b_y ? next_b_y-- : next_r_y--;
					break;
				case 3:
					cur_r_y > cur_b_y ? next_r_y++ : next_b_y++;
					break;
				}
			}

			if(!visited[next_r_x][next_r_y][next_b_x][next_b_y]){
				visited[next_r_x][next_r_y][next_b_x][next_b_y] = true;
				red.push(make_pair(next_r_x, next_r_y));
				blue.push(make_pair(next_b_x, next_b_y));
				move_num.push(cur_move + 1);
			}
		}
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		board.push_back(temp);
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == 'B')
				b_x = i, b_y = j;
			else if (temp[j] == 'R')
				r_x = i, r_y = j;
			else if (temp[j] == 'O')
				out_x = i, out_y = j;
		}
	}

	solve();

	cout << ans << "\n";
}