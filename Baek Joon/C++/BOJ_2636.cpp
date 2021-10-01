#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C, cheese_num = 0;
int board[100][100];
bool visited[100][100];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void bfs() {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;

	while (!q.empty()) {
		int cur_r = q.front().first;
		int cur_c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_r = cur_r + dx[i];
			int next_c = cur_c + dy[i];
			if (next_r < 0 || next_c < 0 || next_r >= R || next_c >= C || visited[next_r][next_c])
				continue;
			if (board[next_r][next_c] == 0) {
				visited[next_r][next_c] = true;
				q.push(make_pair(next_r, next_c));
			}
			else if (board[next_r][next_c] == 1) {
				board[next_r][next_c] = 0;
				visited[next_r][next_c] = true;
				cheese_num--;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				cheese_num++;
		}

	int ans = 0, last_cheese_num = 0;
	while (cheese_num != 0) {
		last_cheese_num = cheese_num;
		bfs();
		ans++;
	}

	cout << ans << "\n" <<last_cheese_num <<"\n";
}