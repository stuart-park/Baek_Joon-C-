#include <iostream>
using namespace std;

int main() {
	int num, temp, count = 0;
	cin >> num;
	temp = num;
	while (1) {
		int a = (num / 10) + (num % 10);
		int d = a % 10;
		int e = (num % 10) * 10;
		int f = e + d;
		count++;
		if (f == temp)
			break;
		num = f;
	}
	cout << count << endl;

}