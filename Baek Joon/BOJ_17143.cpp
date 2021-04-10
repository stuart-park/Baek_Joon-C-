#include <iostream>
#include <vector>
using namespace std;

int R, C, M, ans = 0;

struct shark {
	int r;
	int c;
	int s;
	int d;
	int z;
};
vector<shark> board[100][100];
vector<shark> temp[100][100];

void solve() {
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (!board[j][i].empty()) {
				ans += board[j][i].front().z;
				board[j][i].clear();
				break;
			}
		}

		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (board[j][k].empty())
					continue;
				int s = board[j][k].front().s;
				int d = board[j][k].front().d;
				int z = board[j][k].front().z;
				board[j][k].clear();

				if (d == 0) {
					int a = (R - 1 - j + s) / (R - 1);
					int b = (R - 1 - j + s) % (R - 1);
					int cur_r;
					if (a % 2 == 1)
						cur_r = b, d = 1;
					else if (a % 2 == 0)
						cur_r = R - 1 - b;
					temp[cur_r][k].push_back({ cur_r, k, s, d, z });
				}
				else if (d == 1) {
					int a = (j + s) / (R - 1);
					int b = (j + s) % (R - 1);
					int cur_r;
					if (a % 2 == 1)
						cur_r = R - 1 - b, d = 0;
					else if (a % 2 == 0)
						cur_r = b;
					temp[cur_r][k].push_back({ cur_r, k, s, d, z });
				}
				else if (d == 2) {
					int a = (k + s) / (C - 1);
					int b = (k + s) % (C - 1);
					int cur_c;
					if (a % 2 == 1)
						cur_c = C - 1 - b, d = 3;
					else if (a % 2 == 0)
						cur_c = b;
					temp[j][cur_c].push_back({ j, cur_c, s, d, z });
				}
				else if (d == 3) {
					int a = (C - 1 - k + s) / (C - 1);
					int b = (C - 1 - k + s) % (C - 1);
					int cur_c;
					if (a % 2 == 1)
						cur_c = b, d = 2;
					else if (a % 2 == 0)
						cur_c = C - 1 - b;
					temp[j][cur_c].push_back({ j, cur_c, s, d,z });
				}
			}
		}

		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				if (temp[j][k].size() == 1) {
					board[j][k].push_back(temp[j][k].front());
					temp[j][k].clear();
				}
				else if (temp[j][k].size() > 1) {
					int max_size = 0, max_shark = -1;
					for (int l = 0; l < temp[j][k].size(); l++) {
						if (max_size < temp[j][k][l].z)
							max_size = temp[j][k][l].z, max_shark = l;
					}
					board[j][k].push_back(temp[j][k][max_shark]);
					temp[j][k].clear();
				}
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		board[r - 1][c - 1].push_back({ r - 1, c - 1, s, d - 1, z });
	}

	solve();

	cout << ans << "\n";
}