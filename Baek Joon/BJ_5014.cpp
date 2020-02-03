//push 해주고 pop하면서 방문표시하는 것보다 방문표시하고 push 해주는 것이 더 빠름

#include <iostream>
#include <queue>
using namespace std;
bool visit[1000001] = { false };
int time[1000001];

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	queue<int> temp;
	temp.push(S);
	visit[S] = true;
	while (!temp.empty()) {
		int a = temp.front();
		temp.pop();
		if (a == G) {
			cout << time[G] << endl;
			return 0;
		}
		if (a + U <= F && visit[a + U] == false) {
			time[a + U] = time[a] + 1;
			temp.push(a + U);
			visit[a + U] = true;
		}
		if (a - D >= 1 && visit[a - D] == false) {
			time[a - D] = time[a] + 1;
			temp.push(a - D);
			visit[a - D] = true;
		}
	}
	cout << "use the stairs" << endl;
}