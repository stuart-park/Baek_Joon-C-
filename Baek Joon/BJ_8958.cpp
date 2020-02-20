#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, count=0, total;
	cin >> N;

	string temp;
	vector<string> arr;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < N; i++) {
		total = 0;
		count = 0;
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i].at(j) == 'O') {
				count++;
				total += count;
			}
			else
				count = 0;
		}
		cout << total << endl;
	}
}