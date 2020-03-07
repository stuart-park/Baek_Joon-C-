#include <iostream>
#include <string>
using namespace std;

int main() {

	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int ans = 1;
	string s;
	getline(cin, s);

	for (int i = 1; i < s.size(); i++)
		if (s[i] == ' ')
			ans++;

	if (s.back() == ' ')
		ans--;

	cout << ans;
}

//input: ' ' 
//output: 0