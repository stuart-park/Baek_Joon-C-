package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2961 {
	public static int N, ans = Integer.MAX_VALUE;
	public static int[][] ingredient;
	public static boolean[] isSelected;

	public static void cook(int sour, int bitter, int idx, int cnt) {
		if (idx == N) {
			if (cnt != 0) {
				int num = sour - bitter >= 0 ? sour - bitter : bitter - sour;
				if (num < ans)
					ans = num;
			}
			return;
		}

		for (int i = idx; i < N; i++) {
			if (isSelected[i])
				continue;
			isSelected[i] = true;
			cook(sour * ingredient[i][0], bitter + ingredient[i][1], idx + 1, cnt + 1);
			isSelected[i] = false;
			cook(sour, bitter, idx + 1, cnt);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());

		ingredient = new int[N][2];
		isSelected = new boolean[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			ingredient[i][0] = Integer.parseInt(st.nextToken());
			ingredient[i][1] = Integer.parseInt(st.nextToken());
		}
		cook(1, 0, 0, 0);

		sb.append(ans);
		System.out.println(sb.toString());
	}
}
