#include <iostream>
#include <vector>
#include <string>
using namespace std;

string check(vector<int> arr) {
	if (arr[0] == 1) {
		for (int i = 0; i < 7; i++) {
			if (arr[i + 1] == arr[i] + 1)
				continue;
			else
				return "mixed";
		}
		return "ascending";
	}
	if(arr[0]==8) {
		for (int i = 0; i < 7; i++) {
			if (arr[i + 1] == arr[i] - 1)
				continue;
			else
				return "mixed";
		}
		return "descending";
	}
}

int main() {
	vector<int> arr(8);
	for (int i = 0; i < 8; i++)
		cin >> arr[i];
	string ans = check(arr);
	cout << ans << endl;
}