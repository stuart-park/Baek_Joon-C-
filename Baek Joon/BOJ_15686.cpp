#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, M, ans = 99999999;
int board[50][50];
vector<int> selectedChicken;
vector<pair<int, int>> housePos;
vector<pair<int, int>> chickenPos; 

void selectChicken(int idx, int cnt) {
	if (cnt == M) {
		int total_sum = 0;
		for (int i = 0; i <housePos.size(); i++) {
			int min_dist=9999999;
			for (int j = 0; j < M; j++) {
				int chicken_dist = abs(housePos[i].first - chickenPos[selectedChicken[j]].first) +
					abs(housePos[i].second - chickenPos[selectedChicken[j]].second);
				if (min_dist > chicken_dist)
					min_dist = chicken_dist;
			}
			total_sum += min_dist;
		}
		if (total_sum < ans)
			ans = total_sum;
		return;
	}

	for (int i = idx; i < chickenPos.size(); i++) {
		selectedChicken.push_back(i);
		selectChicken(i + 1, cnt + 1);
		selectedChicken.pop_back();
	}
}

void solve() {
	selectChicken(0, 0);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				housePos.push_back(make_pair(i, j));
			else if (board[i][j] == 2)
				chickenPos.push_back(make_pair(i, j));
		}

	solve();

	cout << ans << "\n";
}