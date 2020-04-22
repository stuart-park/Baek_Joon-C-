#include <iostream>
#include <vector>
#include <queue>

int dx[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int dy[] = { 1, -1, 1, -1, 2, -2, 2, -2 };

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {

		int x1, y1, x2, y2, L;
		queue<pair<pair<int, int>, int>> pos;
		int curX, curY, curMove = 0;

		cin >> L;
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		vector<vector<bool>> visited(L, vector<bool>(L, false));
		pos.push(make_pair(make_pair(x1, y1), 0));
		visited[y1][x1] = true;

		while (1) {
			curX = pos.front().first.first;
			curY = pos.front().first.second;
			curMove = pos.front().second;
			pos.pop();

			if (curX == x2 && curY == y2) {
				cout << curMove << endl;
				break;
			}

			for (int k = 0; k < 8; k++) {
				x1 = curX + dx[k];
				y1 = curY + dy[k];
				if (x1 < L && x1 >= 0 && y1 < L && y1 >= 0 && visited[y1][x1] == false) {
					pos.push(make_pair(make_pair(x1, y1), curMove + 1));
					visited[y1][x1] = true;
				}
			}
		}
	}
}