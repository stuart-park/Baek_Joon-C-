#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ans[100];
int friends[100][100] = { 0, };
bool visited[100][100] = { false, };

int main() {
	std::ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int f1, f2;
		cin >> f1 >> f2;
		friends[f1-1][f2-1] = 1;
		friends[f2-1][f1-1] = 1;
	}

	for (int i = 0; i < N; i++) {
		int kevin_bacon = 0;
		queue<pair<int, int>> ranks;

		for (int j = 0; j < N; j++) {
			if (friends[i][j] == 1)
				ranks.push(make_pair(j, 1));
		}

		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			while (!ranks.empty()) {
				int cur_friend = ranks.front().first;
				int cur_level = ranks.front().second;
				
				ranks.pop();

				if (visited[i][cur_friend] == true)
					continue;

				if (visited[i][cur_friend] == false) {
					visited[i][cur_friend] = true;
					kevin_bacon += cur_level;
				}

				for (int k = 0; k < N; k++) {
					if ((friends[cur_friend][k] == 1) && (k != i) && (visited[i][k] == false))
						ranks.push(make_pair(k, cur_level + 1));
				}
			}
		}
		ans[i] = kevin_bacon;
	}

	int max = ans[0];
	int max_friend = 1;
	for (int i = 0; i < N; i++) {
		if (ans[i] < max) {
			max = ans[i];
			max_friend = i + 1;
		}
	}
	cout << max_friend << endl;
}