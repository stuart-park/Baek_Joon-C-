package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Solution_SW1223 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for (int t = 1; t <= 10; t++) {
			StringBuilder sb = new StringBuilder();
			int N = Integer.parseInt(br.readLine());

			Stack<Character> stack = new Stack<>();
			String inOrder = br.readLine();
			String postOrder = "";

			for (int i = 0; i < inOrder.length(); i++) {
				if (inOrder.charAt(i) >= '1' && inOrder.charAt(i) <= '9')
					postOrder += inOrder.charAt(i);
				else {
					char oper = inOrder.charAt(i);
					if (!stack.empty()) {
						if (oper == '+') {
							char top = stack.peek();
							stack.pop();
							postOrder += top;
						} else if (oper == '*') {
							char top = stack.peek();
							if (top == '*') {
								stack.pop();
								postOrder += top;
							}
							if (!stack.empty()) {
								top = stack.peek();
								if (top == '+') {
									stack.pop();
									postOrder += top;
								}
							}
						}
					}
					stack.add(oper);
				}
			}
			while(!stack.empty())
				postOrder += stack.pop();

			Stack<Integer> num = new Stack<>();

			for (int i = 0; i < postOrder.length(); i++) {
				char c = postOrder.charAt(i);
				if (c == '+')
					continue;
				else if (c == '*') {
					int num1 = num.pop();
					int num2 = num.pop();
					num.add(num1 * num2);

				} else
					num.add(c - '0');
			}

			int ans = 0;
			while (!num.empty())
				ans += num.pop();

			sb.append("#" + t + " " + ans);
			System.out.println(sb.toString());
		}
	}

}
