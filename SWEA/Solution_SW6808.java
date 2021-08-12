package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW6808 {
	public static int win_num, lose_num;
	public static int[] A; //규영
	public static boolean[] isSelected;

	public static void startGame(int cnt, int total_A, int total_B) {
		if (cnt == 9) {
			if (total_A > total_B)
				win_num++;
			else if (total_A < total_B)
				lose_num++;
			return;
		}

		for (int i = 1; i < 19; i++) {
			if (isSelected[i])
				continue;
			isSelected[i] = true;
			startGame(cnt + 1, i < A[cnt] ? total_A + i + A[cnt] : total_A,
					i > A[cnt] ? total_B + i + A[cnt] : total_B);
			isSelected[i] = false;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			st = new StringTokenizer(br.readLine());

			win_num = 0;
			lose_num = 0;
			A = new int[9];
			isSelected = new boolean[19];
			for (int i = 0; i < 9; i++) {
				A[i] = Integer.parseInt(st.nextToken());
				isSelected[A[i]] = true;
			}

			startGame(0, 0, 0);

			sb = new StringBuilder();
			sb.append("#" + t + " " + win_num + " " + lose_num);
			System.out.println(sb.toString());
		}
	}
}
