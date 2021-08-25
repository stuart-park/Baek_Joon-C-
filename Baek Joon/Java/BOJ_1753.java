package com.ssafy.algo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_1753 {
	private static int V, E;
	private static int[] dist;
	private static List<Pair>[] list;

	private static class Pair implements Comparable<Pair> {
		int first;
		int second;

		Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}

		@Override
		public int compareTo(Pair o) {
			if (this.first >= o.first)
				return 1;
			return -1;
		}

	}

	private static void dijkstra(int v) {
		for (int i = 1; i <= V; i++)
			dist[i] = Integer.MAX_VALUE;

		dist[v] = 0;
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(dist[v], v));

		while (!pq.isEmpty()) {
			int cur_vertex = pq.peek().second;
			int cur_dist = pq.peek().first;

			pq.poll();
			
			if(dist[cur_vertex] != cur_dist)
				continue;

			for (int i = 0; i < list[cur_vertex].size(); i++) {
				int next_vertex = list[cur_vertex].get(i).second;
				int next_dist = cur_dist + list[cur_vertex].get(i).first;
				if (dist[next_vertex] > next_dist) {
					dist[next_vertex] = next_dist;
					pq.add(new Pair(next_dist, next_vertex));
				}
			}
		}

	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();

		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());

		dist = new int[V + 1];
		list = new ArrayList[V + 1];

		for (int i = 0; i < V + 1; i++)
			list[i] = new ArrayList<>();

		int startVertex = Integer.parseInt(br.readLine());

		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			list[u].add(new Pair(w, v));
		}

		dijkstra(startVertex);

		for (int i = 1; i <= V; i++) {
			if (dist[i] == Integer.MAX_VALUE)
				sb.append("INF\n");
			else
				sb.append(dist[i] + "\n");
		}
		
		System.out.println(sb.toString());
	}

}
