package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_SW1238 {
	private static int ans;
	private static int[][] info;
	private static boolean[] isCalled;

	private static class Pair<T, S> {
		T first;
		S second;

		Pair(T first, S second) {
			this.first = first;
			this.second = second;
		}
	}

	private static void bfs(int start) {
		Queue<Pair<Integer, Integer>> q = new LinkedList<>();

		isCalled[start] = true;
		for (int i = 1; i < 101; i++)
			if (info[start][i] == 1) {
				q.add(new Pair(i, 0));
				isCalled[i] = true;
			}

		int max_num = 0;
		while (!q.isEmpty()) {
			int cur_pos = q.peek().first;
			int cur_num = q.peek().second;
			q.poll();

			if (max_num < cur_num) {
				max_num = cur_num;
				ans = 0;
			}
			if (ans < cur_pos)
				ans = cur_pos;

			for (int i = 1; i < 101; i++)
				if (info[cur_pos][i] == 1 && !isCalled[i]) {
					q.add(new Pair(i, cur_num + 1));
					isCalled[i] = true;
				}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		for (int t = 1; t <= 10; t++) {
			StringBuilder sb = new StringBuilder();
			st = new StringTokenizer(br.readLine());

			ans = 0;
			info = new int[101][101];
			isCalled = new boolean[101];

			int L = Integer.parseInt(st.nextToken());
			int Start = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < L / 2; i++) {
				int s = Integer.parseInt(st.nextToken());
				int d = Integer.parseInt(st.nextToken());
				info[s][d] = 1;
			}

			bfs(Start);

			sb.append("#" + t + " " + ans);
			System.out.println(sb);
		}

	}
}
