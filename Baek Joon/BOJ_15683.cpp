#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans = 100;
int board[8][8];
int temp[8][8];
vector<pair<int, int>> cctvPos;
vector<int> cctvDir;

void checkArea() {
	int total_sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0)
				total_sum++;
		}
	}
	if (total_sum < ans)
		ans = total_sum;
}

void camera1(int x, int y,int cctv_dir) {
	int dir[4][2] = { {0, 1},{0, -1},{-1, 0},{1, 0} };
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		
		q.pop();

		int next_x = cur_x + dir[cctv_dir][0];
		int next_y = cur_y + dir[cctv_dir][1];

		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			continue;
		else if (temp[next_x][next_y] == 6)
			continue;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			q.push(make_pair(next_x, next_y));
			continue;
		}
		q.push(make_pair(next_x, next_y));
	}	
}

void camera2(int x, int y, int cctv_dir) {
	int dir[2][2][2] = { {{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}} };
	int cur_x = x, cur_y = y;
	while(1){
		int next_x = cur_x + dir[cctv_dir][0][0];
		int next_y = cur_y + dir[cctv_dir][0][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[cctv_dir][1][0];
		int next_y = cur_y + dir[cctv_dir][1][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	/*queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next_x = cur_x + dir[cctv_dir][i][0];
			int next_y = cur_y + dir[cctv_dir][i][1];

			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				continue;
			else if (temp[next_x][next_y] == 6)
				continue;
			else if (temp[next_x][next_y] == 0) {
				temp[next_x][next_y] = -1;
				q.push(make_pair(next_x, next_y));
				continue;
			}
			q.push(make_pair(next_x, next_y));
		}
	}*/
}

void camera3(int x, int y, int cctv_dir) {
	int dir[4][2][2] = { {{-1, 0},{0, 1}},{{1, 0},{0, 1}},{{1, 0},{0, -1}},{{0, -1},{-1, 0}} };
	int cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[cctv_dir][0][0];
		int next_y = cur_y + dir[cctv_dir][0][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[cctv_dir][1][0];
		int next_y = cur_y + dir[cctv_dir][1][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	/*queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int next_x = cur_x + dir[cctv_dir][i][0];
			int next_y = cur_y + dir[cctv_dir][i][1];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				continue;
			else if (board[next_x][next_y] == 6)
				continue;
			else if (board[next_x][next_y] == 0) {
				board[next_x][next_y] = -1;
				q.push(make_pair(next_x, next_y));
				continue;
			}
			q.push(make_pair(next_x, next_y));
		}
	}*/
}

void camera4(int x, int y, int cctv_dir) {
	int dir[4][3][2] = { {{-1, 0},{0, 1},{1, 0}},{{0, 1},{1,0},{0,-1}},
		{{0,-1},{-1,0},{1,0}},{{0,-1},{-1,0},{0,1}} };
	int cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[cctv_dir][0][0];
		int next_y = cur_y + dir[cctv_dir][0][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[cctv_dir][1][0];
		int next_y = cur_y + dir[cctv_dir][1][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[cctv_dir][2][0];
		int next_y = cur_y + dir[cctv_dir][2][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	/*queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 3; i++) {
			int next_x = cur_x + dir[cctv_dir][i][0];
			int next_y = cur_y + dir[cctv_dir][i][1];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				continue;
			else if (board[next_x][next_y] == 6)
				continue;
			else if (board[next_x][next_y] == 0) {
				board[next_x][next_y] = -1;
				q.push(make_pair(next_x, next_y));
				continue;
			}
			q.push(make_pair(next_x, next_y));
		}
	}*/
}

void camera5(int x, int y, int cctv_dir) {
	int dir[4][2] = { {1, 0},{-1, 0}, {0, 1}, {0, -1} };
	int cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[0][0];
		int next_y = cur_y + dir[0][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[1][0];
		int next_y = cur_y + dir[1][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[2][0];
		int next_y = cur_y + dir[2][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	cur_x = x, cur_y = y;
	while (1) {
		int next_x = cur_x + dir[3][0];
		int next_y = cur_y + dir[3][1];
		if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
			break;
		else if (temp[next_x][next_y] == 6)
			break;
		else if (temp[next_x][next_y] == 0) {
			temp[next_x][next_y] = -1;
			cur_x = next_x, cur_y = next_y;
			continue;
		}
		cur_x = next_x, cur_y = next_y;
	}
	/*queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dir[i][0];
			int next_y = cur_y + dir[i][1];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
				continue;
			else if (board[next_x][next_y] == 6)
				continue;
			else if (board[next_x][next_y] == 0) {
				board[next_x][next_y] = -1;
				q.push(make_pair(next_x, next_y));
				continue;
			}
			q.push(make_pair(next_x, next_y));
		}
	}*/
}

void activateCCTV() {
	for (int i = 0; i < cctvPos.size(); i++) {
		int cctv_type = board[cctvPos[i].first][cctvPos[i].second];
		int cctv_dir = cctvDir[i];

		if (cctv_type == 1)
			camera1(cctvPos[i].first, cctvPos[i].second, cctv_dir);
		else if (cctv_type == 2)
			camera2(cctvPos[i].first, cctvPos[i].second, cctv_dir);
		else if (cctv_type == 3)
			camera3(cctvPos[i].first, cctvPos[i].second, cctv_dir);
		else if (cctv_type == 4)
			camera4(cctvPos[i].first, cctvPos[i].second, cctv_dir);
		else
			camera5(cctvPos[i].first, cctvPos[i].second, cctv_dir);
	}
}

void selectDir(int cctv_num) {
	if (cctv_num == cctvPos.size()) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp[i][j] = board[i][j];
		activateCCTV();
		checkArea();
		return;
	}

	int cctv_type = board[cctvPos[cctv_num].first][cctvPos[cctv_num].second];
	
	if (cctv_type == 1 || cctv_type == 3 || cctv_type == 4) {
		for (int i = 0; i < 4; i++){
			cctvDir.push_back(i);
			selectDir(cctv_num + 1);
			cctvDir.pop_back();
		}
	}
	else if (cctv_type == 2) {
		for (int i = 0; i < 2; i++) {
			cctvDir.push_back(i);
			selectDir(cctv_num + 1);
			cctvDir.pop_back();
		}
	}
	else if (cctv_type == 5) {
		cctvDir.push_back(0);
		selectDir(cctv_num + 1);
		cctvDir.pop_back();
	}
}

void solve() {
	selectDir(0);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)
				cctvPos.push_back(make_pair(i, j));
		}
	}

	solve();

	cout << ans << "\n";
}