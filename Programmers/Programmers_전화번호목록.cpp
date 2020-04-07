#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	for (int i = 0; i < phone_book.size() - 1; i++)
		for (int j = i + 1; j < phone_book.size(); j++) {
			int cnt = 0;
			int n = min(phone_book[i].size(), phone_book[j].size());
			for (int k = 0; k < n; k++) {
				if (phone_book[i].at(k) == phone_book[j].at(k))
					cnt++;
			}
			if (cnt == n) {
				answer = false;
				return answer;
			}
		}
	return answer;
}

int main() {
	vector<string> phone_book = {"119", "991241523","11951321421"};
	bool ans = solution(phone_book);
	cout << ans << endl;
}