package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_3040 {
	public static boolean isFound = false;
	public static int[] arr = new int[9];
	public static boolean[] isReal = new boolean[9];

	public static void findReal(int idx, int cnt, int sum) {
		if (cnt == 7) {
			if (sum == 100 && !isFound) {
				StringBuilder sb = new StringBuilder();
				for (int i = 0; i < 9; i++)
					if (isReal[i])
						sb.append(arr[i] + "\n");
				System.out.println(sb.toString());
				isFound = true;
			}
			return;
		}

		for (int i = idx; i < 9; i++) {
			if (isReal[i])
				continue;
			isReal[i] = true;
			findReal(i + 1, cnt + 1, sum + arr[i]);
			isReal[i] = false;
			findReal(i + 1, cnt, sum);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int i = 0; i < 9; i++)
			arr[i] = Integer.parseInt(br.readLine());

		findReal(0, 0, 0);
	}

}
