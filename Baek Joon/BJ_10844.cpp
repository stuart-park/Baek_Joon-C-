#define mod 1000000000
#include <iostream>
using namespace std;

int arr[100][10] = { 0 };

int main() {
	int n, sum = 0;
	cin >> n;

	for (int i = 1; i < 10; i++)
		arr[0][i] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				arr[i][j] = arr[i - 1][j + 1];
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % mod;
		}
	}

	for (int i = 0; i < 10; i++)
		sum = (sum + arr[n - 1][i]) % mod;

	cout << sum << endl;
}