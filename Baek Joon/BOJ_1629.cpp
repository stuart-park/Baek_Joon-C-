#include <iostream>
using namespace std;

int a, b, c;

long long func(int n) {
	if (n == 1)
		return a % c;
	if (n % 2 == 0)
		return (func(n / 2) * func(n / 2)) % c;
	else
		return (func(n / 2) * func(1 + n / 2)) % c;
}

 int main() {
	cin >> a >> b >> c;

	cout << func(b) << "\n";
}