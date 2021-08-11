package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_16935 {
	public static int N, M, R;
	public static int[][] arr;

	public static void UpDown() {
		for (int i = 0; i < N / 2; i++) {
			int[] tmp = new int[M];
			for (int j = 0; j < M; j++)
				tmp[j] = arr[i][j];
			for (int j = 0; j < M; j++)
				arr[i][j] = arr[N - i - 1][j];
			for (int j = 0; j < M; j++)
				arr[N - i - 1][j] = tmp[j];
		}
	}

	public static void LeftRight() {
		for (int i = 0; i < M / 2; i++) {
			int[] tmp = new int[N];
			for (int j = 0; j < N; j++)
				tmp[j] = arr[j][i];
			for (int j = 0; j < N; j++)
				arr[j][i] = arr[j][M - i - 1];
			for (int j = 0; j < N; j++)
				arr[j][M - i - 1] = tmp[j];
		}
	}

	public static void RotateRight() {
		int[][] temp = new int[M][N];

		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				temp[i][N - j - 1] = arr[j][i];

		arr = new int[M][N];
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				arr[i][j] = temp[i][j];

		int tmp = N;
		N = M;
		M = tmp;
	}

	public static void RotateLeft() {
		int[][] temp = new int[M][N];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				temp[M - j - 1][i] = arr[i][j];

		arr = new int[M][N];
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				arr[i][j] = temp[i][j];

		int tmp = N;
		N = M;
		M = tmp;
	}

	public static void DivideRotateRight() {
		int[][] temp = new int[N / 2][M / 2];

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < M / 2; j++)
				temp[i][j] = arr[i][j];

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < M / 2; j++)
				arr[i][j] = arr[i + N / 2][j];

		for (int i = N / 2; i < N; i++)
			for (int j = 0; j < M / 2; j++)
				arr[i][j] = arr[i][j + M / 2];

		for (int i = N / 2; i < N; i++)
			for (int j = M / 2; j < M; j++)
				arr[i][j] = arr[i - N / 2][j];

		for (int i = 0; i < N / 2; i++)
			for (int j = M / 2; j < M; j++)
				arr[i][j] = temp[i][j - M / 2];
	}

	public static void DivideRotateLeft() {
		int[][] temp = new int[N / 2][M / 2];

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < M / 2; j++)
				temp[i][j] = arr[i][j];

		for (int i = 0; i < N / 2; i++)
			for (int j = 0; j < M / 2; j++)
				arr[i][j] = arr[i][j + M / 2];

		for (int i = 0; i < N / 2; i++)
			for (int j = M / 2; j < M; j++)
				arr[i][j] = arr[i + N / 2][j];

		for (int i = N / 2; i < N; i++)
			for (int j = M / 2; j < M; j++)
				arr[i][j] = arr[i][j - M / 2];

		for (int i = N / 2; i < N; i++)
			for (int j = 0; j < M / 2; j++)
				arr[i][j] = temp[i - N / 2][j];
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());

		arr = new int[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < R; i++) {
			int cmd = Integer.parseInt(st.nextToken());
			switch (cmd) {
			case 1:
				UpDown();
				break;
			case 2:
				LeftRight();
				break;
			case 3:
				RotateRight();
				break;
			case 4:
				RotateLeft();
				break;
			case 5:
				DivideRotateRight();
				break;
			case 6:
				DivideRotateLeft();
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				sb.append(arr[i][j] + " ");
			sb.append("\n");
		}

		System.out.println(sb.toString());
	}

}
