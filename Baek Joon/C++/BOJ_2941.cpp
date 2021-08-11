#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> alp = { "c=","c-", "dz=", "d-","lj","nj","s=","z=" };
	int ans = 0;
	string s;
	cin >> s;
	
	for (int i = 0; i < s.size();) {
		for (int j = 0; j < alp.size(); j++) {
			if (s.substr(i, alp[j].size()) == alp[j]) {
				ans++;
				i += alp[j].size();
				break;
			}
			else if (j == alp.size() - 1) {
				ans++;
				i++;
			}
		}
	}

	cout << ans;
}