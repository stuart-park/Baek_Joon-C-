#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool haveType(string clothes, vector<string> type) {
	for (int j = 0; j < type.size(); j++)
		if (type[j] == clothes)
			return true;
	return false;
}

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	vector<string> type;
	type.push_back(clothes[0][1]);

	for (int i = 1; i < clothes.size(); i++) {
		if (!haveType(clothes[i][1], type))
			type.push_back(clothes[i][1]);
	}

	vector <int> num;

	for (int i = 0; i < type.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < clothes.size(); j++)
			if (type[i] == clothes[j][1])
				cnt++;
		num.push_back(cnt+1);
	}

	for (int i = 0; i < num.size(); i++)
		answer = answer * num[i];

	return answer - 1;
	
}

//int main() {
//	vector < vector<string> >clothes = { {"ABC","A"},{"DFEWR","B"},{"ERQDS","A"} };
//	int a = solution(clothes);
//	cout << a;
//}