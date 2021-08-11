#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int board[100][100];
int n, apple_num, move_num, time;

int dir[4][2] = { {1, 0}, {-1, 0},{0, -1},{0, 1} };

queue<pair<int, char>> movement;

void BFS() {
	deque<pair<int, int>> snake_pos;
	snake_pos.push_back(make_pair(0, 0));

	int direction = 0; // 0: Right, 1: Left, 2: Up, 3: Down

	while (!movement.empty()) {
		int sec = movement.front().first;
		char change_direction = movement.front().second;

		movement.pop();

		for (int i = 0; i < sec; i++) {
			int row_front = snake_pos.front().first;
			int col_front = snake_pos.front().second;
			int row_back = snake_pos.back().first;
			int col_back = snake_pos.back().second;

			if (row_front + dir[direction][1] < n && row_front + dir[direction][1] >= 0 && 
				col_front + dir[direction][0] < n && col_front + dir[direction][0] >= 0 && 
				board[row_front + dir[direction][1]][col_front + dir[direction][0]] != 1) {
				snake_pos.push_front(make_pair(row_front + dir[direction][1], col_front + dir[direction][0]));
				if (board[row_front + dir[direction][1]][col_front + dir[direction][0]] == 2) {
					board[row_front + dir[direction][1]][col_front + dir[direction][0]] = 1;
					time++;
					continue;
				}
				else {
					board[row_front + dir[direction][1]][col_front + dir[direction][0]] = 1;
					snake_pos.pop_back();
					board[row_back][col_back] = 0;
				}

			}
			else
				return;

			time++;
		}

		if (change_direction == 'D') {
			if (direction == 0)
				direction = 3;
			else if (direction == 1)
				direction = 2;
			else if (direction == 2)
				direction = 0;
			else if (direction == 3)
				direction = 1;
		}
		else if (change_direction == 'L') {
			if (direction == 0)
				direction = 2;
			else if (direction == 1)
				direction = 3;
			else if (direction == 2)
				direction = 1;
			else if (direction == 3)
				direction = 0;
		}
	}

	while (1) {
		int row_front = snake_pos.front().first;
		int col_front = snake_pos.front().second;
		int row_back = snake_pos.back().first;
		int col_back = snake_pos.back().second;

		if (row_front + dir[direction][1] < n && row_front + dir[direction][1] >= 0 &&
			col_front + dir[direction][0] < n && col_front + dir[direction][0] >= 0 &&
			board[row_front + dir[direction][1]][col_front + dir[direction][0]] != 1) {
			snake_pos.push_front(make_pair(row_front + dir[direction][1], col_front + dir[direction][0]));
			board[row_front + dir[direction][1]][col_front + dir[direction][0]] = 1;
			if (board[row_front + dir[direction][1]][col_front + dir[direction][0]] == 2)
				continue;
			else {
				snake_pos.pop_back();
				board[row_back][col_back] = 0;
			}

		}
		else
			return;

		time++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	board[0][0] = 1; // 1: Snake

	cin >> n >> apple_num;

	for (int i = 0; i < apple_num; i++) {
		int row, col;
		cin >> row >> col;
		board[row-1][col-1] = 2; // 2: Apple
	}

	cin >> move_num;
	
	int first_sec;
	char direction;
	cin >> first_sec >> direction;
	movement.push(make_pair(first_sec, direction));

	for (int i = 1; i < move_num; i++) {
		int sec;
		cin >> sec >> direction;
		int temp = sec - first_sec;
		first_sec = sec;
		movement.push(make_pair(temp, direction));
	}

	BFS();

	cout << time+1 << "\n";
	
}