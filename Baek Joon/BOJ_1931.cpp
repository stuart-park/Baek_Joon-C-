#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, y;
	cin >> n;
	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		time.push_back(make_pair(y, x));
	}

	sort(time.begin(), time.end());

	int ans = 1;
	int start = time[0].first;
	for (int i = 1; i < n; i++) {
		if (start <= time[i].second) {
			ans++;
			start = time[i].first;
		}
	}

	cout << ans << '\n';
}