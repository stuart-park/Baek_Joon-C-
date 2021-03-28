#include <iostream>
#include <string>

char rotate_cube[1000][2];
int n;
char up[3][3] = { {'w','w','w'}, {'w','w','w'}, {'w','w','w'} };
char down[3][3] = { {'y','y','y'}, {'y','y','y'}, {'y','y','y'} };
char c_left[3][3] = { {'g','g','g'}, {'g','g','g'}, {'g','g','g'} };
char c_right[3][3] = { {'b','b','b'}, {'b','b','b'}, {'b','b','b'} };
char front[3][3] = { {'r','r','r'}, {'r','r','r'}, {'r','r','r'} };
char back[3][3] = { {'o','o','o'}, {'o','o','o'}, {'o','o','o'} };

using namespace std;

void solve() {
	for (int i = 0; i < n; i++) {
		char temp;
		if (rotate_cube[i][0] == 'L') {
			if (rotate_cube[i][1] == '-') {
				for (int j = 0; j < 3; j++) {
					temp = up[j][0];
					up[j][0] = front[j][0];
					front[j][0] = down[j][0];
					down[j][0] = back[j][0];
					back[j][0] = temp;
				}
				temp = c_left[0][0];
				c_left[0][0] = c_left[0][2];
				c_left[0][2] = c_left[2][2];
				c_left[2][2] = c_left[2][0];
				c_left[2][0] = temp;

				temp = c_left[0][1];
				c_left[0][1] = c_left[1][2];
				c_left[1][2] = c_left[2][1];
				c_left[2][1] = c_left[1][0];
				c_left[1][0] = temp;
			}
			else {
				for (int j = 0; j < 3; j++) {
					temp = up[j][0];
					up[j][0] = back[j][0];
					back[j][0] = down[j][0];
					down[j][0] = front[j][0];
					front[j][0] = temp;
				}

				temp = c_left[0][0];
				c_left[0][0] = c_left[2][0];
				c_left[2][0] = c_left[2][2];
				c_left[2][2] = c_left[0][2];
				c_left[0][2] = temp;

				temp = c_left[0][1];
				c_left[0][1] = c_left[1][0];
				c_left[1][0] = c_left[2][1];
				c_left[2][1] = c_left[1][2];
				c_left[1][2] = temp;
			}
		}

		else if (rotate_cube[i][0] == 'R') {
			if (rotate_cube[i][1] == '-') {
				for (int j = 0; j < 3; j++) {
					temp = up[j][2];
					up[j][2] = back[j][2];
					back[j][2] = down[j][2];
					down[j][2] = front[j][2];
					front[j][2] = temp;
				}

				temp = c_right[0][0];
				c_right[0][0] = c_right[0][2];
				c_right[0][2] = c_right[2][2];
				c_right[2][2] = c_right[2][0];
				c_right[2][0] = temp;

				temp = c_right[0][1];
				c_right[0][1] = c_right[1][2];
				c_right[1][2] = c_right[2][1];
				c_right[2][1] = c_right[1][0];
				c_right[1][0] = temp;
				
			}
			else {
				for (int j = 0; j < 3; j++) {
					temp = up[j][2];
					up[j][2] = front[j][2];
					front[j][2] = down[j][2];
					down[j][2] = back[j][2];
					back[j][2] = temp;
				}
				temp = c_right[0][0];
				c_right[0][0] = c_right[2][0];
				c_right[2][0] = c_right[2][2];
				c_right[2][2] = c_right[0][2];
				c_right[0][2] = temp;

				temp = c_right[0][1];
				c_right[0][1] = c_right[1][0];
				c_right[1][0] = c_right[2][1];
				c_right[2][1] = c_right[1][2];
				c_right[1][2] = temp;
			}
		}
		else if (rotate_cube[i][0] == 'U') {
			if (rotate_cube[i][1] == '-') {
				for (int j = 0; j < 3; j++) {
					temp = c_right[j][0];
					c_right[j][0] = front[0][2 - j];
					front[0][2 - j] = c_left[2-j][2];
					c_left[2 - j][2] = back[2][j];
					back[2][j] = temp;
				}

				temp = up[0][0];
				up[0][0] = up[0][2];
				up[0][2] = up[2][2];
				up[2][2] = up[2][0];
				up[2][0] = temp;

				temp = up[0][1];
				up[0][1] = up[1][2];
				up[1][2] = up[2][1];
				up[2][1] = up[1][0];
				up[1][0] = temp;
			}
			else {
				for (int j = 0; j < 3; j++) {
					temp = c_right[j][0];
					c_right[j][0] = back[2][j];
					back[2][j] = c_left[2 - j][2];
					c_left[2 - j][2] = front[0][2 - j];
					front[0][2 - j] = temp;
				}

				temp = up[0][0];
				up[0][0] = up[2][0];
				up[2][0] = up[2][2];
				up[2][2] = up[0][2];
				up[0][2] = temp;

				temp = up[0][1];
				up[0][1] = up[1][0];
				up[1][0] = up[2][1];
				up[2][1] = up[1][2];
				up[1][2] = temp;
			}
		}

		else if (rotate_cube[i][0] == 'D') {
			if (rotate_cube[i][1] == '-') {
				for (int j = 0; j < 3; j++) {
					temp = front[2][j];
					front[2][j] = c_right[2 - j][2];
					c_right[2 - j][2] = back[0][2 - j];
					back[0][2 - j] = c_left[j][0];
					c_left[j][0] = temp;
				}

				temp = down[0][0];
				down[0][0] = down[0][2];
				down[0][2] = down[2][2];
				down[2][2] = down[2][0];
				down[2][0] = temp;

				temp = down[0][1];
				down[0][1] = down[1][2];
				down[1][2] = down[2][1];
				down[2][1] = down[1][0];
				down[1][0] = temp;
				
		
			}
			else {
				for (int j = 0; j < 3; j++) {
					temp = front[2][j];
					front[2][j] = c_left[j][0];
					c_left[j][0] = back[0][2 - j];
					back[0][2 - j] = c_right[2 - j][2];
					c_right[2 - j][2] = temp;
				}

				temp = down[0][0];
				down[0][0] = down[2][0];
				down[2][0] = down[2][2];
				down[2][2] = down[0][2];
				down[0][2] = temp;

				temp = down[0][1];
				down[0][1] = down[1][0];
				down[1][0] = down[2][1];
				down[2][1] = down[1][2];
				down[1][2] = temp;
			}
		}
		else if (rotate_cube[i][0] == 'F') {
			if (rotate_cube[i][1] == '-') {
				for (int j = 0; j < 3; j++) {
					temp = up[2][j];
					up[2][j] = c_right[2][j];
					c_right[2][j] = down[0][2 - j];
					down[0][2 - j] = c_left[2][j];
					c_left[2][j] = temp;
				}

				temp = front[0][0];
				front[0][0] = front[0][2];
				front[0][2] = front[2][2];
				front[2][2] = front[2][0];
				front[2][0] = temp;

				temp = front[0][1];
				front[0][1] = front[1][2];
				front[1][2] = front[2][1];
				front[2][1] = front[1][0];
				front[1][0] = temp;
			}
			else {
				for (int j = 0; j < 3; j++) {
					temp = up[2][j];
					up[2][j] = c_left[2][j];
					c_left[2][j] = down[0][2 - j];
					down[0][2 - j] = c_right[2][j];
					c_right[2][j] = temp;
				}
				temp = front[0][0];
				front[0][0] = front[2][0];
				front[2][0] = front[2][2];
				front[2][2] = front[0][2];
				front[0][2] = temp;

				temp = front[0][1];
				front[0][1] = front[1][0];
				front[1][0] = front[2][1];
				front[2][1] = front[1][2];
				front[1][2] = temp;

			}
		}
		else if (rotate_cube[i][0] == 'B') {
			if (rotate_cube[i][1] == '-') {
				for (int j = 0; j < 3; j++) {
					temp = up[0][2 - j];
					up[0][2 - j] = c_left[0][2 - j];
					c_left[0][2 - j] = down[2][j];
					down[2][j] = c_right[0][2 - j];
					c_right[0][2 - j] = temp;
				}
				temp = back[0][0];
				back[0][0] = back[0][2];
				back[0][2] = back[2][2];
				back[2][2] = back[2][0];
				back[2][0] = temp;

				temp = back[0][1];
				back[0][1] = back[1][2];
				back[1][2] = back[2][1];
				back[2][1] = back[1][0];
				back[1][0] = temp;
			}
			else {
				for (int j = 0; j < 3; j++) {
					temp = up[0][2 - j];
					up[0][2 - j] = c_right[0][2 - j];
					c_right[0][2 - j] = down[2][j];
					down[2][j] = c_left[0][2 - j];
					c_left[0][2 - j] = temp;
				}

				temp = back[0][0];
				back[0][0] = back[2][0];
				back[2][0] = back[2][2];
				back[2][2] = back[0][2];
				back[0][2] = temp;

				temp = back[0][1];
				back[0][1] = back[1][0];
				back[1][0] = back[2][1];
				back[2][1] = back[1][2];
				back[1][2] = temp;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> rotate_cube[i][0] >> rotate_cube[i][1];

		solve();

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << up[i][j];
			cout << "\n";
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				up[i][j] = 'w';
				down[i][j] = 'y';
				c_right[i][j] = 'b';
				c_left[i][j] = 'g';
				front[i][j] = 'r';
				back[i][j] = 'o';

			}
		}
	}
}