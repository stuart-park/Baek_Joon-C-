#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, bs_x, bs_y, cur_size = 2, cur_eat_fish = 0, min_dist, min_x, min_y, max_x = 50, max_y = 50, max_dist = 500;
int space[20][20];
int dist[20][20] = { 0, };
bool visited[20][20] = { false, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };


void BFS() {
	queue<pair<int, int>> pos;
	pos.push(make_pair(bs_x, bs_y));
	visited[bs_x][bs_y] = true;

	while (!pos.empty()) {
		int cur_x = pos.front().first;
		int cur_y = pos.front().second;

		pos.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			else if (space[next_x][next_y] > cur_size || visited[next_x][next_y] == true)
				continue;
			else if (space[next_x][next_y] < cur_size && space[next_x][next_y] != 0) {
				dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
				visited[next_x][next_y] = true;
				if (dist[next_x][next_y] < min_dist) {
					min_dist = dist[next_x][next_y];
					min_x = next_x;
					min_y = next_y;
				}
				else if (dist[next_x][next_y] == min_dist) {
					if (min_x == next_x) {
						if (min_y > next_y) {
							min_x = next_x;
							min_y = next_y;
						}
					}
					else if (min_x > next_x) {
						min_x = next_x;
						min_y = next_y;
					}
				}
				pos.push(make_pair(next_x, next_y));
			}
			else {
				dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
				pos.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
			}
		}
	}
}

int solution() {
	int ans = 0;

	while (1) {
		memset(dist, 0, sizeof(dist));
		memset(visited, false, sizeof(visited));
		min_dist = max_dist;
		min_x = max_x;
		min_y = max_y;
		BFS();
		if (max_x != min_x && min_y != max_y) {
			space[min_x][min_y] = 0;
			cur_eat_fish += 1;
			if (cur_eat_fish == cur_size) {
				cur_size += 1;
				cur_eat_fish = 0;
			}
			ans += dist[min_x][min_y];
			bs_x = min_x, bs_y = min_y;

		}
		else
			break;
	}

	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> space[i][j];
			if (space[i][j] == 9) {
				bs_x = i;
				bs_y = j;
				space[i][j] = 0;
			}
		}
	}

	int ans = solution();

	cout << ans << "\n";
}