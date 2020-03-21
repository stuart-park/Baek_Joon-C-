#include <iostream>
using namespace std;

int main() {
	int m, n, total = 0, small;
	bool flag = false;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= i; j++) 
			if (i%j == 0)
				count++;
		if (count == 2) {
			total += i;
			if(flag==false)
				small = i;
			flag = true;
		}
	}

	if (total == 0)
		cout << "-1" << endl;
	else
		cout << total << '\n' << small << endl;
} 