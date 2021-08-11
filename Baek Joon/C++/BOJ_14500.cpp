#include <iostream>
#include <queue>
using namespace std;

int N, M, ans = 0;
int board[500][500];

void shape_num1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 3; j++) {
			int total_num = 0;
			for (int k = j; k < j + 4; k++)
				total_num += board[i][k];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N - 3; j++) {
			int total_num = 0;
			for (int k = j; k < j + 4; k++)
				total_num += board[k][i];
			if (total_num > ans)
				ans = total_num;
		}
	}
}

void shape_num2() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j], 
				total_num += board[i][j + 1], total_num += board[i + 1][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
}

void shape_num3() {
	for (int i = 0; i < N-2; i++) {
		for (int j = 0; j < M-1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 2][j], total_num += board[i + 2][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < M; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 2][j], total_num += board[i + 2][j - 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i][j + 1],
				total_num += board[i + 1][j + 1], total_num += board[i + 2][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 2][j], total_num += board[i][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 1][j + 1], total_num += board[i + 1][j + 2];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 1; i < N ; i++) {
		for (int j = 0; j < M - 2; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i][j + 1],
				total_num += board[i][j + 2], total_num += board[i - 1][j + 2];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i][j + 1],
				total_num += board[i][j + 2], total_num += board[i + 1][j + 2];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i][j + 1], total_num += board[i][j + 2];
			if (total_num > ans)
				ans = total_num;
		}
	}

}

void shape_num4() {
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 1][j + 1], total_num += board[i + 2][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M - 2; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i][j + 1],
				total_num += board[i - 1][j + 1], total_num += board[i - 1][j + 2];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < M; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 1][j - 1], total_num += board[i + 2][j - 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i][j + 1],
				total_num += board[i + 1][j + 1], total_num += board[i + 1][j + 2];
			if (total_num > ans)
				ans = total_num;
		}
	}
}

void shape_num5() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 2; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i][j + 1],
				total_num += board[i][j + 2], total_num += board[i + 1][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i][j + 1],
				total_num += board[i - 1][j + 1], total_num += board[i + 1][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < M - 1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 1][j - 1], total_num += board[i + 1][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 1; j++) {
			int total_num = 0;
			total_num += board[i][j], total_num += board[i + 1][j],
				total_num += board[i + 2][j], total_num += board[i + 1][j + 1];
			if (total_num > ans)
				ans = total_num;
		}
	}
}


void solve(){
	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0: 
			shape_num1();
		case 1: 
			shape_num2();
		case 2: 
			shape_num3();
		case 3: 
			shape_num4();
		case 4: 
			shape_num5();
		}
	}
}

 int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	solve();

	cout << ans << "\n";
}