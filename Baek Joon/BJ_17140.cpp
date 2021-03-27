#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k, ans = 0;
int A[100][100];
int cntNum[100]= { 0, };

void solution() {
	int r_size = 3, c_size = 3, max_r = 3, max_c = 3;

	while (A[r-1][c-1] != k) {
		if (ans > 100) {
			ans = -1;
			break;
		}
		if (r_size >= c_size) {
			for (int i = 0; i < r_size; i++) {
				for (int j = 0; j < c_size; j++) {
					if (A[i][j] == 0)
						continue;
					cntNum[A[i][j] - 1]++;
					A[i][j] = 0;
				}
				vector<pair<int, int>> cnt;
				for (int j = 0; j < 100; j++) {
					if (cntNum[j] != 0) {
						cnt.push_back(make_pair(cntNum[j], j));
						cntNum[j] = 0;
					}
				}
				sort(cnt.begin(), cnt.end());
				for (int j = 0; j < cnt.size() * 2; j += 2) {
					A[i][j] = cnt[j / 2].second + 1;
					A[i][j + 1] = cnt[j / 2].first;
				}
				if (max_c < (cnt.size() * 2))
					max_c = cnt.size() * 2;
			}
		}
		else {
			for (int i = 0; i < c_size; i++) {
				for (int j = 0; j < r_size; j++) {
					if (A[j][i] == 0)
						continue;
					cntNum[A[j][i] - 1]++;
					A[j][i] = 0;
				}
				vector<pair<int, int>> cnt;
				for (int j = 0; j < 100; j++) {
					if (cntNum[j] != 0) {
						cnt.push_back(make_pair(cntNum[j], j));
						cntNum[j] = 0;
					}
				}
				sort(cnt.begin(), cnt.end());
				for (int j = 0; j < cnt.size() * 2; j += 2) {
					A[j][i] = cnt[j / 2].second + 1;
					A[j + 1][i] = cnt[j / 2].first;
				}
				if (max_r < (cnt.size() * 2))
					max_r = cnt.size() * 2;
			}
		}
		r_size = max_r;
		c_size = max_c;
		ans++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
			cin >> A[i][j];
		

	solution();

	cout << ans << "\n";
}