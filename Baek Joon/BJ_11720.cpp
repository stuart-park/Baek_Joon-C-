#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, total = 0;
	string s;
	cin >> N;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		total += (s[i] - 48);
	}

	cout << total << endl;
}