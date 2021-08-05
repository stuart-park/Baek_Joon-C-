package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW2001 {
	public static int[][] board;
	public static int N;
	public static int M;

	public static int killFly(int r, int c) {
		int sum = 0;
		for (int i = r; i < M + r; i++) {
			for (int j = c; j < M + c; j++) {
				sum += board[i][j];
			}
		}

		return sum;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T;
		T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			board = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			int max_kill = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					int tmp = 0;
					if (i + M <= N && j + M <= N)
						tmp = killFly(i, j);
					if (max_kill < tmp)
						max_kill = tmp;
				}
			}
			
			System.out.printf("#%d %d\n", t+1, max_kill);
		}

	}

}
