#include <iostream>
using namespace std;

int main() {
	int N, count = 0;
	cin >> N;
	for (int i = 1; i <= N; i++){
		if (i < 100)
			count++;
		else {
			int a = i / 100;
			int b = (i % 100) / 10;
			int c = i % 10;
			if (c - b == b - a)
				count++;
		}
	}
	cout << count << endl;
}