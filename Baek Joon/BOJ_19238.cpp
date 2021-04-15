#include <iostream>
#include <queue>
using namespace std;

int N, M, fuel, row, col, ans = -1;
int min_passenger, min_dist;
int board[20][20];
int passenger_info[400][4];
bool isFinish[400];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void BFS(int a, int b, int left_passenger) {
	bool visited[20][20] = { false, };
	queue<pair<pair<int, int>, int>> pos;
	pos.push(make_pair(make_pair(a, b), 0));
	visited[a][b] = true;
	int min_x = -1, min_y = -1, find_passenger = 0;

	while (!pos.empty()) {
		int cur_x = pos.front().first.first;
		int cur_y = pos.front().first.second;
		int cur_move = pos.front().second;

		pos.pop();

		for (int i = 0; i < M; i++) {
			if (!isFinish[i] && cur_x == passenger_info[i][0] && cur_y == passenger_info[i][1]) {
				if (cur_move < min_dist)
					min_dist = cur_move, min_x = cur_x, min_y = cur_y, min_passenger = i;
				else if (cur_move == min_dist) {
					if (cur_x == min_x) {
						if (cur_y < min_y)
							min_y = cur_y, min_passenger = i;
					}
					else if (cur_x < min_x)
						min_x = cur_x, min_y = cur_y, min_passenger = i;
				}
				find_passenger++;
			}
		}

		if (left_passenger == find_passenger)
			break;

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (board[next_x][next_y] == 1  || visited[next_x][next_y])
				continue;
			pos.push(make_pair(make_pair(next_x, next_y), cur_move + 1));
			visited[next_x][next_y] = true;
		}
	}
}

int toDestination(int min_passenger) {
	bool visited[20][20] = { false, };
	queue<pair<pair<int, int>, int>> pos;
	pos.push(make_pair(make_pair(row, col), 0));
	visited[row][col] = true;
	int destination_move = -1;

	while (!pos.empty()) {
		int cur_x = pos.front().first.first;
		int cur_y = pos.front().first.second;
		int cur_move = pos.front().second;
		
		pos.pop();

		if (cur_x == passenger_info[min_passenger][2] && cur_y == passenger_info[min_passenger][3]) {
			destination_move = cur_move;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
				continue;
			if (board[next_x][next_y] == 1 || visited[next_x][next_y])
				continue;
			pos.push(make_pair(make_pair(next_x, next_y), cur_move + 1));
			visited[next_x][next_y] = true;
		}
	}

	return destination_move;
}

bool checkPassenger() {
	for (int i = 0; i < M; i++)
		if (!isFinish[i])
			return false;
	return true;
}

void solve() {
	int left_passenger = M;

	for (int i = 0; i < M; i++) {
		//½Â°´ ÅÂ¿ò

		min_passenger = -1, min_dist = 500;
		BFS(row, col, left_passenger);

		if (min_passenger == -1) {
			ans = -1;
			break;
		}

		row = passenger_info[min_passenger][0], col = passenger_info[min_passenger][1];
		fuel -= min_dist;
		if (fuel <= 0) {
			ans = -1;
			break;
		}
		//½Â°´ µµÂø
		int dest_move = toDestination(min_passenger);
		if (dest_move == -1) {
			ans = -1;
			break;
		}
		isFinish[min_passenger] = true;
		left_passenger--;
		row = passenger_info[min_passenger][2], col = passenger_info[min_passenger][3];
		fuel -= dest_move;
		if (fuel < 0) {
			ans = -1;
			break;
		}
		fuel = fuel + (dest_move * 2);

		ans = fuel;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> fuel;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j]; 

	int x, y;
	cin >> x >> y;
	row = x - 1, col = y - 1;

	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		passenger_info[i][0] = a - 1, passenger_info[i][1] = b - 1, passenger_info[i][2] = c - 1, passenger_info[i][3] = d - 1;
	}
	
	solve();

	cout << ans << "\n";
}