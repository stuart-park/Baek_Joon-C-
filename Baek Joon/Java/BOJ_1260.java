package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_1260 {
	private static int N, M, V;
	private static int[][] graph = new int[1001][1001];
	private static boolean[] isVisited = new boolean[1001];
	private static StringBuilder sb;

	private static void bfs(int start) {
		Queue<Integer> pos = new LinkedList<>();

		pos.add(start);
		isVisited[start] = true;

		while (!pos.isEmpty()) {
			int cur_pos = pos.poll();
			sb.append(cur_pos + " ");

			for (int i = 1; i <= N; i++) {
				if (graph[cur_pos][i] == 1 && !isVisited[i]) {
					pos.add(i);
					isVisited[i] = true;
				}
			}
		}
	}

	private static void dfs(int node) {
		isVisited[node] = true;
		sb.append(node + " ");

		for (int i = 1; i <= N; i++) {
			if (graph[node][i] == 1 && !isVisited[i])
				dfs(i);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			graph[s][d] = 1;
			graph[d][s] = 1;
		}

		sb = new StringBuilder();
		dfs(V);
		System.out.println(sb.toString());

		sb = new StringBuilder();
		isVisited = new boolean[1001];
		bfs(V);
		System.out.println(sb.toString());
	}

}
