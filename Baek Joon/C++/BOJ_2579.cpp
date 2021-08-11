#include <iostream>	
#include <vector>
#include <algorithm>

using namespace std;

int dp[2][303] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = n-1; i >= 0; i--)
		cin >> arr[i];

	dp[0][2] = arr[0];
	dp[1][2] = arr[0];

	for (int i = 3; i < n+2; i++) {
		dp[0][i] = dp[1][i - 1] + arr[i-2];
		if(i>3)
			dp[1][i] = max(dp[0][i - 2], dp[1][i - 2]) + arr[i-2];
	}

	dp[0][n+2] = max(dp[0][n+1],dp[1][n+1]);
	dp[1][n+2] = max(dp[0][n], dp[1][n]);

	cout << max(dp[0][n+2], dp[1][n+2]) << '\n';
}