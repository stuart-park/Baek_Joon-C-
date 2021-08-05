package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_SW1225 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		Queue<Integer> q = new LinkedList<>();

		for (int t = 0; t < 10; t++) {
			int TC = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 8; i++)
				q.add(Integer.parseInt(st.nextToken()));

			int k = 1;
			while (true) {
				int num = q.poll() - k;
				if (num <= 0) {
					q.add(0);
					break;
				}
				q.add(num);
				if (k == 5)
					k = 1;
				else
					k++;
			}

			System.out.printf("#%d ", TC);
			for (int i = 0; i < 8; i++)
				System.out.printf("%d ", q.poll());
			System.out.printf("\n");
		}
	}
}
