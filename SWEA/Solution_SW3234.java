package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution_SW3234 {
    private static int ans = 0;
    
    private static void startSimulation(int cnt, int right_weight, int left_weight, boolean[] isSelected, int[] weight,
            int N) {
        if (cnt == N) {
            ans++;
            return;
        }
 
        for (int i = 0; i < N; i++) {
            if (isSelected[i])
                continue;
            isSelected[i] = true;
            startSimulation(cnt + 1, right_weight, left_weight + weight[i], isSelected, weight, N);
            if (right_weight + weight[i] <= left_weight)
                startSimulation(cnt + 1, right_weight + weight[i], left_weight,  isSelected, weight, N);
            isSelected[i] = false;
        }
    }
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = null;
 
        int T = Integer.parseInt(br.readLine());
 
        for (int t = 1; t <= T; t++) {
            StringBuilder sb = new StringBuilder();
            int N = Integer.parseInt(br.readLine());
            ans = 0;
 
            int[] weight;
            boolean[] isSelected;
 
            weight = new int[N];
            isSelected = new boolean[N];
 
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++)
                weight[i] = Integer.parseInt(st.nextToken());
 
            startSimulation(0, 0, 0, isSelected, weight, N);
 
            sb.append("#" + t + " " + ans);
            System.out.println(sb.toString());
        }
    }
 
}