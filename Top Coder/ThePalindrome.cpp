#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class ThePalindrome {
public:
	int find(string s) {
		int ans = 0;
		while (1) {
			if (s.size() == 0 || s.size() == 1)
				break;
			if (s[0] == s[s.size() - 1]) {
				s.erase(0, 1);
				s.erase(s.size() - 1, 1);
				ans += 2;
			}
			else {
				s.erase(0, 1);
				ans += 2;
			}
		}
		if (s.size() == 1)
			return ans + 1;
		else
			return ans;
	}
};
