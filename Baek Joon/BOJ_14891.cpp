#include <iostream>
using namespace std;

int gear[4][8];
int K, ans=0;
int rotate_gear[100][2];
int point[4] = { 1, 2, 4, 8 };

void rotate(int direction, int g) {
	if (direction == 1) {
		int temp = gear[g][7];
		for (int i = 7; i > 0; i--)
			gear[g][i] = gear[g][i - 1];
		gear[g][0] = temp;
	}
	else {
		int temp = gear[g][0];
		for (int i = 0; i < 7; i++)
			gear[g][i] = gear[g][i + 1];
		gear[g][7] = temp;
	}
}

void solve() {
	for (int i = 0; i < K; i++) {
		if (rotate_gear[i][1] == 1) {
			if (rotate_gear[i][0] == 1) {
				if (gear[0][2] != gear[1][6]) {
					if (gear[1][2] != gear[2][6]) {
						if (gear[2][2] != gear[3][6]) {
							rotate(-1, 3);
						}
						rotate(1, 2);
					}
					rotate(-1, 1);
				}
				rotate(1, 0);
			}
			else if (rotate_gear[i][0] == 4) {
				if (gear[3][6] != gear[2][2]) {
					if (gear[2][6] != gear[1][2]) {
						if (gear[1][6] != gear[0][2]) {
							rotate(-1, 0);
						}
						rotate(1, 1);
					}
					rotate(-1, 2);
				}
				rotate(1, 3);
			}
			else if (rotate_gear[i][0] == 2) {
				if (gear[1][6] != gear[0][2]) {
					rotate(-1, 0);
				}
				if (gear[1][2] != gear[2][6]) {
					if (gear[2][2] != gear[3][6]) {
						rotate(1, 3);
					}
					rotate(-1, 2);
				}
				rotate(1, 1);
			}
			else if (rotate_gear[i][0] == 3) {
				if (gear[2][2] != gear[3][6]) {
					rotate(-1, 3);
				}
				if (gear[2][6] != gear[1][2]) {
					if (gear[1][6] != gear[0][2]) {
						rotate(1, 0);
					}
					rotate(-1, 1);
				}
				rotate(1, 2);
			}
		}
		else if (rotate_gear[i][1] == -1) {
			if (rotate_gear[i][0] == 1) {
				if (gear[0][2] != gear[1][6]) {
					if (gear[1][2] != gear[2][6]) {
						if (gear[2][2] != gear[3][6]) {
							rotate(1, 3);
						}
						rotate(-1, 2);
					}
					rotate(1, 1);
				}
				rotate(-1, 0);
			}
			else if (rotate_gear[i][0] == 4) {
				if (gear[3][6] != gear[2][2]) {
					if (gear[2][6] != gear[1][2]) {
						if (gear[1][6] != gear[0][2]) {
							rotate(1, 0);
						}
						rotate(-1, 1);
					}
					rotate(1, 2);
				}
				rotate(-1, 3);
			}
			else if (rotate_gear[i][0] == 2) {
				if (gear[1][6] != gear[0][2]) {
					rotate(1, 0);
				}
				if (gear[1][2] != gear[2][6]) {
					if (gear[2][2] != gear[3][6]) {
						rotate(-1, 3);
					}
					rotate(1, 2);
				}
				rotate(-1, 1);
			}
			else if (rotate_gear[i][0] == 3) {
				if (gear[2][2] != gear[3][6]) {
					rotate(1, 3);
				}
				if (gear[2][6] != gear[1][2]) {
					if (gear[1][6] != gear[0][2]) {
						rotate(-1, 0);
					}
					rotate(1, 1);
				}
				rotate(-1, 2);
			}
		}
	}
	
	for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1)
			ans += point[i];
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		for (int j = 7; j >= 0; j--) {
			gear[i][j] = num % 10;
			num /= 10;
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> rotate_gear[i][0] >> rotate_gear[i][1];

	solve();

	cout << ans << "\n";
}