#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 0;
int T[15], P[15];
int dp[17][17] = { 0, };

void solve() {
	for (int i = 0; i <=N; i++) {
		for (int j = 1; j <= N+1; j++) {
			if (j >= i + 1 + T[i])
				dp[i + 1][j] = max(dp[i][j], dp[i][i + 1] + P[i]);
			else
				dp[i + 1][j] = dp[i][j];
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >>T[i] >> P[i];

	solve();

	cout << dp[N + 1][N + 1] << "\n";

}