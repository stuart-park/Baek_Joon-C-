#include <iostream>
using namespace std;

int main(void) {
	int coin, price, count = 0;
	cin >> coin >> price;
	int arr[10];

	for (int i = 0; i < coin; i++)
		cin >> arr[i];

	for (int i = coin - 1; i >= 0; i--) {
		count += price / arr[i];
		price %= arr[i];
	}

	cout << count << endl;

	return 0;
}
