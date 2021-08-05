package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution_SW1954 {
	public static int[] dx = { 0, 1, 0, -1 };
	public static int[] dy = { 1, 0, -1, 0 };

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			int N = Integer.parseInt(br.readLine());
			int[][] arr = new int[N][N];
			int num = 1;
			int dir = 0;
			int row = 0;
			int col = 0;

			while (num <= N * N) {
				arr[row][col] = num;

				int n_r = row + dx[dir];
				int n_c = col + dy[dir];
				
				if (n_r < 0 || n_c < 0 || n_r >= N || n_c >= N || arr[n_r][n_c] != 0) {
					dir = (dir + 1) % 4;
				}

				row += dx[dir];
				col += dy[dir];

				num++;
			}

			System.out.printf("#%d\n", t + 1);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.printf("%d ", arr[i][j]);
				}
				System.out.printf("\n");
			}
		}
	}
}
