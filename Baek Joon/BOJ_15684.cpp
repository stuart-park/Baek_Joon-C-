#include <iostream>
using namespace std;

int N, M, H, ans = -1; //N: Col, H: Row
int row_info[270][2];
int ladder[30][9];

bool try_ladder() {
	for (int i = 0; i < N; i++) {
		int cur_col = i;
		for (int j = 0; j < H; j++) {
			if (ladder[j][cur_col - 1] == 1 && cur_col > 0)
				cur_col -= 1;
			else if (ladder[j][cur_col] == 1 && cur_col != N - 1)
				cur_col += 1;
		}
		if (cur_col != i)
			return false;
	}
	return true;
}

void solve(int a, int b, int add_ladder) {
	if (add_ladder > 3) 
		return;

	if (add_ladder == 3 && !try_ladder())
		return;

	if (try_ladder()) {
		if (ans == -1)
			ans = add_ladder;
		else if (ans > add_ladder)
			ans = add_ladder;
		return;
	}

	for (int i = a; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (ladder[i][j] == 1)
				continue;
			else if ((ladder[i][j - 1] == 0 && j > 0 && ladder[i][j + 1] == 0) || (j == 0  && ladder[i][j + 1] == 0)) {
				ladder[i][j] = 1,  add_ladder += 1;
				solve(i, j, add_ladder);
				ladder[i][j] = 0,  add_ladder -= 1;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;


	for (int i = 0; i < M; i++) {
		cin >> row_info[i][0] >> row_info[i][1];
		ladder[row_info[i][0] - 1][row_info[i][1] - 1] = 1;
	}

	solve(0, 0, 0);

	cout << ans << "\n";

}