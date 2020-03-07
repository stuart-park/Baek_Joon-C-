#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	int newA = (a % 10) * 100 + ((a % 100) / 10) * 10 + (a / 100);
	int newB = (b % 10) * 100 + ((b % 100) / 10) * 10 + (b / 100);

	if (newA > newB)
		cout << newA;
	else
		cout << newB;
}