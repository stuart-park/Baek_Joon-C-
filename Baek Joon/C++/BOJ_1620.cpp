#include <iostream>
#include <map>
#include <string>
#include <ctype.h>

using namespace std;
map<int, string> pokemon;
map<string, int> pokemon2;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> N >> M;

	string tmp;

	for (int i = 0; i <N; i++) {
		cin >> tmp;
		pokemon.insert(make_pair(i + 1, tmp));
		pokemon2.insert(make_pair(tmp, i + 1));
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (isalpha(tmp[0])) {
			cout << pokemon2[tmp] << '\n';
		}
		else {
			cout << pokemon[stoi(tmp)] << '\n';
		}
	}
}

