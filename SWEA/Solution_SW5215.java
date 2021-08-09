package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW5215 {
	public static int N, L, ans = 0;
	public static int info[][];
	public static boolean isSelected[];

	public static void select(int idx, int favor, int total_cal) {
		if (total_cal <= L) {
			if (ans < favor)
				ans = favor;
		}

		else if (total_cal > L)
			return;

		for (int i = idx; i < N; i++) {
			if (isSelected[i])
				continue;
			isSelected[i] = true;
			select(i + 1, favor + info[i][0], total_cal + info[i][1]);
			isSelected[i] = false;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			info = new int[N][2];
			isSelected = new boolean[N];
			ans = 0;

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				info[i][0] = Integer.parseInt(st.nextToken());
				info[i][1] = Integer.parseInt(st.nextToken());
			}

			select(0, 0, 0);

			System.out.printf("#%d %d\n", t + 1, ans);
		}
	}

}
