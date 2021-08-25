package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW1251 {
	private static int[][] pos;
	private static double[][] graph;
	private static double[] minWeight;
	private static boolean[] isVisited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= 10; t++) {
			StringBuilder sb = new StringBuilder();
			int N = Integer.parseInt(br.readLine());

			pos = new int[N][2];
			graph = new double[N][N];
			isVisited = new boolean[N];
			minWeight = new double[N];

			for (int i = 0; i < 2; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					int num = Integer.parseInt(st.nextToken());
					pos[j][i] = num;
				}
			}

			double E = Double.parseDouble(br.readLine());

			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					double dist = Math.sqrt(Math.pow(pos[i][0] - pos[j][0], 2) + Math.pow(pos[i][1] - pos[j][1], 2));
					graph[i][j] = dist;
					graph[j][i] = dist;
				}
			}

			for (int i = 0; i < N; i++)
				minWeight[i] = Integer.MAX_VALUE;

			double ans = 0;
			minWeight[0] = 0;

			for (int i = 0; i < N; i++) {
				int minVertex = -1;
				double minDist = Integer.MAX_VALUE;
				for (int j = 0; j < N; j++) {
					if (!isVisited[j] && minDist > minWeight[j]) {
						minVertex = j;
						minDist = minWeight[j];
					}
				}

				isVisited[minVertex] = true;
				ans += minDist * minDist * E;

				for (int j = 0; j < N; j++) {
					if (!isVisited[j] && graph[minVertex][j] != 0 && minWeight[j] > graph[minVertex][j])
						minWeight[j] = graph[minVertex][j];
				}
			}

			sb.append("#" + t + " " + Math.round(ans));
			System.out.println(sb.toString());

		}
	}

}
