package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_16236 {
	private static int N, min_x, min_y, min_dist, shark_size = 2, ans = 0, cnt = 0;
	private static int[][] board;
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

	private static void findFish(int x, int y) {
		Queue<Pair<Integer, Integer>> pos = new LinkedList<>();
		Queue<Integer> dist = new LinkedList<>();

		pos.add(new Pair(x, y));
		dist.add(0);

		isVisited[x][y] = true;

		min_x = Integer.MAX_VALUE;
		min_y = Integer.MAX_VALUE;
		min_dist = Integer.MAX_VALUE;

		while (!pos.isEmpty()) {
			int cur_x = pos.peek().first;
			int cur_y = pos.peek().second;
			int cur_dist = dist.peek();

			pos.poll();
			dist.poll();

			if (board[cur_x][cur_y] < shark_size && board[cur_x][cur_y] > 0) {
				if (cur_dist < min_dist) {
					min_dist = cur_dist;
					min_x = cur_x;
					min_y = cur_y;
				} else if (cur_dist == min_dist) {
					if (cur_x < min_x) {
						min_x = cur_x;
						min_y = cur_y;
					} else if (cur_x == min_x)
						if (cur_y < min_y)
							min_y = cur_y;
				}
			}

			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dx[i];
				int next_y = cur_y + dy[i];

				if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= N || isVisited[next_x][next_y]
						|| board[next_x][next_y] > shark_size)
					continue;
				isVisited[next_x][next_y] = true;
				pos.add(new Pair(next_x, next_y));
				dist.add(cur_dist + 1);
			}
		}
	}

	private static void moveStart(int x, int y) {
		while (true) {
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					isVisited[i][j] = false;

			findFish(x, y);

			if (min_x == Integer.MAX_VALUE || min_y == Integer.MAX_VALUE)
				break;

			board[min_x][min_y] = 0;
			x = min_x;
			y = min_y;
			cnt++;

			if (cnt == shark_size) {
				cnt = 0;
				shark_size++;
			}

			ans += min_dist;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		isVisited = new boolean[N][N];

		int s_x = 0, s_y = 0;

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if (board[i][j] == 9) {
					board[i][j] = 0;
					s_x = i;
					s_y = j;
				}
			}

		}

		moveStart(s_x, s_y);

		System.out.println(ans);
	}
}
