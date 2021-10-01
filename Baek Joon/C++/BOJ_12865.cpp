#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K;
int info[101][2];
int dp[101][100001];

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j + info[i][0] <= K) 
				dp[i][j + info[i][0]] = max(dp[i - 1][j + info[i][0]], dp[i - 1][j] + info[i][1]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int W, V;
		cin >> W >> V;
		info[i][0] = W, info[i][1] = V;
	}

	solve();

	cout << dp[N][K] << "\n";
}
