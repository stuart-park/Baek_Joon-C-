#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1001];
int buildOrder[1001][1001];
int reqTime[1001];

int calTime(int n, int start) {
	if (dp[start] != -1)
		return dp[start];

	int temp = 0;     

	for (int i = 1; i <=n; i++) {
		if (buildOrder[i][start] == 1) {
			temp = max(temp, calTime(n, i));   
		}
	}
	return dp[start] = temp + reqTime[start];
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k, goal, ans;
		cin >> n >> k;
		//vector<int> reqTime(n+1);
		//vector<vector<int>> buildOrder(n+1, vector<int>(n+1, 0));

		memset(dp, -1, sizeof(dp));
		memset(buildOrder, 0, sizeof(buildOrder));

		for (int j = 1; j <=n; j++)
			cin >> reqTime[j];

		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			buildOrder[x][y] = 1;
		}

		cin >> goal;

		ans = calTime(n, goal);

		cout << ans << endl;
	}
}