package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW3499 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			int N = Integer.parseInt(br.readLine());
			String[] arr = new String[N];
			String[] ans = new String[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
				arr[i] = st.nextToken();

			for (int i = 0; i < N / 2; i++) {
				ans[i * 2] = arr[i];
				ans[i * 2 + 1] = N % 2 == 0 ? arr[i + N / 2] : arr[i + (N / 2) + 1];
			}

			if (N % 2 == 1)
				ans[N - 1] = arr[N / 2];

			System.out.printf("#%d ", t + 1);
			for (int i = 0; i < N; i++)
				System.out.printf("%s ", ans[i]);
			System.out.printf("\n");
		}
	}
}
