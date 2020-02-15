#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int arr[10];
	vector<int> arr2;
	int count = 1;

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		arr2.push_back(arr[i] % 42);
	}

	sort(arr2.begin(), arr2.end());

	for (int i = 0; i < 9; i++) {
		if (arr2[i] != arr2[i + 1])
			count++;
	}

	cout << count << endl;
}