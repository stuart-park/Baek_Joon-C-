#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int>& student, vector<bool>& finished, vector<bool>& visited, int s, int& cnt) {
	int nextnode = student[s];
	visited[s] = true;

	if (visited[nextnode - 1] == false)
		DFS(student, finished, visited, nextnode - 1, cnt);

	else if (finished[nextnode - 1] == false) {
		while ((nextnode - 1) != s) {
			cnt++;
			nextnode = student[nextnode - 1];
		}
		cnt++;
	}
	finished[s] = true;
}

int main() {
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N, cnt = 0;
		cin >> N;
		vector<int> student(N);
		vector<bool> visited(N);
		vector<bool> finished(N);

		for (int j = 0; j < N; j++)
			cin >> student[j];

		for (int j = 0; j < N; j++)
			if (visited[j] == false)
				DFS(student, finished, visited, j, cnt);

		cout << N - cnt << endl;

	}
}