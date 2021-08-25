package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ_10026 {
	private static int N;
	private static char[][] board;
	private static boolean[][] isVisited;
	private static int[] dx = { 1, -1, 0, 0 };
	private static int[] dy = { 0, 0, 1, -1 };

	private static class Pair<T, S> {
		T first;
		S second;

		Pair(T first, S second) {
			this.first = first;
			this.second = second;
		}
	}

	private static void countSection(int r, int c, boolean isBlind) {
		if (isBlind) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (board[i][j] == 'G')
						board[i][j] = 'R';
				}
			}
		}

		char color = board[r][c];

		Queue<Pair<Integer, Integer>> pos = new LinkedList<>();
		pos.add(new Pair(r, c));
		isVisited[r][c] = true;

		while (!pos.isEmpty()) {
			int cur_r = pos.peek().first;
			int cur_c = pos.peek().second;

			pos.poll();

			for (int i = 0; i < 4; i++) {
				int next_r = cur_r + dx[i];
				int next_c = cur_c + dy[i];
				if (next_r < 0 || next_c < 0 || next_r >= N || next_c >= N || isVisited[next_r][next_c])
					continue;
				else if (color == board[next_r][next_c]) {
					isVisited[next_r][next_c] = true;
					pos.add(new Pair(next_r, next_c));
				}

			}
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(br.readLine());
		board = new char[N][N];
		isVisited = new boolean[N][N];

		int normal = 0, blind = 0;
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < N; j++) {
				board[i][j] = s.charAt(j);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!isVisited[i][j]) {
					countSection(i, j, false);
					normal++;
				}
			}
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				isVisited[i][j] = false;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!isVisited[i][j]) {
					countSection(i, j, true);
					blind++;
				}
			}
		}

		sb.append(normal + " " + blind);
		System.out.println(sb.toString());

	}
}
