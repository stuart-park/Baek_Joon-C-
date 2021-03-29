#include <iostream>
using namespace std;

int main() {
	int burger[3], drink[2];
	int min1 = 2000, min2 = 2000;

	for (int i = 0; i < 3; i++) {
		cin >> burger[i];
		if (min1 > burger[i])
			min1 = burger[i];
	}
		
	for (int i = 0; i < 2; i++) {
		cin >> drink[i];
		if (min2 > drink[i])
			min2 = drink[i];
	}

	cout << min1 + min2 - 50;
}