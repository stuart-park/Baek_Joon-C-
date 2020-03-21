#include <iostream>
using namespace std;

int main() {
	int n, x, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		int count = 0;
		for (int j = 1; j <= x; j++)
			if (x%j == 0)
				count++;
		if (count == 2)
			ans++;
	}
	cout << ans << endl;
}