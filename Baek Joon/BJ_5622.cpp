#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> arr = {"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
	int ans=0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			for (int k = 0; k < arr[j].size(); k++) {
				if (arr[j].at(k) == s[i])
					ans += (j + 3);
			}
		}
	}

	cout << ans;
}