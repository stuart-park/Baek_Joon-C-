#include <iostream>
using namespace std;

int main() {
	int A, B, V, start = 0, date = 0;
	cin >> A >> B >> V;
	
	V = V - A;

	while (1) {
		if (V % (A - B) == 0)
			break;
		V++;
	}

	cout << (V / (A - B)) + 1;
}