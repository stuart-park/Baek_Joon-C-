#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue <int> front;
	priority_queue <int, vector<int>, greater<int>> middle;
	priority_queue <int, vector<int>, greater<int>> back;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		if (middle.size() < 2)
			middle.push(num);
		else {
			int middle_first = middle.top();
			middle.pop();
			int middle_second = middle.top();
			middle.pop();

			if (num < middle_first) {
				if (front.size() <= back.size())
					front.push(num);
				else {
					back.push(middle_second);
					middle_second = middle_first;
					if (front.empty() || num > front.top())
						middle_first = num;
					else {
						middle_first = front.top();
						front.pop();
						front.push(num);
					}
				}
			}
			else if (middle_second < num) {
				if (front.size() > back.size())
					back.push(num);
				else {
					front.push(middle_first);
					middle_first = middle_second;
					if (back.empty() || num < back.top())
						middle_second = num;
					else {
						middle_second = back.top();
						back.pop();
						back.push(num);
					}
				}
			}
			else {
				if (front.size() > back.size()) {
					back.push(middle_second);
					middle_second = num;
				}
				else {
					front.push(middle_first);
					middle_first = num;
				}

			}

			middle.push(middle_first);
			middle.push(middle_second);
		}

		cout << middle.top() << "\n";
	}
}