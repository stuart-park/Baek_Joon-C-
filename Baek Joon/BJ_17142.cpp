#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M, empty_place = 0, max_time=999999999,ans = 0;
int Lab[50][50];
int spreadTime[50][50];
vector<pair<int, int>> Virus;
vector<bool> isSelected;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(queue<pair<int, int>> pos) {
	int spread_place = 0;
	int total_time = 0;

	while (!pos.empty()) {
		int cur_x = pos.front().first;
		int cur_y = pos.front().second;

		pos.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (Lab[next_x][next_y] == 1 || spreadTime[next_x][next_y]!=-1)
				continue;

			spreadTime[next_x][next_y] = spreadTime[cur_x][cur_y] + 1;
			if (Lab[next_x][next_y] == 0) {
				total_time = spreadTime[next_x][next_y];
				spread_place++;
			}
			pos.push(make_pair(next_x, next_y));
		}
	}
	if (spread_place == empty_place)
		if (total_time < max_time)
			max_time = total_time;
}

void SelectStart(int idx, int cnt) {
	if (cnt == M) {
		queue<pair<int, int>> pos;
		memset(spreadTime, -1, sizeof(spreadTime));
		for (int i = 0; i < Virus.size(); i++) {
			if (isSelected[i]) {
				pos.push(make_pair(Virus[i].first, Virus[i].second));
				spreadTime[Virus[i].first][Virus[i].second] = 0;
			}
		}
		BFS(pos);
		return;
	}

	for (int i = idx; i < Virus.size(); i++) {
		if (isSelected[i])
			continue;
		isSelected[i] = true;
		SelectStart(i + 1, cnt + 1);
		isSelected[i] = false;
	}
}

void solution() {
	SelectStart(0, 0);
	if (max_time == 999999999)
		ans = -1;
	else
		ans = max_time;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> Lab[i][j];
			if (Lab[i][j] == 2) {
				Virus.push_back(make_pair(i, j));
				isSelected.push_back(false);
			}
			if (Lab[i][j] == 0)
				empty_place++;
		}
	
	solution();

	cout << ans << "\n";
}