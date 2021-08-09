package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW9229 {
	public static int[] arr;
	public static int ans;
	public static int N, M;

	public static void select(int idx, int cnt, int total) {
		if (total > M)
			return;

		if (cnt == 2) {
			if (ans < total)
				ans = total;
			return;
		}

		for (int i = idx; i < N; i++)
			select(i + 1, cnt + 1, total + arr[i]);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			StringBuilder sb = new StringBuilder();
			st = new StringTokenizer(br.readLine());

			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());

			arr = new int[N];
			ans = -1;

			for (int i = 0; i < N; i++)
				arr[i] = Integer.parseInt(st.nextToken());

			select(0, 0, 0);

			sb.append("#" + (t + 1) + " " + ans + "\n");
			System.out.println(sb.toString());

		}
	}
}
