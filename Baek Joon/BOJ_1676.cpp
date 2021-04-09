#include <iostream>
using namespace std;

int two_num[500] = {0, };
int five_num[500] = {0, };

int main() {
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int num1 = 0, num2 = 0;
	for (int i = 0; i < 500; i++) {
		int tmp = i + 1;
		while (tmp % 2 == 0) {
			tmp = tmp / 2;
			num1++;
		}
		while(tmp%5==0){
			tmp = tmp / 5;
			num2++;
		}
		two_num[i] = num1;
		five_num[i] = num2;
		num1 = 0, num2 = 0;
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N; i++) {
		sum1 += two_num[i];
		sum2 += five_num[i];
	}

	int ans = (sum1 > sum2) ? sum2 : sum1;
	cout << ans << endl;
}