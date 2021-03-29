#include <iostream>
using namespace std;

int main() {
	int X, total=0, i=0, temp;
	cin >> X;

	while (1) {
		i++;
		total += i;
		if (X <= total) {
			total = total - i;
			temp = i;
			break;
		}
	}

	for (total = total + 1; total < X; total++) 
		i--;

	if (temp % 2 == 0)
		cout << temp - i + 1 << "/" << i;
	else
		cout << i << "/" << temp - i + 1;
}