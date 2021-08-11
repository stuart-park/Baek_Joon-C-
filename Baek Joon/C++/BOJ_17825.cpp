#include <iostream>
using namespace std;

int dice[10];
int score[33]; //판 점수
int map[33]; // 판
bool isHorse[33]; //현재 판 위치에 말이 있는지 확인
int horsePos[4]; //현재 말의 위치
int ans = 0;

void solution(int cnt, int sum) {
	if (cnt == 10) { // 10번 이동 완료
		if (ans < sum)
			ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++) { 
		int cur_pos = horsePos[i];
		int next_pos = cur_pos;
		int move_cnt = dice[cnt];

		if (cur_pos == 5 || cur_pos == 10 || cur_pos == 15) {
			if (cur_pos == 5)
				next_pos = 21;
			else if (cur_pos == 10)
				next_pos = 27;
			else
				next_pos = 29;
			move_cnt--;
		}

		while (move_cnt--) {
			next_pos = map[next_pos];
		}

		if (next_pos != 32 && isHorse[next_pos])
			continue;

		isHorse[cur_pos] = false;
		isHorse[next_pos] = true;
		horsePos[i] = next_pos;

		solution(cnt + 1, sum + score[next_pos]);

		horsePos[i] = cur_pos;
		isHorse[next_pos] = false;
		isHorse[cur_pos] = true;
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	for (int i = 0; i < 20; i++)
		map[i] = i + 1;

	map[21] = 22, map[22] = 23, map[23] = 24, map[24] = 25,
		map[25] = 26, map[26] = 20, map[27] = 28, map[28] = 24,
		map[29] = 30, map[30] = 31, map[31] = 24, map[20] = 32, map[32] = 32;

	for (int i = 0; i < 21; i++)
		score[i] = i * 2;
	
	score[21] = 13, score[22] = 16, score[23] = 19, score[24] = 25,
		score[25] = 30, score[26] = 35, score[27] = 22, score[28] = 24,
		score[29] = 28, score[30] = 27, score[31] = 26, score[32] = 0;

	solution(0, 0);

	cout << ans << "\n";
}