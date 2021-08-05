package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution_SW1218 {
	public static char[] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 0; t < 10; t++) {
			int N = Integer.parseInt(br.readLine());
			arr = new char[N];
			arr = br.readLine().toCharArray();
			Stack<Character> stack = new Stack<>();

			for (int i = 0; i < N; i++) {
				if (!stack.empty()) {
					char c = arr[i];
					if (arr[i] == ')' && stack.peek() == '(')
						stack.pop();
					else if (arr[i] == ']' && stack.peek() == '[')
						stack.pop();
					else if (arr[i] == '}' && stack.peek() == '{')
						stack.pop();
					else if (arr[i] == '>' && stack.peek() == '<')
						stack.pop();
					else
						stack.push(arr[i]);
				}
				else
					stack.push(arr[i]);
			}

			int ans = -1;
			if (stack.empty())
				ans = 1;
			else
				ans = 0;
			
			System.out.printf("#%d %d\n", t+1, ans);

		}
	}
}
