#include <iostream>
#include <string>
using namespace std;

int main() {
	int T, R;
	cin >> T;
	string s;

	for (int i = 0; i < T; i++) {
		cin >> R >> s;
		for (int j = 0; j < s.size(); j++) {
			for (int k = 0; k < R; k++)
				cout << s[j];
		}
		cout << endl;
	}
}