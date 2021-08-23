package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_1759 {
	private static int L, C;
	private static char[] words;
	private static boolean[] isSelected = new boolean[15];

	private static void makePassword(int cnt, int idx, int con_num, int col_num) {
		if (cnt == L) {
			if (col_num < 1 || con_num < 2)
				return;
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < C; i++)
				if (isSelected[i])
					sb.append(words[i]);
			System.out.println(sb.toString());
			return;
		}

		for (int i = idx; i < C; i++) {
			if (isSelected[i])
				continue;
			isSelected[i] = true;
			if (words[i] == 'a' || words[i] == 'e' || words[i] == 'i' || words[i] == 'o' || words[i] == 'u')
				makePassword(cnt + 1, i + 1, con_num, col_num + 1);
			else
				makePassword(cnt + 1, i + 1, con_num + 1, col_num);
			isSelected[i] = false;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		L = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		words = new char[C];

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < C; i++)
			words[i] = st.nextToken().charAt(0);
		Arrays.sort(words);

		makePassword(0, 0, 0, 0);

	}

}
