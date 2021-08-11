#include <iostream>
using namespace std;

int main() {
	int N, i=1;
	cin >> N;

	int a = N / 5;
	int b = (N % 5) / 3;

	while (a!=-1) {
		if ((a * 5) + (b * 3) == N) {
			cout << a + b;
			break;
		}
		else {
			a = a - 1;
			b = (N - (a * 5)) / 3;
		}
	}

	if (a == -1)
		cout << "-1";
}