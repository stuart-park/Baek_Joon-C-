package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_16926 {
	public static int[][] arr;

	public static void rotate(int row_s, int row_e, int col_s, int col_e) {
		int temp = arr[row_s][col_s];
		for (int i = col_s; i < col_e; i++)
			arr[row_s][i] = arr[row_s][i + 1];
		for (int i = row_s; i < row_e; i++)
			arr[i][col_e] = arr[i + 1][col_e];
		for (int i = col_e; i > col_s; i--)
			arr[row_e][i] = arr[row_e][i - 1];
		for (int i = row_e; i > row_s; i--)
			arr[i][col_s] = arr[i - 1][col_s];
		arr[row_s + 1][col_s] = temp;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		arr = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int row_s = 0;
		int col_s = 0;
		int row_e = N - 1;
		int col_e = M - 1;
		while (true) {
			if (row_s >= row_e || col_s >= col_e)
				break;

			for (int i = 0; i < R; i++)
				rotate(row_s, row_e, col_s, col_e);

			row_s++;
			row_e--;
			col_s++;
			col_e--;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				sb.append(arr[i][j] + " ");
			}
			sb.append("\n");
		}

		System.out.println(sb.toString());
	}
}
