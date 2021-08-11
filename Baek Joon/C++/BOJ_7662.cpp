#include <iostream>
#include <set>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t -- ) {
		int n;
		cin >> n;

		multiset <int> dual_pq;

		for (int i = 0; i < n; i++) {
			char oper;
			int num;
			cin >> oper >> num;
			if (oper == 'I')
				dual_pq.insert(num);
			else if(!dual_pq.empty()) {
				if (num == -1) {
					auto dual_max = dual_pq.begin();
					dual_pq.erase(dual_max);
				}
				else {
					auto dual_min = dual_pq.end();
					dual_min--;
					dual_pq.erase(dual_min);
				}
			}
		}

		if (dual_pq.empty())
			cout << "EMPTY" << '\n';
		else {
			auto end_it = dual_pq.end();
			end_it--;
			cout << *end_it << " " << *dual_pq.begin() << '\n';
		}
	}

}