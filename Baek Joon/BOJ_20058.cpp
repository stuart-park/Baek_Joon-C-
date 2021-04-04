#include <iostream>
#include <queue>
#include <cmath> //cmath에서 pow함수를 이용하면 시간초과 발생 (pow 함수 시간 복잡도 O(n))
using namespace std;

int N, Q, total_ice = 0, max_ice = 0;
int board[64][64];
int L[1000];

int dir[4][2] = { {1, 0},{-1, 0},{0,1},{0, -1} };

//void dfs(int a, int b, int len, int num) {
//	if (len == num) {
//		int temp[64][64] = { 0, };
//
//		int k = 0;
//		for (int i = a; i < a + len; i++) {
//			for (int j = b; j < b + len; j++)
//				temp[(j % len) + a][b + len - 1 - k] = board[i][j];
//			k++;
//		}
//
//		for (int i = a; i < a + len; i++)
//			for (int j = b; j < b + len; j++)
//				board[i][j] = temp[i][j];
//	}
//	else {
//		dfs(a, b, len / 2, num);
//		dfs(a + len / 2, b, len / 2, num);
//		dfs(a, b + len / 2, len / 2, num);
//		dfs(a + len / 2, b + len / 2, len / 2, num);
//	}
//}

void checkIce() {
	int temp[64][64];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			temp[i][j] = board[i][j];


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0)
				continue;

			int adjacent_ice = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				if (temp[nx][ny] == 0)
					continue;
				adjacent_ice++;
			}
			if (adjacent_ice < 3)
				board[i][j]--;
		}
	}	
}

void rotate_board(int a, int b, int c) {
	int temp[64][64] = { 0, };

	int k = 0;
	for (int i = a; i < a + c; i++) {
		for (int j = b; j < b + c; j++)
			temp[(j % c) + a][b + c - 1 - k] = board[i][j];
		k++;
	}

	for (int i = a; i < a + c; i++)
		for (int j = b; j < b + c; j++)
			board[i][j] = temp[i][j];
}

int countAdjacent(int a, int b) {
	int ice_num = 0;
	queue<pair<int, int>> pos;
	bool visited[64][64] = { false, };
	visited[a][b] = true;
	pos.push(make_pair(a, b));

	while (!pos.empty()) {
		int cur_x = pos.front().first;
		int cur_y = pos.front().second;

		pos.pop();

		ice_num++;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (visited[next_x][next_y] || board[next_x][next_y] == 0)
				continue;
			pos.push(make_pair(next_x, next_y));
			visited[next_x][next_y] = true;
		}
	}

	return ice_num;
}

void solve() {
	for (int i = 0; i < Q; i++) {
		int num = L[i];
		num = (1 << num);
		//dfs(0, 0, N, num);
		for (int j = 0; j < N; j += num)
			for (int k = 0; k < N; k += num)
				rotate_board(j, k, num);

		checkIce();
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			total_ice += board[i][j];
			if (board[i][j] != 0) {
				int ice_num = countAdjacent(i, j);
				if (ice_num == 1)
					continue;
				else if (ice_num > max_ice)
					max_ice = ice_num;
			}
		}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;

	N = (1 << N);
	 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];


	for (int i = 0; i < Q; i++)
		cin >> L[i];

	solve();

	cout << total_ice << "\n" << max_ice;
}