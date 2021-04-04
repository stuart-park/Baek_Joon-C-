#include <iostream>
#include <vector>

using namespace std;

int n, b, c;
long long ans = 0;
vector<int> a;

void solve() {

	for (int i = 0; i < n; i++) {
		if (a[i] < b)
			ans = ans + 1;
		else {
			int student = a[i] - b;
			int sub_num;
			if (student % c != 0)
				sub_num = student / c + 1;
			else
				sub_num = student / c;

			ans = ans + sub_num + 1;
		}
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}

	cin >> b >> c;
	
	solve();

	cout << ans << "\n";
}