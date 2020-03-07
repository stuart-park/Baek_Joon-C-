#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	for (int i = 0; i < lost.size(); i++)
		for (int k = 0; k < reserve.size(); k++)
			if (lost[i] == reserve[k]) {
				reserve.erase(reserve.begin() + k);
				lost.erase(lost.begin() + i);
			}

	int answer = n - lost.size();
	int j = 0;

	for (int i = 0; i < lost.size(); i++) {
		if (reserve.size() < j)
			break;
		if ((reserve[j] - 1) == lost[i]) {
			answer++;
			j++;
			continue;
		}
		if ((reserve[j] + 1) == lost[i]) {
			answer++;
			j++;
		}
	}
	return answer;
}
