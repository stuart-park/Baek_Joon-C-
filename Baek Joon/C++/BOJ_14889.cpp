#include <iostream>
using namespace std;

int N, total_1 = 0, total_2 = 0, ans = 100000000;
int ablity[20][20];
bool isTeam[20];

int count_isTeam() {
	int num = 0;
	for (int i = 0; i < N; i++)
		if (isTeam[i] == true)
			num++;

	return num;
}

void solve(int s) {
	if (count_isTeam() == N /2) {
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				if (isTeam[i] == false && isTeam[j] == false)
					total_2 += ablity[i][j], total_2 += ablity[j][i];
				if (isTeam[i] == true && isTeam[j] == true)
					total_1 += ablity[i][j], total_1 += ablity[j][i];
			}
		}
		int temp = total_1 > total_2 ? total_1 - total_2 : total_2 - total_1;
		if (temp < ans)
			ans = temp;

		total_1 = 0, total_2 = 0;
		return;
	}

	for (int i = s; i < N; i++) {
		isTeam[i] = true;
		solve(i + 1);
		isTeam[i] = false;
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ablity[i][j];

	isTeam[0] = true;

	solve(1);

	cout << ans << "\n";
}