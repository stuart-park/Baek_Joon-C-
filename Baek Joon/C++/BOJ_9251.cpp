#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	string A, B;
	cin >> A >> B;

	for (int j = 1; j <= A.size(); j++) {
		for (int k = 1; k <= B.size(); k++) {
			if (A[j - 1] == B[k - 1]) {
				dp[j][k] = dp[j - 1][k - 1] + 1;
			}
			else {
				dp[j][k] = max(dp[j][k - 1], dp[j - 1][k]);
			}
		}
	}
		
	cout << dp[A.size()][B.size()] << endl;
}