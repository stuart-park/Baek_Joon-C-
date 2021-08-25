package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW3289 {
	private static int[] numbers;

	private static void union(int a, int b) {
		int aRoot = findSet(a);
		int bRoot = findSet(b);
		if (aRoot != bRoot)
			numbers[bRoot] = aRoot;
	}

	private static int findSet(int a) {
		if (a == numbers[a])
			return a;
		return numbers[a] = findSet(numbers[a]);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			StringBuilder sb = new StringBuilder();
			sb.append("#" + t + " ");
			st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());

			numbers = new int[n + 1];
			for (int i = 1; i <= n; i++)
				numbers[i] = i;

			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(br.readLine());
				int num = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				if (num == 0)
					union(a, b);
				else if (num == 1) {
					if (findSet(a) == findSet(b))
						sb.append("1");
					else
						sb.append("0");
				}
			}

			System.out.println(sb.toString());

		}
	}

}
