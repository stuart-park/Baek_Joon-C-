#include <iostream>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> point(n);
	for (int i = 0; i < n; i++)
		cin >> point[i];

	int max_point = point[n - 1];
	for (int i = n - 1; i >= 0; ) {
		if (max_point + point[i-1] > max_point + point[i - 2]) {
			max_point += point[i-1];
			i = i - 1;
		}
		else {
			max_point += point[i - 2];
			i = i - 2;
		}
	}

	cout << max_point << '\n'; 


}