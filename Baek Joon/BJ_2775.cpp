#include <iostream>
using namespace std;

int main() {
	int T, n, k;
	int arr[15][14] = { 0 };

	for (int i = 0; i < 14; i++)
		arr[0][i] = i + 1;

	for (int i = 1; i < 15; i++)
		for (int j = 0; j < 14; j++)
			for (int k = 0; k <= j; k++)
				arr[i][j] += arr[i-1][k];

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << arr[k][n - 1] << endl;
	}
}