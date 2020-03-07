#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int count = 0;
	vector<bool> visit;
	for (int i = 0; i < words.size(); i++)
		visit.push_back(false);
	queue<pair<string, int>> q;
	q.push(make_pair(begin, 0));

	while (q.empty()==false) {
		string temp = q.front().first;
		int temp2 = q.front().second;
		q.pop();
		if (temp == target) {
			answer = temp2;
			break;
		}
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < temp.size(); j++)
				if (temp[j] != words[i].at(j))
					count++;
			if (count == 1 && visit[i] == false) {
				q.push(make_pair(words[i], temp2 + 1));
				visit[i] = true;
			}
		}
		count = 0;
	}	

	return answer;
}