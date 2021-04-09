#include <iostream>
#include <vector>
using namespace std;

int ans[3] = { 0, 0, 0 };

void check_matrix(vector<vector<int>> &matrix, int i_start, int j_start,  int n) {
	int temp = matrix[i_start][j_start];
	for (int i = i_start; i < i_start+n; i++)
		for (int j = j_start; j < j_start+n; j++)
			if (matrix[i][j] != temp) {
				check_matrix(matrix, i_start, j_start, n / 3);
				check_matrix(matrix, i_start, j_start + n / 3, n / 3);
				check_matrix(matrix, i_start, j_start + (2 * n) / 3, n / 3);
				check_matrix(matrix, i_start + n / 3, j_start, n / 3);
				check_matrix(matrix, i_start + (2 * n) / 3, j_start, n / 3);
				check_matrix(matrix, i_start + n / 3, j_start + n / 3, n / 3);
				check_matrix(matrix, i_start + n / 3, j_start + (2 * n) / 3, n / 3);
				check_matrix(matrix, i_start + (2 * n) / 3, j_start + n / 3, n / 3);
				check_matrix(matrix, i_start + (2 * n) / 3, j_start + (2 * n) / 3, n / 3);
				return;

			}
	if (temp == -1)
		ans[0]++;
	else if (temp == 0)
		ans[1]++;
	else if (temp == 1)
		ans[2]++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int N, temp;
	cin >> N;

	vector<vector<int>> matrix (N, vector <int> (N, 0));

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	check_matrix(matrix, 0, 0, N);

	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
}