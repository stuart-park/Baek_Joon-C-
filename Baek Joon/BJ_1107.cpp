#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int press_num_key = 0;
bool isBroken[10] = { false, };

bool check_key(int n, int max_num, bool flag) {
	if (n == 0) {
		if (isBroken[0] == false) {
			press_num_key++;
			return true;
		}
		else {
			press_num_key = 0;
			return false;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (n / max_num == 0 && flag == false)
			max_num = max_num / 10;
		else {
			flag = true;
			if (isBroken[n / max_num] == true) {
				press_num_key = 0;
				return false;
			}
			else {
				n = n % max_num;
				max_num = max_num / 10;
				press_num_key++;
			}
		}

	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, broke_key, ans;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> broke_key;
		isBroken[broke_key] = true;
	}

	int up_channel = N, down_channel = N;
	int max_num = 100000;
	bool flag = false;
	int cnt1=99999999, cnt2=99999999;

	while (1) {
		if (M == 10)
			break;
		if (check_key(down_channel, max_num, flag) && down_channel != -1) {
			cnt2 = N - down_channel;
			break;
		}
		else if (check_key(up_channel, max_num, flag)) {
			cnt1 = up_channel - N;
			break;
		}
		else {
			up_channel += 1;
			if (down_channel > 0)
				down_channel -= 1;
		}
	}

	int min_cnt = min(cnt1, cnt2);

	ans = min(abs(N - 100), min_cnt + press_num_key);
	cout << ans << '\n';
}