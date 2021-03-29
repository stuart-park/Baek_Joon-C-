//메모리 초과//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> arr;
	queue<int> count;
	queue<pair<int, int>> loca;

	for (int i = 0; i < n; i++) {
		string elem;
		cin >> elem;
		arr.push_back(elem);

	}

	loca.push(make_pair(0, 0));
	count.push(1);

	while (loca.empty() == false) {
		int r = loca.front().first;
		int c = loca.front().second;
		int temp = count.front();
		count.pop();
		loca.pop();
		if (r == n - 1 && c == m - 1) 
			break;
		else {
			arr[r].at(c) = '0';
			if (r + 1 < n && arr[r + 1].at(c) == '1') {
				loca.push(make_pair(r + 1, c));
				count.push(temp+1);
			}
			if (c + 1 < m && arr[r].at(c + 1) == '1') {
				loca.push(make_pair(r, c + 1));
				count.push(temp + 1);
			}
			if (r - 1 >= 0 && arr[r - 1].at(c) == '1') {
				loca.push(make_pair(r - 1, c));
				count.push(temp + 1);
			}
			if (c - 1 >= 0 && arr[r].at(c - 1) == '1') {
				loca.push(make_pair(r, c - 1));
				count.push(temp + 1);
			}
		}
	}
	cout << count.back() << endl;
}