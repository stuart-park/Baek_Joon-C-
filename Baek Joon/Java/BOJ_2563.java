package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2563 {
	public static int[][] board = new int[101][101];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int ans = 0;
		int N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			for (int r = x; r < x + 10; r++) {
				for (int c = y; c < y + 10; c++) {
					if (board[r][c] == 1)
						continue;
					board[r][c] = 1;
					ans++;
				}
			}
		}
		System.out.printf("%d\n", ans);
	}
}
