#include <iostream>
#include <cmath>
using namespace std;

int N, M, T, ans = 0;
int circle[50][50];
int temp_c[50][50];
int rotate_num[50][3];
int temp[50];

void solution() {
	for (int i = 0; i < T; i++) {
		//rotate
		for (int j = 0; j < N; j++) {
			if ((j + 1) % rotate_num[i][0] == 0) {
				if (rotate_num[i][1] == 0) {// clock wise
					for (int k = 0; k < M; k++)
						temp[k] = circle[j][k];
					for (int k = 0; k < M; k++)
						circle[j][(k + rotate_num[i][2]) % M] = temp[k];
				}
				else {// counter clock wise
					for (int k = 0; k < M; k++)
						temp[k] = circle[j][k];
					for (int k = 0; k < M; k++) {
						if (k - rotate_num[i][2] < 0)
							circle[j][(k - rotate_num[i][2]) + M] = temp[k];
						else
							circle[j][(k - rotate_num[i][2])] = temp[k];
					}
				}
			}

 		}

		for (int j = 0; j < N; j++)
			for (int k = 0; k < M; k++)
				temp_c[j][k] = circle[j][k];
			

		//check adjacent num
		float total_num = 0;
		int cnt = 0;
		bool flag = false;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (circle[j][k] == 0)
					continue;
				total_num += circle[j][k];
				int temp = temp_c[j][k];

				if (j + 1 < N && temp == temp_c[(j + 1) % N][k])
					circle[j][k] = 0, circle[(j + 1) % N][k] = 0, flag = true;
				if (temp == temp_c[j][(k + 1) % M])
					circle[j][k] = 0, circle[j][(k + 1) % M] = 0, flag = true;
				if (j - 1 >= 0 && temp == temp_c[(j - 1) % N][k])
					circle[j][k] = 0, circle[(j - 1) % N][k] = 0, flag = true;
				if (k - 1 >= 0 && temp == temp_c[j][(k - 1) % M])
						circle[j][k] = 0, circle[j][(k - 1) % M] = 0, flag = true;
				if (k == 0 && temp == temp_c[j][M - 1])
					circle[j][k] = 0, circle[j][M - 1] = 0, flag = true;
				cnt++;
			}
		}

		if (!flag) {
			float avg = total_num / cnt;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < M; k++) {
					if (circle[j][k] == 0)
						continue;
					if (circle[j][k] > avg)
						circle[j][k] -= 1;
					else if (circle[j][k] < avg)
						circle[j][k] += 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += circle[i][j];
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> circle[i][j];
		}
	}
	for (int i = 0; i < T; i++)
		cin >> rotate_num[i][0] >> rotate_num[i][1] >> rotate_num[i][2];

	solution();

	cout << ans << endl;
}