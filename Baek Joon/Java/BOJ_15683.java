package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_15683 {
	private static int N, M, ans = Integer.MAX_VALUE;
	private static int[][] board;
	private static ArrayList<Pair<Integer, Integer>> cctv_pos;
	private static int[] cctv_dir;

	private static void checkArea() {
		int num = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (board[i][j] == 0)
					num++;

		if (num < ans)
			ans = num;
	}

	private static void watchOne(int r, int c, int d) {
		int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		int cur_r = r, cur_c = c;
		while (true) {
			cur_r += dir[d][0];
			cur_c += dir[d][1];
			if (cur_r < 0 || cur_c < 0 || cur_r >= N || cur_c >= M || board[cur_r][cur_c] == 6)
				break;
			else if (board[cur_r][cur_c] == 0)
				board[cur_r][cur_c] = -1;
		}

	}

	private static void watchTwo(int r, int c, int d) {
		int[][][] dir = { { { 1, 0 }, { -1, 0 } }, { { 0, 1 }, { 0, -1 } } };

		int cur_r, cur_c;
		for (int i = 0; i < 2; i++) {
			cur_r = r;
			cur_c = c;
			while (true) {
				cur_r += dir[d][i][0];
				cur_c += dir[d][i][1];
				if (cur_r < 0 || cur_c < 0 || cur_r >= N || cur_c >= M || board[cur_r][cur_c] == 6)
					break;
				else if (board[cur_r][cur_c] == 0)
					board[cur_r][cur_c] = -1;
			}
		}
	}

	private static void watchThree(int r, int c, int d) {
		int[][][] dir = { { { -1, 0 }, { 0, 1 } }, { { -1, 0 }, { 0, -1 } }, { { 1, 0 }, { 0, -1 } },
				{ { 1, 0 }, { 0, 1 } } };

		int cur_r, cur_c;
		for (int i = 0; i < 2; i++) {
			cur_r = r;
			cur_c = c;
			while (true) {
				cur_r += dir[d][i][0];
				cur_c += dir[d][i][1];
				if (cur_r < 0 || cur_c < 0 || cur_r >= N || cur_c >= M || board[cur_r][cur_c] == 6)
					break;
				else if (board[cur_r][cur_c] == 0)
					board[cur_r][cur_c] = -1;
			}
		}
	}

	private static void watchFour(int r, int c, int d) {
		int[][][] dir = { { { -1, 0 }, { 0, 1 }, { 0, -1 } }, { { -1, 0 }, { 1, 0 }, { 0, 1 } },
				{ { 1, 0 }, { 0, -1 }, { 0, 1 } }, { { 1, 0 }, { 0, -1 }, { -1, 0 } } };

		int cur_r, cur_c;
		for (int i = 0; i < 3; i++) {
			cur_r = r;
			cur_c = c;
			while (true) {
				cur_r += dir[d][i][0];
				cur_c += dir[d][i][1];
				if (cur_r < 0 || cur_c < 0 || cur_r >= N || cur_c >= M || board[cur_r][cur_c] == 6)
					break;
				else if (board[cur_r][cur_c] == 0)
					board[cur_r][cur_c] = -1;
			}
		}
	}

	private static void watchFive(int r, int c, int d) {
		int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

		int cur_r, cur_c;
		for (int i = 0; i < 4; i++) {
			cur_r = r;
			cur_c = c;
			while (true) {
				cur_r += dir[i][0];
				cur_c += dir[i][1];
				if (cur_r < 0 || cur_c < 0 || cur_r >= N || cur_c >= M || board[cur_r][cur_c] == 6)
					break;
				else if (board[cur_r][cur_c] == 0)
					board[cur_r][cur_c] = -1;
			}
		}
	}

	private static void selectDir(int idx, int cnt) {
		if (cnt == cctv_pos.size()) {
			int[][] temp = new int[N][M];
			
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					temp[i][j] = board[i][j];

			for (int i = 0; i < cctv_pos.size(); i++) {
				int cctv_type = board[cctv_pos.get(i).first][cctv_pos.get(i).second];
				switch (cctv_type) {
				case 1:
					watchOne(cctv_pos.get(i).first, cctv_pos.get(i).second, cctv_dir[i]);
					break;
				case 2:
					watchTwo(cctv_pos.get(i).first, cctv_pos.get(i).second, cctv_dir[i]);
					break;
				case 3:
					watchThree(cctv_pos.get(i).first, cctv_pos.get(i).second, cctv_dir[i]);
					break;
				case 4:
					watchFour(cctv_pos.get(i).first, cctv_pos.get(i).second, cctv_dir[i]);
					break;
				case 5:
					watchFive(cctv_pos.get(i).first, cctv_pos.get(i).second, cctv_dir[i]);
					break;
				}
			}
			checkArea();
			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					board[i][j] = temp[i][j];

			return;
		}

		int cctv_type = board[cctv_pos.get(idx).first][cctv_pos.get(idx).second];
		if (cctv_type == 1 || cctv_type == 3 || cctv_type == 4) {
			for (int j = 0; j < 4; j++) {
				cctv_dir[idx] = j;
				selectDir(idx + 1, cnt + 1);
			}
		} else if (cctv_type == 2) {
			for (int j = 0; j < 2; j++) {
				cctv_dir[idx] = j;
				selectDir(idx + 1, cnt + 1);
			}
		} else {
			cctv_dir[idx] = 0;
			selectDir(idx + 1, cnt + 1);
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		board = new int[N][M];
		cctv_pos = new ArrayList<>();

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if (board[i][j] >= 1 && board[i][j] <= 5)
					cctv_pos.add(new Pair(i, j));
			}
		}

		cctv_dir = new int[cctv_pos.size()];
		selectDir(0, 0);

		System.out.println(ans);

	}
}

class Pair<T, S> {
	T first;
	S second;

	Pair(T first, S second) {
		this.first = first;
		this.second = second;
	}
}
