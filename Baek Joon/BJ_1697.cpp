#define MAX 100000
#include <iostream>
#include <queue>
using namespace  std;

int N, K;
bool visit[100001] = { false };

void BFS(int s) {
	queue<pair<int, int>> pos;
	pos.push(make_pair(s, 0));
	while (1) {
		int a = pos.front().first;
		int b = pos.front().second;
		visit[a] = true;
		if (a == K) {
			cout << b << endl;
			break;
		}
		pos.pop();
		if (a - 1 >= 0 && visit[a - 1] == false)
			pos.push(make_pair(a - 1, b + 1));
		if (a + 1 <= MAX && visit[a + 1] == false)
			pos.push(make_pair(a + 1, b + 1));
		if (a * 2 <= MAX && visit[a * 2] == false)
			pos.push(make_pair(a * 2, b + 1));
		
	}
}
 
int main() {
	cin >> N >> K;
	BFS(N);
}