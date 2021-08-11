#include <iostream>
using namespace std;

int N, ans = 0;
int board[20][20];
int arr[20][20];
int select_dir[5] = { 0, };

int dx[] = { 1, -1, 0 ,0 };
int dy[] = { 0, 0, 1, -1 };

void moveLeft() {
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (arr[i][j] != 0) {
				int temp = arr[i][j], k;
				arr[i][j] = 0;
				for (k = j - 1; k >= 0; k--) {
					if (arr[i][k] == 0)
						continue;
					else {
						arr[i][k + 1] = temp;
						break;
					}
				}
				if (k == -1)
					arr[i][0] = temp;
			}
		}
		for (int j = 0; j < N - 1; j++) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j + 1]) {
				arr[i][j] *= 2;
				arr[i][j + 1] = 0;
			}
		}
		for (int j = 1; j < N; j++) {
			if (arr[i][j] != 0) {
				int temp = arr[i][j], k;
				arr[i][j] = 0;
				for (k = j - 1; k >= 0; k--) {
					if (arr[i][k] == 0)
						continue;
					else {
						arr[i][k + 1] = temp;
						break;
					}
				}
				if (k == -1)
					arr[i][0] = temp;
			}
		}
	}
}

void moveRight() {
	for (int i = 0; i < N; i++) {
		for (int j = N-2; j >= 0; j--) {
			if (arr[i][j] != 0) {
				int temp = arr[i][j], k;
				arr[i][j] = 0;
				for (k = j + 1; k < N; k++) {
					if (arr[i][k] == 0)
						continue;
					else {
						arr[i][k - 1] = temp;
						break;
					}
				}
				if (k == N)
					arr[i][N - 1] = temp;
			}
		}
		for (int j = N-1; j > 0; j--) {
			if (arr[i][j] != 0 && arr[i][j] == arr[i][j - 1]) {
				arr[i][j] *= 2;
				arr[i][j - 1] = 0;
			}
		}
		for (int j = N - 2; j >= 0; j--) {
			if (arr[i][j] != 0) {
				int temp = arr[i][j], k;
				arr[i][j] = 0;
				for (k = j + 1; k < N; k++) {
					if (arr[i][k] == 0)
						continue;
					else {
						arr[i][k - 1] = temp;
						break;
					}
				}
				if (k == N)
					arr[i][N - 1] = temp;
			}
		}
	}
}

void moveUp() {
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (arr[j][i] != 0) {
				int temp = arr[j][i], k;
				arr[j][i] = 0;
				for (k = j - 1; k >= 0; k--) {
					if (arr[k][i] == 0)
						continue;
					else {
						arr[k + 1][i] = temp;
						break;
					}
				}
				if (k == -1)
					arr[0][i] = temp;
			}
		}
		for (int j = 0; j < N - 1; j++) {
			if (arr[j][i] != 0 && arr[j][i] == arr[j + 1][i]) {
				arr[j][i] *= 2;
				arr[j + 1][i] = 0;
			}
		}
		for (int j = 1; j < N; j++) {
			if (arr[j][i] != 0) {
				int temp = arr[j][i], k;
				arr[j][i] = 0;
				for (k = j - 1; k >= 0; k--) {
					if (arr[k][i] == 0)
						continue;
					else {
						arr[k + 1][i] = temp;
						break;
					}
				}
				if (k == -1)
					arr[0][i] = temp;
			}
		}
	}
}

void moveDown() {
	for (int i = 0; i < N; i++) {
		for (int j = N - 2; j >= 0; j--) {
			if (arr[j][i] != 0) {
				int temp = arr[j][i], k;
				arr[j][i] = 0;
				for (k = j + 1; k < N; k++) {
					if (arr[k][i] == 0)
						continue;
					else {
						arr[k - 1][i] = temp;
						break;
					}
				}
				if (k == N)
					arr[N - 1][i] = temp;
			}
		}
		for (int j = N - 1; j > 0; j--) {
			if (arr[j][i] != 0 && arr[j][i] == arr[j - 1][i]) {
				arr[j][i] *= 2;
				arr[j - 1][i] = 0;
			}
		}
		for (int j = N - 2; j >= 0; j--) {
			if (arr[j][i] != 0) {
				int temp = arr[j][i], k;
				arr[j][i] = 0;
				for (k = j + 1; k < N; k++) {
					if (arr[k][i] == 0)
						continue;
					else {
						arr[k - 1][i] = temp;
						break;
					}
				}
				if (k == N)
					arr[N - 1][i] = temp;
			}
		}
	}
}

void copy_arr() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = board[i][j];
}

void solve(int cnt) {
	if (cnt == 5) {
		copy_arr();
		for (int i = 0; i < 5; i++) {
			int dir = select_dir[i];
			if (dir == 0)
				moveLeft();
			else if (dir == 1)
				moveRight();
			else if (dir == 2)
				moveDown();
			else if (dir == 3)
				moveUp();
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] > ans)
					ans = arr[i][j];
			}
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		select_dir[cnt] = i;
		solve(cnt + 1);
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

	solve(0);

	cout << ans << "\n";
}