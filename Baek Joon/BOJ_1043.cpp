#include <iostream>
#include <vector>
using namespace std;

int n, m, num_people, ans = 0;
int graph[51][51] = { 0, };
int party_num[51][51] = { 0, };
bool true_person[51] = { false, };

void dfs(int node) {
	for (int i = 1; i <= n; i++) {
		if (!true_person[i] && graph[node][i] == 1) {
			true_person[i] = true;
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m >> num_people;

	if (num_people != 0) {
		for (int i = 0; i < num_people; i++) {
			int tmp;
			cin >> tmp;
			true_person[tmp] = true;
		}
	}

	for (int i = 0; i < m; i++) {
		int num_person;
		cin >> num_person;

		for (int j = 0; j < num_person; j++) {
			int tmp;
			cin >> tmp;
			party_num[i][j] = tmp;
		}

		for (int j = 0; j < num_person - 1; j++) {
			for (int k = j + 1; k < num_person; k++) {
				graph[party_num[i][j]][party_num[i][k]] = 1;
				graph[party_num[i][k]][party_num[i][j]] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (true_person[i])
			dfs(i);
	}

	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (true_person[party_num[i][j]]) {
				flag = true;
				break;
			}	
		}
		if (!flag)
			ans++;
	}

	cout << ans << "\n";	
}