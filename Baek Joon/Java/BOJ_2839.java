package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_2839 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());

		int a = N / 5;
		int b = (N % 5) / 3;

		while (a != -1) {
			if ((a * 5) + (b * 3) == N) {
				System.out.println(a + b);
				break;
			} else {
				a = a - 1;
				b = (N - (a * 5)) / 3;
			}
		}

		if (a == -1)
			System.out.println("-1");
		
	}
}
