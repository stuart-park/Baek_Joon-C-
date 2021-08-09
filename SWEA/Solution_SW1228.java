package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Solution_SW1228 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		for (int t = 0; t < 10; t++) {
			int N = Integer.parseInt(br.readLine());
			LinkedList<Integer> arr = new LinkedList<>();
			st = new StringTokenizer(br.readLine());

			for (int i = 0; i < N; i++) {
				int num = Integer.parseInt(st.nextToken());
				arr.add(num);
			}

			int M = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());

			for (int i = 0; i < M; i++) {
				String s = st.nextToken();
				int start = Integer.parseInt(st.nextToken());
				int num = Integer.parseInt(st.nextToken());
				for (int j = start; j < start + num; j++) {
					int elem = Integer.parseInt(st.nextToken());
					arr.add(j, elem);
				}
			}

			System.out.printf("#%d ", t + 1);
			Iterator<Integer> iter = arr.iterator();
			int i = 0;
			while (i < 10) {
				System.out.printf("%d ", iter.next());
				i++;
			}
			System.out.printf("\n");
		}

	}
}
