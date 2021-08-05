package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW1210 {
	public static int[][] board = new int[100][100];

	public static int startLadder() {
		for (int i = 0; i < 100; i++) {
			if (board[0][i] == 0)
				continue;
			else {
				int cur_row = 0;
				int cur_col = i;
				while (true) {
					if (cur_row == 100)
						break;

					if (cur_col - 1 >= 0 && board[cur_row][cur_col - 1] == 1) {
						while (true) {
							if (cur_col - 1 < 0 || board[cur_row][cur_col - 1] == 0)
								break;
							else
								cur_col -= 1;
						}
					}

					else if (cur_col + 1 < 100 && board[cur_row][cur_col + 1] == 1) {
						while (true) {
							if (cur_col + 1 >= 100 || board[cur_row][cur_col + 1] == 0)
								break;
							else
								cur_col += 1;
						}
					}

					cur_row += 1;
				}

				if (board[cur_row - 1][cur_col] == 2)
					return i;
			}
		}

		return 0;
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		for (int i = 0; i < 10; i++) {
			int num = Integer.parseInt(br.readLine());

			for (int j = 0; j < 100; j++) {
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < 100; k++)
					board[j][k] = Integer.parseInt(st.nextToken());
			}

			int ans = startLadder();
			System.out.printf("#%d %d\n", num, ans);

		}
	}
}
