#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	int n, m, ans=0;
	cin >> n >> m;

	map<string, int> never_seen;
	vector<string> never_heard;
	vector<string> never_both;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		never_heard.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		never_seen.insert(make_pair(temp, i));
	}

	for (int i = 0; i < n; i++) {
		ans+=never_seen.count(never_heard[i]);
		if (never_seen.find(never_heard[i]) != never_seen.end())
			never_both.push_back(never_heard[i]);
	}

	cout << ans << '\n';
	sort(never_both.begin(), never_both.end());
	for (int i = 0; i < never_both.size(); i++)
		cout << never_both[i] << '\n';
		
}