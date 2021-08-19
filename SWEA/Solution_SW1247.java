package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW1247 {
	public static int s_r, s_c, d_r, d_c, N, ans = Integer.MAX_VALUE;
	public static int[][] client;
	public static boolean[] isVisited;

	public static void findPath(int r, int c, int dist, int cnt) {
		if (cnt == N) {
			int total_dist = dist + Math.abs(d_r - r) + Math.abs(d_c - c);
			if (ans > total_dist)
				ans = total_dist;
			return;
		}

		for (int i = 0; i < N; i++) {
			if (isVisited[i])
				continue;
			isVisited[i] = true;
			findPath(client[i][0], client[i][1], dist + Math.abs(client[i][0] - r) + Math.abs(client[i][1] - c),
					cnt + 1);
			isVisited[i] = false;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringBuilder sb = new StringBuilder();

			N = Integer.parseInt(br.readLine());
			ans = Integer.MAX_VALUE;
			client = new int[N][2];
			isVisited = new boolean[N];

			st = new StringTokenizer(br.readLine());

			s_r = Integer.parseInt(st.nextToken());
			s_c = Integer.parseInt(st.nextToken());

			d_r = Integer.parseInt(st.nextToken());
			d_c = Integer.parseInt(st.nextToken());

			for (int i = 0; i < N; i++) {
				client[i][0] = Integer.parseInt(st.nextToken());
				client[i][1] = Integer.parseInt(st.nextToken());
			}

			findPath(s_r, s_c, 0, 0);

			sb.append("#" + t + " " + ans);
			System.out.println(sb.toString());
		}
	}
}
