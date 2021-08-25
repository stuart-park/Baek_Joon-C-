package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Solution_SW7465 {
	private static int[] relation;

	private static int findSet(int v) {
		if (v == relation[v])
			return v;
		return relation[v] = findSet(relation[v]);
	}

	private static void union(int a, int b) {
		int aRoot = findSet(a);
		int bRoot = findSet(b);
		if (aRoot != bRoot)
			relation[bRoot] = aRoot;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			StringBuilder sb = new StringBuilder();
			st = new StringTokenizer(br.readLine());

			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int ans = 0;

			relation = new int[N + 1];
			for (int i = 1; i <= N; i++)
				relation[i] = i;

			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				union(a, b);
			}

			List<Integer> list = new ArrayList<>();

			for (int i = 1; i <= N; i++) {
				int root = findSet(i);
				boolean flag = false;
				for (int j = 0; j < list.size(); j++)
					if (list.get(j) == root) {
						flag = true;
						break;
					}
				if (!flag) {
					ans++;
					list.add(root);
				}
			}

			sb.append("#" + t + " " + ans);
			System.out.println(sb.toString());
		}
	}
}
