#include <iostream>	
#include <vector>
using namespace std;

int N;
long long B;
vector<vector<int>> matrix(5, vector<int>(5, 0));

vector<vector<int>> multiple(vector<vector<int>> m1, vector<vector<int>> m2) {
	vector<vector<int>> temp(5, vector<int>(5, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int total = 0;
			for (int k = 0; k < N; k++) {
				total += ((m1[i][k] * m2[k][j])%1000);
			}
			temp[i][j] = total % 1000;
		}
	}

	return temp;
}

vector<vector<int>> recursive(long long p) {
	if (p == 1)
		return matrix;

	vector<vector<int>> temp = recursive(p / 2);
	vector<vector<int>> temp2 = multiple(temp, temp);

	if (p % 2 == 0)
		return temp2;
	else
		return multiple(temp2, matrix);
}

int main() {
	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			matrix[i][j] = num;
		}
	}

	vector<vector<int>> ans = recursive(B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
}