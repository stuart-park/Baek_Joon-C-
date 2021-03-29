#include <iostream>
using namespace std;

int main() {
	bool arr[10001] = { false };

	for (int i = 1; i < 10001; i++) {
		int a = i / 1000;
		int b = (i % 1000) / 100;
		int c = (i % 100) / 10;
		int d = i % 10;
		if (arr[i + a + b + c + d] == false)
			arr[i + a + b + c + d] = true;
	}

	for (int i = 1; i < 10001; i++) {
		if (arr[i] == false)
			cout << i << endl;
	}
}