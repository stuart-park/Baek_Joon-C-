#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 97; i < 123; i++)
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == i) {
				cout << j << " ";
				break;
			}
			else if (j == s.size()-1)
				cout << "-1" << " ";
		}
}