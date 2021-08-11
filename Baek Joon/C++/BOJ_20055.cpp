#include <iostream>
using namespace std;

int N, K, ans = 0;
int belt[200];
bool isRobot[100];

bool check() {
	int num = 0;
	for (int i = 0; i < 2 * N; i++)
		if (belt[i] == 0)
			num++;
	if (num >= K)
		return true;
	return false;
}

void solve() {
	while (!check()) {
		// 과정 1
		int temp = belt[2 * N - 1];
		for (int i = 2 * N - 1; i > 0; i--)
			belt[i] = belt[i - 1];
		belt[0] = temp;
		for (int i = N - 1; i > 0; i--)
			isRobot[i] = isRobot[i - 1];
		isRobot[0] = false;
		if (isRobot[N - 1])
			isRobot[N - 1] = false;

		//과정 2
		for (int i = N - 2; i >= 0; i--)
			if (isRobot[i] && !isRobot[i + 1] && belt[i + 1] >= 1)
				isRobot[i] = false, isRobot[i + 1] = true, belt[i + 1] -= 1;
		if (isRobot[N - 1])
			isRobot[N - 1] = false;

		//과정 3
		if (belt[0]!=0)
			isRobot[0] = true, belt[0] -= 1;

		ans++;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < 2 * N; i++)
		cin >> belt[i];

	solve();

	cout << ans << "\n";
}