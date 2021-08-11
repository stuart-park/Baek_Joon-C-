#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, elem;
	cin >> n;
	vector<vector<long long>> board(n, vector<long long>(n, 0));
	vector<vector<long long>> count(n, vector<long long>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> elem;
			board[i][j] = elem;
		}

	count[0][0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int jump = board[i][j];
			if (i + jump < n && i != n - 1)
				count[i + jump][j] += count[i][j];
			if (j + jump < n && j != n - 1)
				count[i][j + jump] += count[i][j];

		}
	}

	cout << count[n - 1][n - 1] << endl;
}