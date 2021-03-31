#include <iostream>
#include <vector>
using namespace std;

int N, M, K, ans = 0;
int board[20][20]; // 상어 번호 
int smell[20][20]; // 상어 냄새
int shark_direction[400]; // 상어 방향
int dir_priority[400][4][4]; // 이동 우선순위
int shark_pos[400][2]; //상어 위치
bool isDead[400];

int dir[4][2] = { {-1, 0},{1, 0},{0, -1},{0, 1} };

bool checkShark() {
	for (int i = 1; i < M; i++)
		if (!isDead[i])
			return false;
	return true;
}

void decrease_smell(int shark_num) {
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if (board[i][j] - 1 == shark_num) {
				smell[i][j]--;
				if (smell[i][j] == 0)
					board[i][j] = 0;
			}	
}

void solve() {
	int temp_smell[20][20];

	while (1) {
		if (ans > 1000) {
			ans = -1;
			break;
		}

		if (checkShark())
			break;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				temp_smell[i][j] = smell[i][j];

		for (int i = 0; i < M; i++) {
			if (!isDead[i]) {
				bool flag = false;
				for (int j = 0; j < 4; j++) { // 아무 냄새 없는 칸 탐색
					int next_x = shark_pos[i][0] + dir[dir_priority[i][shark_direction[i] - 1][j] - 1][0];
					int next_y = shark_pos[i][1] + dir[dir_priority[i][shark_direction[i] - 1][j] - 1][1];
					if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
						continue;
					if (smell[next_x][next_y] == K && temp_smell[next_x][next_y] == 0) {
						isDead[i] = true;
						break;
					}
					if (temp_smell[next_x][next_y] == 0) {
						shark_direction[i] = dir_priority[i][shark_direction[i] - 1][j];
						flag = true;
						break;
					}
				}

				if (!flag) {
					for (int j = 0; j < 4; j++) { // 냄새 없는 칸 없을 떄 갈 수 있는 방향 탐색
						int next_x = shark_pos[i][0] + dir[dir_priority[i][shark_direction[i] - 1][j] - 1][0];
						int next_y = shark_pos[i][1] + dir[dir_priority[i][shark_direction[i] - 1][j] - 1][1];
						if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
							continue;
						if (temp_smell[next_x][next_y] != 0 && board[next_x][next_y] - 1 != i)
							continue;
						shark_direction[i] = dir_priority[i][shark_direction[i] - 1][j];
						break;
					}
				}

				if (!isDead[i]) {
					shark_pos[i][0] += dir[shark_direction[i] - 1][0];
					shark_pos[i][1] += dir[shark_direction[i] - 1][1];

					decrease_smell(i);

					board[shark_pos[i][0]][shark_pos[i][1]] = i + 1;
					smell[shark_pos[i][0]][shark_pos[i][1]] = K;
				}

				else
					decrease_smell(i);
			}
			else
				decrease_smell(i);
		}
		ans++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0)
				shark_pos[board[i][j] - 1][0] = i, shark_pos[board[i][j] - 1][1] = j, smell[i][j] = K;
		}

	for (int i = 0; i < M; i++)
		cin >> shark_direction[i];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 4; k++)
				cin >> dir_priority[i][j][k];
	
	solve();

	cout << ans << "\n";
}