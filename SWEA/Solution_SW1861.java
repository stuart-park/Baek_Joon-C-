package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_SW1861 {
	public static int[] dx = { 1, -1, 0, 0 };
	public static int[] dy = { 0, 0, 1, -1 };
	public static int[][] board;
	public static int N;

	private static int bfs(int x, int y) {
		Queue<Pair<Integer, Integer>> q = new LinkedList<>();
		q.add(new Pair(x, y));

		int cnt = 0;
		while (!q.isEmpty()) {
			int cur_x = q.peek().first;
			int cur_y = q.peek().second;
			q.poll();
			cnt++;

			for (int i = 0; i < 4; i++) {
				int n_x = cur_x + dx[i];
				int n_y = cur_y + dy[i];
				if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N && board[n_x][n_y] - board[cur_x][cur_y] == 1)
					q.add(new Pair(n_x, n_y));
				else
					continue;
			}
		}

		return cnt;
	}

	private static int dfs(int cur_x, int cur_y, int cnt) {
		int ans = cnt;
		for (int i = 0; i < 4; i++) {
			int n_x = cur_x + dx[i];
			int n_y = cur_y + dy[i];
			if (n_x >= 0 && n_x < N && n_y >= 0 && n_y < N && board[n_x][n_y] - board[cur_x][cur_y] == 1)
				ans = dfs(n_x, n_y, cnt + 1);
			else
				continue;
		}

		return ans;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		for (int t = 1; t <= T; t++) {
			N = Integer.parseInt(br.readLine());
			board = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++)
					board[i][j] = Integer.parseInt(st.nextToken());
			}

			int start_num = 9000000;
			int max_move = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					// int move_num = bfs(i, j);
					int move_num = dfs(i, j, 1);
					if (max_move < move_num) {
						max_move = move_num;
						start_num = board[i][j];
					} else if (max_move == move_num)
						start_num = board[i][j] < start_num ? board[i][j] : start_num;
				}
			}

			StringBuilder sb = new StringBuilder();
			sb.append("#" + t + " " + start_num + " " + max_move);
			System.out.println(sb);
		}
	}
}

class Pair<T, S> {
	T first;
	S second;

	Pair(T first, S second) {
		super();
		this.first = first;
		this.second = second;
	}
}