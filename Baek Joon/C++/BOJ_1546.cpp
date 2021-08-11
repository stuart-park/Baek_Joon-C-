#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int  main() {
	float N, temp, total = 0, max = 0;
	cin >> N;

	vector<float> arr;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
		if (max < temp)
			max = temp;
	}

	for (int i = 0; i < N; i++) {
		arr[i] = (arr[i] / max) * 100;
		total += arr[i];
	}
	
	cout << total / N << endl;
}