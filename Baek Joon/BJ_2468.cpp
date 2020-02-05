#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[100][100];
bool visit[100][100];
int dx[4] = { 1, -1, 0,0 };
int dy[4] = { 0,0,1, -1 };

void reset(){
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			visit[i][j] = false;
}

void DFS(int y, int x, int max) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
		if (y + dy[i] < N && x + dx[i] < N && x + dx[i] >= 0 && y + dy[i] >= 0)
			if (arr[y + dy[i]][x + dx[i]] > max && visit[y + dy[i]][x + dx[i]] == false)
				DFS(y + dy[i], x + dx[i], max);
}

int main() { 
	int temp, num;
	vector<int> safe;
	cin >> N;  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			arr[i][j] = temp;
		}
	}

	for (int max = 0; max <=101; max++) {
		num = 0;
		reset();
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
				if (visit[j][k] == false && arr[j][k] > max) {
					DFS(j, k, max);
					num++;
				}
		}
		safe.push_back(num);
	}
	sort(safe.begin(), safe.end());
	cout << safe.back() << endl;
}