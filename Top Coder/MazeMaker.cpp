#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

bool visited[50][50] = { false };

class MazeMaker {
public:
	int longestPath(vector<string> maze, int startRow, int startCol, vector<int> moveRow, vector<int> moveCol) {
		int count[50][50];
		int ans = 0;
		int row = maze.size();
		int col = maze[0].size();

		queue<pair<int, int>>  pos;

		pos.push(make_pair(startCol, startRow));

		for (int i=0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				count[i][j] = -1;

		visited[startRow][startCol] = true;
		count[startRow][startCol] = 0;

		while (pos.empty() == false) {
			int x = pos.front().first;
			int y = pos.front().second;
			pos.pop();
			for (int i = 0; i < moveRow.size(); i++) {
				if (x + moveCol[i] < col && x + moveCol[i] >= 0 && y + moveRow[i] < row && y + moveRow[i] >= 0) {
					if (maze[y + moveRow[i]].at(x + moveCol[i]) == '.' && visited[y + moveRow[i]][x + moveCol[i]] == false && count[y + moveRow[i]][x + moveCol[i]] == -1) {
						visited[y + moveRow[i]][x + moveCol[i]] = true;
						count[y + moveRow[i]][x + moveCol[i]] = count[y][x] + 1;
						pos.push(make_pair(x + moveCol[i], y + moveRow[i]));
					}
				}
			}
		}

		for (int i = 0; i < col; i++)
			for (int j = 0; j < row; j++) {
				if (maze[j].at(i) == '.' && count[i][j] == -1)
					return -1;
				ans = max(ans, count[i][j]);
			}
		return ans;
	}
};


int main() {
	MazeMaker maze;
	vector<string> a = { "........" };
	vector<int> c = { 1,0,1,0,1,0 };
	vector<int> d = { 0,1,0,1,0,1 };
	int b = maze.longestPath(a, 0, 0, c, d);
	cout << b;
}

//int main() {
//	MazeMaker maze;
//	vector<string> a = { "...","...","..." };
//	vector<int> c = { 1,0,-1,0,};
//	vector<int> d = { 0,1,0,-1};
//	int b = maze.longestPath(a, 0, 1, c, d);
//	cout << b;
//}


//int main() {
//	MazeMaker maze;
//	vector<string> a = { "x.x","...","xxx","x.x" };
//	vector<int> c = { 1,0,-1,0};
//	vector<int> d = { 0,1,0,-1};
//	int b = maze.longestPath(a, 0, 1, c, d);
//	cout << b;
//}


//int main() {
//	MazeMaker maze;
//	vector<string> a= { "...","...","..."};
//	vector<int> c = { 1,0,-1,0,1,1,-1,-1};
//	vector<int> d = { 0,1,0,-1,1,-1,1,-1 };
//	int b = maze.longestPath(a, 0, 1, c, d);
//	cout << b;
//}