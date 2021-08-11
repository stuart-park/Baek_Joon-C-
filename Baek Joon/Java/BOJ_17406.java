package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.IntStream;

public class BOJ_17406 {
	public static int N, M, R;
	public static int ans = Integer.MAX_VALUE;
	public static int[][] arr;
	public static int[][] rotate_oper;
	public static boolean[] isSelected;

	public static void rotate_cw(int r_s, int r_e, int c_s, int c_e) {
		int temp = arr[r_s][c_s];
		for (int i = r_s; i < r_e; i++)
			arr[i][c_s] = arr[i + 1][c_s];
		for (int i = c_s; i < c_e; i++)
			arr[r_e][i] = arr[r_e][i + 1];
		for (int i = r_e; i > r_s; i--)
			arr[i][c_e] = arr[i - 1][c_e];
		for (int i = c_e; i > c_s; i--)
			arr[r_s][i] = arr[r_s][i - 1];
		arr[r_s][c_s + 1] = temp;
	}

	public static void select_oper(int idx, int cnt) {
		int[][] temp = new int[N + 1][M + 1];
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				temp[i][j] = arr[i][j];

		int r_s = rotate_oper[idx][0] - rotate_oper[idx][2];
		int r_e = rotate_oper[idx][0] + rotate_oper[idx][2];
		int c_s = rotate_oper[idx][1] - rotate_oper[idx][2];
		int c_e = rotate_oper[idx][1] + rotate_oper[idx][2];
		while (true) {
			if (r_s >= r_e || c_s >= c_e)
				break;
			rotate_cw(r_s, r_e, c_s, c_e);
			r_s++;
			r_e--;
			c_s++;
			c_e--;
		}

		if (cnt == R) {
			for (int i = 1; i <= N; i++) {
				int sum = IntStream.of(arr[i]).sum();
				if (sum < ans)
					ans = sum;
			}
			return;
		}

		for (int i = 0; i < R; i++) {
			if (isSelected[i])
				continue;
			isSelected[i] = true;
			select_oper(i, cnt + 1);
			isSelected[i] = false;

		}

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				arr[i][j] = temp[i][j];
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		arr = new int[N + 1][M + 1];
		rotate_oper = new int[R][3];
		isSelected = new boolean[R];

		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		for (int i = 0; i < R; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++)
				rotate_oper[i][j] = Integer.parseInt(st.nextToken());
		}

		for (int i = 0; i < R; i++) {
			isSelected[i] = true;
			select_oper(i, 1);
			isSelected[i] = false;
		}

		System.out.printf("%d ", ans);
	}
}
