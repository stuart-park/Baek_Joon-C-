package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ_2493 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = null;

		int N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());

		Stack<Integer> stack = new Stack<>();
		Stack<Integer> pos = new Stack<>();
		int[] arr = new int[N];

		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		
			while(true) {
				if(stack.empty() || arr[i] <= stack.peek())
					break;
				stack.pop();
				pos.pop();
			}
			
			if (stack.empty())
				sb.append("0 ");
			else
				sb.append(pos.peek()+" ");
			
			stack.add(arr[i]);
			pos.add(i+1);
				
		}
		
		System.out.println(sb.toString());
	}
}
