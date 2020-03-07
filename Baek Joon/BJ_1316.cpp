#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N, ans = 0;
	cin >> N;

	bool flag;
	vector<string> arr;
	vector<char> temp;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.push_back(s);
	}

	for (int i = 0; i < N; i++) {

		flag = true;
		temp.push_back(arr[i].at(0));

		for (int j = 0; j < arr[i].size() - 1; j++) {
			if (arr[i].size() == 1) {
				ans++;
				break;
			}
			else if (arr[i].at(j) != arr[i].at(j + 1))
				temp.push_back(arr[i].at(j + 1));
			else
				continue;
		}

		sort(temp.begin(), temp.end());

		for (int j = 0; j < temp.size()-1; j++)
			if (temp[j] == temp[j + 1]) {
				flag = false;
				break;
			}

		if (flag)
			ans++;

		temp.clear();

	}

	cout << ans;
}