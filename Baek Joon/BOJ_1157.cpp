#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int main() {

	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	int ans[26] = { 0 };
	int max = 0, a;
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) 
		s[i] = toupper(s[i]);

	for (int i = 65; i < 91; i++) {
		for (int j = 0; j < s.size(); j++)
			if (s[j] == i)
				ans[i - 65]++;
		if (max < ans[i - 65]) {
			max = ans[i - 65];
			a = i;
		}
	}
	
	sort(ans, ans+26);

	if (ans[25] == ans[24])
		cout << "?";
	else
		cout << (char)a;
}