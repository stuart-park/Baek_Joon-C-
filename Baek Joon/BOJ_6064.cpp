#include <iostream>
using namespace std;

int euclidean(int m, int n) {
	int a;
	while (m != 0) {
		a = n % m;
		n = m;
		m = a;
	}
	return n;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		int num = x;
		int lcm;
		if (n > m)
			lcm = (m * n) / euclidean(m, n);
		else
			lcm = (m * n) / euclidean(n, m);

		if (x == m)
			x = 0;
		if (y == n)
			y = 0;

		while (num % n != y) {
			num = num + m;
			if (num > lcm)
				break;
		}

		if (num > lcm)
			cout << "-1" << '\n';
		else
			cout << num << '\n';
	}
}