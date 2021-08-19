package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_3109 {
	public static int R, C, ans = 0;
	public static boolean isFinish = false;
	public static char[][] board;
	public static int[] dx = { -1, 0, 1 };
	public static int[] dy = { 1, 1, 1 };

	public static void findPath(int r, int c) {
		if (c == C - 1) {
			isFinish = true;
			ans++;
			return;
		}

		for (int i = 0; i < 3; i++) {
			int n_r = r + dx[i];
			int n_c = c + dy[i];
			if (n_r < 0 || n_c < 0 || n_r >= R || n_c >= C || board[n_r][n_c] == 'x' || board[n_r][n_c] == 'o')
				continue;
			board[r][c] = 'o';
			findPath(n_r, n_c);
			if (isFinish)
				return;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		board = new char[R][C];

		for (int i = 0; i < R; i++)
			board[i] = br.readLine().toCharArray();

		for (int i = 0; i < R; i++) {
			isFinish = false;
			findPath(i, 0);
		}

		System.out.println(ans);

	}

}
