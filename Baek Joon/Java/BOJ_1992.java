package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_1992 {
	public static int[][] board;
	public static StringBuilder sb = new StringBuilder();

	public static void segmentation(int N, int row, int col) {
		if (N == 1) {
			sb.append(board[row][col]);
			return;
		}

		int start_num = board[row][col];
		boolean flag = false;

		OUT: for (int i = row; i < row + N; i++) {
			for (int j = col; j < col + N; j++) {
				if (start_num != board[i][j]) {
					sb.append("(");
					segmentation(N / 2, row, col);
					segmentation(N / 2, row, col + N / 2);
					segmentation(N / 2, row + N / 2, col);
					segmentation(N / 2, row + N / 2, col + N / 2);
					sb.append(")");
					flag = true;
					break OUT;
				}
			}
		}
		
		if (!flag)
			sb.append(start_num);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		board = new int[N][N];

		for (int i = 0; i < N; i++) {
			String s = br.readLine();	
			for (int j = 0; j < N; j++)
				board[i][j] = s.charAt(j) - '0';
		}

		segmentation(N, 0, 0);

		System.out.println(sb.toString());
	}

}
