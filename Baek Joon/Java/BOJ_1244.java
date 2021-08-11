package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1244 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int switch_num, student_num;
		int[] switches = new int[100];

		switch_num = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 0; i < switch_num; i++) {
			switches[i] = Integer.parseInt(st.nextToken());
		}

		student_num = Integer.parseInt(br.readLine());

		for (int i = 0; i < student_num; i++) {
			st = new StringTokenizer(br.readLine());
			int gender = Integer.parseInt(st.nextToken());
			if (gender == 1) {
				int num = Integer.parseInt(st.nextToken());
				for (int j = 0; j < switch_num; j++) {
					if ((j + 1) % num == 0) {
						switches[j] = switches[j] == 0 ? 1 : 0;
					}
				}
			} else if (gender == 2) {
				int cur_pos = Integer.parseInt(st.nextToken()) - 1;
				int n = 1;
				switches[cur_pos] = switches[cur_pos] == 0 ? 1 : 0;
				while (true) {
					if (cur_pos - n < 0 || cur_pos + n >= switch_num || switches[cur_pos - n] != switches[cur_pos + n])
						break;
					else if (switches[cur_pos - n] == switches[cur_pos + n]) {
						switches[cur_pos - n] = switches[cur_pos - n] == 0 ? 1 : 0;
						switches[cur_pos + n] = switches[cur_pos + n] == 0 ? 1 : 0; // =switches[cur_pos + n] ^ 1;  
						n++;
					}
				}

			}
		}

		for (int i = 0; i < switch_num; i++) {
			if ((i + 1) % 20 == 0) {
				System.out.printf("%d", switches[i]);
				System.out.println();
			} else
				System.out.printf("%d ", switches[i]);
		}
	}
}
