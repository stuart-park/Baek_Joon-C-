#include <iostream>
#include <vector>
using namespace std;

int main() {
	int C, temp;
	double N;
	cin >> C;
	vector<int> arr;


	for (int i = 0; i < C; i++) {
		cin >> N;
		double avg = 0, ans = 0, count = 0;
		int total = 0;
		arr.clear();
		for (int j = 0; j < N; j++) {
			cin >> temp;
			arr.push_back(temp);
			total += temp;
		}
		avg = total / N;
		for (int j = 0; j < N; j++) {
			if (arr[j] > avg)
				count++;
		}
		ans = (count / N) * 100;
		printf("%.3f%%\n", ans);
	}
}