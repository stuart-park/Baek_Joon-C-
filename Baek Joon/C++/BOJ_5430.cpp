#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	int t, n;
	string func, ac;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> func >> n >> ac;
		string num;
		deque<int> arr;
		bool isReverse = false;
		bool flag = false;

		for (int i = 1; i < ac.size(); i++) {
			if (ac.size() == 2)
				break;
			if (ac[i] == ',' || ac[i] == ']') {
				arr.push_back(stoi(num));
				num.clear();
			}
			else
				num += ac[i];
		}

		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') 
				isReverse = !isReverse;
			
			else if (func[i] == 'D') {
				if (arr.size() == 0) {
					cout << "error" << '\n';
					flag = true;
					break;
				}
				else {
					if (!isReverse)
						arr.pop_front();
					else
						arr.pop_back();
				}
			}
		}

		if (!flag) {
			if (isReverse) {
				for (int i = 0; i < arr.size()/2; i++) {
					int temp = arr[i];
					arr[i] = arr[arr.size() - i - 1];
					arr[arr.size() - i - 1] = temp;
				}
			}
			if (arr.size() == 0)
				cout << "[]" << endl;
			else {
				cout << "[";
				for (int i = 0; i < arr.size() - 1; i++) {
					cout << arr[i] << ",";
				}
				cout << arr[arr.size() - 1] << "]" << '\n';
			}
		}
	}
}