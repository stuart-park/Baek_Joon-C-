#include <iostream>
#include <queue>

using namespace std;

int n, min_num = -1000000000, max_num = 1000000000;
int num[11];
int oper[4];

void solve(int cur_num, int idx) {
	if (idx == n) {
		if (cur_num > min_num)
			min_num = cur_num;
		if (cur_num < max_num)
			max_num = cur_num;

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (i == 0 && oper[i]>0) {
			oper[i]--;
			solve(cur_num + num[idx], idx+1);
			oper[i]++;
		}
		else if (i == 1 && oper[i]>0) {
			oper[i]--;
			solve(cur_num - num[idx], idx + 1);
			oper[i]++;
		}
		else if (i == 2 && oper[i]>0) {
			oper[i]--;
			solve(cur_num * num[idx], idx + 1);
			oper[i]++;
		}
		else if(i==3 && oper[i]>0) {
			oper[i]--;
			solve(cur_num / num[idx], idx + 1);
			oper[i]++;
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	solve(num[0], 1);

	cout << min_num << "\n" << max_num << "\n";
}