#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int person1[5] = { 1,2,3,4,5 };
int person2[8] = { 2,1,2,3,2,4,2,5 };
int person3[10] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> ans;
	vector<pair<int, int>> arr;
	arr.push_back(make_pair(0, 1));
	arr.push_back(make_pair(0, 2));
	arr.push_back(make_pair(0, 3));

	
	for (int i = 0; i < answers.size(); i++) {
		if (answers[i] == person1[i % 5])
			arr[0].first++;
		if (answers[i] == person2[i % 8])
			arr[1].first++;
		if (answers[i] == person3[i % 10])
			arr[2].first++;
	}

	sort(arr.begin(), arr.end());
	ans.push_back(arr[2].second);
	if (arr[2].first == arr[1].first)
		ans.push_back(arr[1].second);
	if (arr[2].first == arr[0].first)
		ans.push_back(arr[0].second);
		
	sort(ans.begin, ans.end);

	return ans;
}