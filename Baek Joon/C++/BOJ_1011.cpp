#include <iostream>
using namespace std;

int main() {
	int T; 
	long long x, y;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		long long total = 0;
		for (long long j = 0;; j++) {
			total += j;
			if ((y - x) <= total * 2) {
				if ((y - x) <= (total) * 2 - j)
					cout << (j * 2) - 1 << endl;
				else
					cout << j * 2 << endl;
				break;
			}
		}
	}
}