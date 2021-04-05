#include <iostream>
#include <vector>
using namespace std;

struct fireball {
	int r;
	int c;
	int m;
	int s;
	int d;
};

int N, M, K, ans = 0;
vector<fireball> info;
vector<fireball> board[50][50];

int dir[8][2] = { {-1, 0},{-1, 1},{0, 1},{1, 1},{1,0},{1, -1},{0, -1},{-1, -1} };
int n_dir1[4] = { 0,2,4,6 };
int n_dir2[4] = { 1,3,5,7 };

void solve() {
	for (int i = 0; i < K; i++) {

		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (!board[j][k].empty())
					board[j][k].clear();
		
		// 파이어볼 이동
		for (int j = 0; j < info.size(); j++) {
			int cur_x = info[j].r;
			int cur_y = info[j].c;
			int speed = (info[j].s % N);
			
			int next_x = cur_x + (dir[info[j].d][0] * speed);
			int next_y = cur_y + (dir[info[j].d][1] * speed);
			if (next_x >= N)
				next_x = next_x - N;
			if (next_y >= N)
				next_y = next_y - N;
			if (next_x < 0)
				next_x = next_x + N;
			if (next_y < 0)
				next_y = next_y + N;

			info[j].r = next_x, info[j].c = next_y;
			board[next_x][next_y].push_back({ next_x, next_y, info[j].m, info[j].s, info[j].d });
			
		}

		//파이어볼 합침
		vector<fireball> temp;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (board[j][k].size() == 0)
					continue;
				if (board[j][k].size() == 1) {
					temp.push_back(board[j][k][0]);
					continue;
				}
				if (board[j][k].size() > 1) {
					int even = 0, odd = 0, total_m = 0, total_s = 0, n = board[j][k].size();
					for (int l = 0; l < board[j][k].size(); l++) {
						total_m += board[j][k][l].m;
						total_s += board[j][k][l].s;
						if (board[j][k][l].d % 2 == 0)
							even++;
						else
							odd++;
					}
					board[j][k].clear();
					int new_m = total_m / 5, new_s = total_s / n;
					if (new_m == 0)
						continue;
					for (int l = 0; l < 4; l++) {
						if (odd == n || even == n) {
							board[j][k].push_back({ j, k, new_m, new_s, n_dir1[l]});
							temp.push_back({ j, k, new_m, new_s, n_dir1[l] });
						}
						else {
							board[j][k].push_back({ j, k, new_m, new_s, n_dir2[l] });
							temp.push_back({ j, k, new_m, new_s, n_dir2[l] });
						}
					}
				}
			}
		}
		info = temp;
	}
	for (int i = 0; i < info.size(); i++)
		ans += info[i].m;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;
		info.push_back({ x - 1, y - 1, m, s, d });
		board[x - 1][y - 1].push_back({ x - 1,y - 1, m, s, d });
	}

	solve();

	cout << ans << "\n";
}