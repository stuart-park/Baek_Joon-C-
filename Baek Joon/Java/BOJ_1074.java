package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1074 {
	public static int N, r, c;

	public static int segmentation(int n, int row, int col) {
		if (n == 0)
			return 0;

		if (r < row + (int) Math.pow(2, n - 1) && c < col + (int) Math.pow(2, n - 1))
			return segmentation(n - 1, row, col);
		
		else if (r < row + (int) Math.pow(2, n - 1) && c < col + (int) Math.pow(2, n))
			return (int) Math.pow(4, n - 1) + segmentation(n - 1, row, col + (int) Math.pow(2, n - 1));
		
		else if (r < row + (int) Math.pow(2, n) && c < col + (int) Math.pow(2, n - 1))
			return (int) Math.pow(4, n - 1) * 2 + segmentation(n - 1, row + (int) Math.pow(2, n - 1), col);
		
		else
			return (int) Math.pow(4, n - 1) * 3
					+ segmentation(n - 1, row + (int) Math.pow(2, n - 1), col + (int) Math.pow(2, n - 1));

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		int ans = segmentation(N, 0, 0);

		System.out.println(ans);

	}
}
