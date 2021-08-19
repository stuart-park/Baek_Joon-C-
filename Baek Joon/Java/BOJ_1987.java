package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class BOJ_1987 {
	public static int R, C, ans = 0;
	public static char[][] map;
	public static int[] dx = { 1, -1, 0, 0 };
	public static int[] dy = { 0, 0, 1, -1 };
	public static Set<Character> alphabet;

	public static void findPath(int r, int c, int cnt) {
		if (ans < cnt)
			ans = cnt;

		for (int i = 0; i < 4; i++) {
			int n_x = r + dx[i];
			int n_y = c + dy[i];
			if (n_x < 0 || n_y < 0 || n_x >= R || n_y >= C || alphabet.contains(map[n_x][n_y]))
				continue;
			alphabet.add(map[n_x][n_y]);
			findPath(n_x, n_y, cnt + 1);
			alphabet.remove(map[n_x][n_y]);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());

		map = new char[R][C];
		alphabet = new HashSet<>();

		for (int i = 0; i < R; i++)
			map[i] = br.readLine().toCharArray();

		alphabet.add(map[0][0]);
		findPath(0, 0, 1);
		
		System.out.println(ans);
	}

}
