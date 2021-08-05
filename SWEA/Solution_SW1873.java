package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution_SW1873 {
	public static int[] dx = { -1, 0, 1, 0 };
	public static int[] dy = { 0, 1, 0, -1 };
	public static char[][] board;
	public static int H, W, N, cur_x, cur_y, cur_dir;

	public static void move(int d) {
		cur_dir = d;
		
		if (d == 0)
			board[cur_x][cur_y] = '^';
		else if (d == 1)
			board[cur_x][cur_y] = '>';
		else if (d == 2)
			board[cur_x][cur_y] = 'v';
		else if (d == 3)
			board[cur_x][cur_y] = '<';
		
		int n_x = cur_x + dx[cur_dir];
		int n_y = cur_y + dy[cur_dir];
		if (n_x >= 0 && n_x < H && n_y >= 0 && n_y < W && board[n_x][n_y] == '.') {
			board[cur_x][cur_y] = '.';
			cur_x = n_x;
			cur_y = n_y;
			if (d == 0)
				board[cur_x][cur_y] = '^';
			else if (d == 1)
				board[cur_x][cur_y] = '>';
			else if (d == 2)
				board[cur_x][cur_y] = 'v';
			else if (d == 3)
				board[cur_x][cur_y] = '<';
		}
	}

	public static void shoot() {
		int s_x = cur_x;
		int s_y = cur_y;
		while (true) {
			s_x += dx[cur_dir];
			s_y += dy[cur_dir];
			if (s_x < 0 || s_x >= H || s_y < 0 || s_y >= W || board[s_x][s_y] == '#')
				break;
			else if (board[s_x][s_y] == '.' || board[s_x][s_y] == '-')
				continue;
			else if (board[s_x][s_y] == '*') {
				board[s_x][s_y] = '.';
				break;
			}

		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = null;

		int T = Integer.parseInt(br.readLine());

		// TestCase
		for (int t = 0; t < T; t++) {
			st = new StringTokenizer(br.readLine());
			H = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());

			board = new char[H][W];
			for (int i = 0; i < H; i++) {
				board[i] = br.readLine().toCharArray();
				for (int j = 0; j < W; j++) {
					if (board[i][j] == '^') {
						cur_x = i;
						cur_y = j;
						cur_dir = 0;
					} else if (board[i][j] == '>') {
						cur_x = i;
						cur_y = j;
						cur_dir = 1;
					} else if (board[i][j] == 'v') {
						cur_x = i;
						cur_y = j;
						cur_dir = 2;
					} else if (board[i][j] == '<') {
						cur_x = i;
						cur_y = j;
						cur_dir = 3;
					}
				}
			}
			N = Integer.parseInt(br.readLine());
			String cmd = br.readLine();

			// Solve
			for (int i = 0; i < cmd.length(); i++) {
				char c = cmd.charAt(i);
				if (c == 'U')
					move(0);
				else if (c == 'D')
					move(2);
				else if (c == 'L')
					move(3);
				else if (c == 'R')
					move(1);
				else if (c == 'S')
					shoot();
			}

			System.out.printf("#%d ", t + 1);
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					System.out.printf("%c", board[i][j]);
				}
				System.out.printf("\n");
			}

		}

	}

}
