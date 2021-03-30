#include <iostream>
#include <cmath>
using namespace std;

int ans = 0;

int segmentation(int N, int r, int c) {
	if (r == 0 && c == 0)
		return 0;
	else {
		if (r < pow(2, N - 1) && c < pow(2, N - 1)) {
			ans+=segmentation(N - 1, r, c);
			return 0;
		}
		else if (r < pow(2, N - 1) && c < pow(2, N)) {
			ans+=segmentation(N - 1, r, c - pow(2, N - 1));
			return pow(4, N - 1);
		}
		else if (r < pow(2, N) && c < pow(2, N - 1)) {
			ans+=segmentation(N - 1, r - pow(2, N - 1), c);
			return pow(4, N - 1) * 2;
		}
		else {
			ans+=segmentation(N - 1, r - pow(2, N - 1), c - pow(2, N - 1));
			return pow(4, N - 1) * 3;
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	int N, r, c;
	cin >> N >> r >> c;

	int total=ans+segmentation(N, r, c);
	cout << total << endl;
		  
}