package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_1158 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		Queue<Integer> q = new LinkedList<>();
		Queue<Integer> ans = new LinkedList<>();

		for (int i = 1; i <= N; i++)
			q.add(i);

		while (!q.isEmpty()) {
			for (int i = 0; i < K-1; i++) {
				int num = q.poll();
				q.add(num);
			}
			
			int num = q.poll();
			ans.add(num);
		}

		sb.append("<");
		for (int i = 0; i < N - 1; i++)
			sb.append(ans.poll() + ", ");
		sb.append(ans.poll() + ">");
		System.out.println(sb.toString());
	}
}
