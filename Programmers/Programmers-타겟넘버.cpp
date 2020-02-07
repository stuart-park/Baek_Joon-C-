#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> numbers, int target) {
	int answer = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(0,0));
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == target && b == numbers.size())
			answer++;
		else if (b < numbers.size()) {
			q.push(make_pair(a + numbers[b], b + 1));
			q.push(make_pair(a - numbers[b], b + 1));
		}
	}
	return answer;
}