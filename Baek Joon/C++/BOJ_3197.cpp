#include <iostream>
#include <queue>
using namespace std;

int R, C, s1_x = -1, s1_y = -1, s2_x = -1, s2_y = -1;
char map[1500][1500];
bool visited[1500][1500];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
queue<pair<int, int>> ice_pos;
queue<pair<int, int>> swan_pos;



void iceMelt() {
	int N = ice_pos.size();

	for (int i = 0; i < N; i++) {
		int cur_r = ice_pos.front().first;
		int cur_c = ice_pos.front().second;
		ice_pos.pop();

		for (int j = 0; j < 4; j++) {
			int next_r = cur_r + dx[j];
			int next_c = cur_c + dy[j];
			if (next_r < 0 || next_c < 0 || next_r >= R || next_c >= C)
				continue;
			else if (map[next_r][next_c] == 'X') {
				map[next_r][next_c] = '.';
				ice_pos.push(make_pair(next_r, next_c));
			}
		}
	}
}

bool moveSwan() {
	queue<pair<int, int>> temp;

	while(!swan_pos.empty()){
		int cur_r = swan_pos.front().first;
		int cur_c = swan_pos.front().second;
		swan_pos.pop();

		bool flag = false;
		for (int j = 0; j < 4; j++) {
			int next_r = cur_r + dx[j];
			int next_c = cur_c + dy[j];
			if (next_r < 0 || next_c < 0 || next_r >= R || next_c >= C || visited[next_r][next_c])
				continue;
			else if (map[next_r][next_c] == '.') {
				visited[next_r][next_c] = true;
				swan_pos.push(make_pair(next_r, next_c));
			}
			else if (map[next_r][next_c] == 'X' && !flag) {
				temp.push(make_pair(cur_r, cur_c));
				flag = true;
			}
			else if (map[next_r][next_c] == 'L')
				return true;
		}
	}

	swan_pos = temp;

	return false;
}

int main() {
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '.') {
				ice_pos.push(make_pair(i, j));
			}
			if (map[i][j] == 'L') {
				ice_pos.push(make_pair(i, j));
				if (s1_x == -1 && s1_y == -1)
					s1_x = i, s1_y = j;
				else
					s2_x = i, s2_y = j;
			}
		}
	}

	swan_pos.push(make_pair(s1_x, s1_y));
	visited[s1_x][s1_y] = true;

	int ans = 0;
	while (true) {
		if (moveSwan())
			break;
		iceMelt();
		ans++;
	}

	cout << ans << "\n";
}