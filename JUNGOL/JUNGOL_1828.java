package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class JUNGOL_1828 {
	public static class Temp implements Comparable<Temp> {
		int min_temp, max_temp;

		Temp(int min_temp, int max_temp) {
			super();
			this.min_temp = min_temp;
			this.max_temp = max_temp;
		}

		@Override
		public int compareTo(Temp o) {
			if (o.min_temp - this.min_temp != 0)
				return o.min_temp - this.min_temp;

			return o.max_temp - this.max_temp;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		Temp[] temp = new Temp[N];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int min_temp = Integer.parseInt(st.nextToken());
			int max_temp = Integer.parseInt(st.nextToken());
			temp[i] = new Temp(min_temp, max_temp);
		}

		Arrays.sort(temp);

		int ans = 1;
		int i = 0, j = 1;

		while (true) {
			if (i == N || j == N)
				break;
			
			if (temp[i].min_temp <= temp[j].max_temp) {
				j++;
				continue;
			} else {
				i = j;
				j++;
				ans++;
			}
		}

		System.out.println(ans);

	}

}
