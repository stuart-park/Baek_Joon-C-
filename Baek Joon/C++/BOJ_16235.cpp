#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, ans = 0;
int board[10][10];
int A[10][10];
//int treeInfo[100][3];

vector<int> treeState[10][10];
//vector<int> deadTree[10][10];

int dir[8][2] = { {-1, -1},{-1, 0},{-1, 1},{0, -1},{0, 1},{1, -1},{1, 0},{1,1} };

void solve() {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) { //Spring
			for (int k = 0; k < N; k++) {
				int deadTree = 0;
				if (!treeState[j][k].empty()) {
					vector<int> temp;
					temp = treeState[j][k];
					treeState[j][k].clear();
					for (int l = 0; l < temp.size(); l++) {
						int age = temp[l];
						if (board[j][k] >= age) {
							board[j][k] -= age;
							age += 1;
							treeState[j][k].push_back(age);
						}
						else if (board[j][k] < age)
							deadTree += (age / 2);
							//deadTree[j][k].push_back(age);
					}
				}
				board[j][k] += deadTree;
			}
		}
		//for (int j = 0; j < N; j++) { //Summer
		//	for (int k = 0; k < N; k++) {
		//		if (!deadTree[j][k].empty()) {
		//			for (int l = 0; l < deadTree[j][k].size(); l++)
		//				board[j][k] += (deadTree[j][k][l] / 2);
		//		}
		//		deadTree[j][k].clear();
		//	}
		//}
		for (int j = 0; j < N; j++) { //Fall
			for (int k = 0; k < N; k++) {
				if (!treeState[j][k].empty()) {
					for (int l = 0; l < treeState[j][k].size(); l++) {
						if (treeState[j][k][l] % 5 == 0) {
							for (int p = 0; p < 8; p++) {
								int next_x = j + dir[p][0];
								int next_y = k + dir[p][1];
								if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N)
									continue;
								treeState[next_x][next_y].push_back(1);
							}
						}
					}
				}
			}
		}
		for (int j = 0; j < N; j++)  //Winter
			for (int k = 0; k < N; k++) {
				board[j][k] += A[j][k];
				if (!treeState[j][k].empty())
					sort(treeState[j][k].begin(), treeState[j][k].end());
			}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans += treeState[i][j].size();
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			board[i][j] = 5;

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		treeState[x - 1][y - 1].push_back(z);
	}

	solve();

	cout << ans << "\n";
}