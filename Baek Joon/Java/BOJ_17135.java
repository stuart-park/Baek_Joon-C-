package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_17135 {
	public static int N, M, D, ans = 0;
	public static int[][] board;
	public static boolean[] isSelected;
	public static int[] dx = { -1, 0, 0 };
	public static int[] dy = { 0, 1, -1 };

	public static void startGame() {
		int sum = 0;

		int[][] temp = new int[N][M];
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp[i][j] = board[i][j];

		Queue<Pair<Integer, Integer>> pos = new LinkedList<>();
		Queue<Pair<Integer, Integer>> enemy = new LinkedList<>();
		Queue<Integer> dist = new LinkedList<>();

		for (int i = N; i > 0; i--) {
			for (int j = 0; j < M; j++) {
				if (isSelected[j]) {
					pos.add(new Pair(i, j));
					dist.add(0);

					int min_dist = Integer.MAX_VALUE;
					int min_y = Integer.MAX_VALUE;
					int min_x = Integer.MAX_VALUE;

					while (!pos.isEmpty()) {
						int cur_x = pos.peek().first;
						int cur_y = pos.peek().second;
						int cur_dist = dist.peek();

						pos.poll();
						dist.poll();

						if (cur_dist >= D)
							continue;

						for (int k = 0; k < 3; k++) {
							int n_x = cur_x + dx[k];
							int n_y = cur_y + dy[k];
							if (n_x < 0 || n_y < 0 || n_x >= i || n_y >= M)
								continue;
							else if (temp[n_x][n_y] == 0) {
								pos.add(new Pair(n_x, n_y));
								dist.add(cur_dist + 1);
							} else if (temp[n_x][n_y] == 1) {
								if (cur_dist + 1 < min_dist) {
									min_dist = cur_dist + 1;
									min_x = n_x;
									min_y = n_y;
								} else if (cur_dist + 1 == min_dist) {
									if (n_y < min_y) {
										min_x = n_x;
										min_y = n_y;
									}
								}
							}
						}
					}

					if (min_dist != Integer.MAX_VALUE)
						enemy.add(new Pair(min_x, min_y));
				}
			}

			while(!enemy.isEmpty()) {
				int x = enemy.peek().first;
				int y = enemy.peek().second;
				enemy.poll();
				if (temp[x][y] == 1) {
					temp[x][y] = 0;
					sum++;
				}
			}

		}

		if (ans < sum)
			ans = sum;
	}

	public static void selectPos(int idx, int cnt) {
		if (cnt == 3) {
			startGame();
			return;
		}

		for (int i = idx; i < M; i++) {
			if (isSelected[i])
				continue;
			isSelected[i] = true;
			selectPos(i + 1, cnt + 1);
			isSelected[i] = false;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		board = new int[N][M];
		isSelected = new boolean[M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		selectPos(0, 0);

		System.out.printf("%d\n", ans);
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