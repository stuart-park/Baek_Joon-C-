package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW1233 {
	public static int ans = 1;
	public static int N;
	public static int[] Node;

	public static void dfs(int cur_node) {
		if (cur_node * 2 > N)
			return;
		if (cur_node * 2 + 1 > N)
			return;

		if (cur_node * 2 <= N)
			dfs(cur_node * 2);
		if (cur_node * 2 + 1 <= N)
			dfs(cur_node * 2 + 1);

		if ((Node[cur_node * 2] & Node[cur_node * 2 + 1]) == 0)
			ans = 0;
		else if ((Node[cur_node * 2] & Node[cur_node * 2 + 1]) == 1) {
			if (Node[cur_node] == 1)
				ans = 0;
			else
				Node[cur_node] = 1;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		for (int t = 1; t <= 10; t++) {
			ans = 1;
			Node = new int[201];
			N = Integer.parseInt(br.readLine());
			for (int i = 1; i <= N; i++) {
				st = new StringTokenizer(br.readLine());
				int num = Integer.parseInt(st.nextToken());
				char c = st.nextToken().charAt(0);
				if (c >= '0' && c <= '9')
					Node[i] = 1;
				else
					Node[i] = 0;

			}

			dfs(1);

			StringBuilder sb = new StringBuilder();
			sb.append("#" + t + " " + ans + "\n");
			System.out.println(sb.toString());
		}
	}
}
