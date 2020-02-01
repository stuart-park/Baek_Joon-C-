#include <iostream>
using namespace std;

int main(void)
{
	int T, k;
	int arr[41][2] = {};

	arr[0][0] = 1;
	arr[1][1] = 1;


	for (int i = 2; i < 41; i++)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> k;
		cout << arr[k][0] << ' ' << arr[k][1] << endl;
	}
	return 0;
}
