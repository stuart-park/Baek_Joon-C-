#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

int N, L, R, ans = 0;
int A[50][50];
int A_copy[50][50];
bool visited[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int a, int b) {
	int total_sum = 0, cnt = 0;
	queue<pair<int, int>> q;
	queue<pair<int, int>> temp;
	q.push(make_pair(a, b));
	temp.push(make_pair(a, b));
	visited[a][b] = true;

	while(!q.empty()){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		total_sum += A[cur_x][cur_y];
		cnt += 1;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (visited[next_x][next_y])
				continue;
			if (abs(A[next_x][next_y] - A[cur_x][cur_y]) >= L && abs(A[next_x][next_y] - A[cur_x][cur_y]) <= R) {
				q.push(make_pair(next_x, next_y));
				temp.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
			}
		}
	}

	int average = total_sum / cnt;

	while (!temp.empty()) {
		int x = temp.front().first;
		int y = temp.front().second;
		temp.pop();
		A_copy[x][y] = average;
	}
}

bool checkCanMove() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j<N;j++){
			for (int k = 0; k < 4; k++) {
				int next_x = i + dx[k];
				int next_y = j + dy[k];
				if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
					continue;
				if (abs(A[next_x][next_y] - A[i][j]) >= L && abs(A[next_x][next_y] - A[i][j]) <= R)
					return true;
			}
		}
	}
	return false;
}

void solve() {
	while (checkCanMove()) {
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j])
					bfs(i, j);
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				A[i][j] = A_copy[i][j];

		ans++;
	}	
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			A_copy[i][j] = A[i][j];
		}

	solve();

	cout << ans << '\n';
}