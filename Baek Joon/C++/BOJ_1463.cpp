#include <iostream>
using namespace std;

int min_cnt=100000;

void DFS(int a, int cnt) {
	if (a == 1 && cnt<min_cnt) {
		min_cnt = cnt;
	}
	else if(cnt<min_cnt){
		if (a % 3 ==0)
			DFS(a / 3, cnt + 1);
		if (a % 2 == 0)
			DFS(a / 2, cnt + 1);
		DFS(a - 1, cnt + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	int N;
	cin >> N;
	DFS(N, 0);
	cout << min_cnt << endl;
}