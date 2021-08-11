#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);

	string equation;
	cin >> equation;

	string tmp = "";
	int temp = 0;
	vector<int> num;

	for (int i = 0; i < equation.size(); i++) {
		if (equation[i] != '+' && equation[i] != '-')
			tmp += equation[i];

		else if (equation[i] == '-') {
			int a = stoi(tmp);
			temp += a;
			num.push_back(temp);
			temp = 0;
			tmp = "";
		}

		else if(equation[i]=='+'){
			int a = stoi(tmp);
			tmp = "";
			temp += a;
		}
	}
	int a = stoi(tmp);
	if (temp == 0)
		num.push_back(a);
	else {
		temp += a;
		num.push_back(temp);
	}

	int ans = num[0];
	for (int i = 1; i < num.size(); i++) 
		ans -= num[i];

	cout << ans << endl;
}