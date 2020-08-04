#include <iostream>
#define MAX 1000000
using namespace std;

int ok(int N) {
	for (int i = 1; i <= MAX; i++) {
		int a = i % 10;
		int b = (i % 100) / 10;
		int c = (i % 1000) / 100;
		int d = (i % 10000) / 1000;
		int e = (i % 100000) / 10000;
		int f = i / 100000;

		if (a + b + c + d + e + f + i == N) {
			return i;
		}
	}
	return 0;
}

int main() {
	int N;
	cin >> N;
	int ans = ok(N);
	cout << ans;
}