#include <string>
#include <vector>

using namespace std;

void DFS(int &n, vector<bool> &visit, vector<vector<int>> &computers, int s) {
	visit[s] = true;
	for (int i = 0; i < n; i++)
		if (i != s && computers[s][i] == 1 && visit[i] == false) {
			DFS(n, visit, computers, i);
		}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	vector<bool> visit;
	for (int i = 0; i < n; i++)
		visit.push_back(false);

	for (int i = 0; i < n; i++)
		if (visit[i] == false) {
			DFS(n, visit, computers, i);
			answer++;
		}
	return answer;
}