package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW2805 {
	public static int[] dx = { -1, 1 };
	public static int[] dy = { 1, -1 };

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;
		
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			int N = Integer.parseInt(br.readLine());
			int ans = 0;
			int range_start = N / 2;
			int range_end = N / 2;
			int dir = 0;

			for (int i = 0; i < N; i++) {
				String tmp = br.readLine();
				for (int j = 0; j < N; j++) {
					if (j >= range_start && j <= range_end) {
						ans += (tmp.charAt(j) - '0');
					}
				}

				if (range_start == 0 && range_end == N - 1)
					dir = 1;

				range_start += dx[dir];
				range_end += dy[dir];
			}

			System.out.printf("#%d %d", t + 1, ans);
		}
	}
}
