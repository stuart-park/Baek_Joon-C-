import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class JUNGOL_2577 {
	private static int N, d, k, c;
	private static int[] plates;
	private static int[] num;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());

		plates = new int[N];
		num = new int[d + 1];

		int ans = 0;
		int cnt = 0;
		boolean flag = false;
		for (int i = 0; i < N + k - 1; i++) {
			if (i < N)
				plates[i] = Integer.parseInt(br.readLine());

			if (i >= k) {
				num[plates[i - k]]--;
				if (num[plates[i - k]] == 0)
					cnt--;
			}

			if (num[plates[i % N]] == 0)
				cnt++;
			
			num[plates[i % N]]++;

			if (num[c] == 0) {
				cnt++;
				flag = true;
			}

			if (ans < cnt)
				ans = cnt;

			if (flag) {
				cnt--;
				flag = false;
			}
		}

		System.out.println(ans);
	}
}
