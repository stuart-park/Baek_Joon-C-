#include <iostream>
using namespace std;

bool prime[1000001];

int main() {
	int M, N;
	cin >> M >> N;

	prime[1] = true;
	for (int i = 2; i < 1000001; i++) {
		int j = 2;
		while (true) {
			int num = i * j;
			if (num > 1000000)
				break;
			prime[num] = true;
			j++;
		}
	}

	for (int i = M; i <= N; i++)
		if (!prime[i])
			cout << i << "\n";
}