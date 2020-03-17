#include <iostream>
using namespace std;

int main() {
	int T, H, W, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> H >> W >> N;
		if (N%H != 0)
			cout << ((N / H) + 1) + ((N%H) * 100) << endl;
		else
			cout << (H * 100) + (N / H) << endl;
	}
}