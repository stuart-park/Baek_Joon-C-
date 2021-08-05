package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Solution_SW1208 {

	public static int[] wall = new int[100];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		for (int i = 0; i < 10; i++) {
			int dump_num = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 100; j++) {
				wall[j] = Integer.parseInt(st.nextToken());
			}

			for (int j = 0; j < dump_num; j++) {
				Arrays.sort(wall);
				wall[0]++;
				wall[99]--;
			}
			
			Arrays.sort(wall);
			int ans = wall[99] - wall[0];

			System.out.printf("#%d %d%n", i + 1, ans);
		}

	}

}
