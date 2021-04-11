#include <iostream>

using namespace std;

int paper[128][128] = { -1, };
int white = 0;
int blue = 0;

void segmentation(int a, int b, int n) {
	int start = paper[a][b];

	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + n; j++) {
			if (paper[i][j] != start) {
				segmentation(a, b, n / 2);
				segmentation(a + n / 2, b, n / 2);
				segmentation(a, b + n / 2, n / 2);
				segmentation(a+n/2, b+n/2, n / 2);
				return;
			}
		}
	}

	if (start == 1)
		blue++;
	else
		white++;
}

int main() {
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> paper[i][j];
	

	segmentation(0, 0, n);

	cout << white << '\n' << blue << '\n';
}