#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int N, K, ans = 0;
int board[12][12]; //0:white, 1:Red, 2:Blue
int horseInfo[10][3];
int dir[4][2] = { {0,1}, {0,-1},{-1,0},{1,0} };
deque<int> horse_status[12][12];

bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (horse_status[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}

void solution() {
	while (1) {
		if (ans > 1000) {
			ans = -1;
			break;
		}
		if (check())
			break;
		for (int i = 0; i < K; i++) {
			int next_x = (horseInfo[i][0] - 1) + dir[horseInfo[i][2] - 1][0];
			int next_y = (horseInfo[i][1] - 1) + dir[horseInfo[i][2] - 1][1];

			if (next_x < 0 || next_x >= N || next_y<0 || next_y>=N || board[next_x][next_y] == 2) {
				if (horseInfo[i][2] == 1)
					horseInfo[i][2] = 2;
				else if (horseInfo[i][2] == 2)
					horseInfo[i][2] = 1;
				else if (horseInfo[i][2] == 3)
					horseInfo[i][2] = 4;
				else if (horseInfo[i][2] == 4)
					horseInfo[i][2] = 3;
				next_x = (horseInfo[i][0] - 1) + dir[horseInfo[i][2] - 1][0];
				next_y = (horseInfo[i][1] - 1) + dir[horseInfo[i][2] - 1][1];
			}
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N || board[next_x][next_y] == 2)
				continue;
			else if (board[next_x][next_y] == 0) {
				stack<int> temp;
				int back = -1;
				while (back != i) {
					back = horse_status[horseInfo[i][0] - 1][horseInfo[i][1] - 1].back();
					temp.push(back);
					horse_status[horseInfo[i][0] - 1][horseInfo[i][1] - 1].pop_back();
					horseInfo[back][0] = next_x + 1, horseInfo[back][1] = next_y + 1;
				}
				while (!temp.empty()) {
					int num = temp.top();
					horse_status[next_x][next_y].push_back(num);
					temp.pop();
				}
			}
			else if (board[next_x][next_y] == 1) {
				int back = -1;
				while (back != i) {
					back = horse_status[horseInfo[i][0] - 1][horseInfo[i][1] - 1].back();
					horse_status[horseInfo[i][0] - 1][horseInfo[i][1] - 1].pop_back();
					horse_status[next_x][next_y].push_back(back);
					horseInfo[back][0] = next_x + 1, horseInfo[back][1] = next_y + 1;
				}
			}
			if (check()) {
				ans++;
				return;
			}
		}
		ans++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> horseInfo[i][0] >> horseInfo[i][1] >> horseInfo[i][2];
		horse_status[horseInfo[i][0] - 1][horseInfo[i][1] - 1].push_back(i);
	}

	solution();

	cout << ans << "\n";
}