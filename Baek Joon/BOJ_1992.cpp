#include <iostream>
#include <vector>
#include <string>
using namespace std;

string quad_tree_table[64];
string ans;

void segmentation(int x, int y, int N) {
	char start = quad_tree_table[x].at(y);

	for (int i = x; i < x+N; i++) {
		for (int j = y; j < y+N; j++) {
			if (start != quad_tree_table[i].at(j)) {
				ans += '(';
				segmentation(x, y, N/2);
				segmentation(x, y+N/2, N/2);
				segmentation(x+N/2, y, N/2);
				segmentation(x + N / 2, y + N / 2, N / 2);
				ans += ')';
				return;
			}
		}
	}
	ans += start;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> quad_tree_table[i];

	segmentation(0, 0, N);

	cout << ans << '\n';

}