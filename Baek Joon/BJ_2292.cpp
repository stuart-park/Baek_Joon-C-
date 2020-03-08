#include <iostream>
using namespace std;

int main() {
	int N, i = 1, pos = 2;
	cin >> N;
	
	while (1) {
		if (N < pos)
			break;
		pos = pos + (6 * i);
		i++;
	}

	cout << i;
}