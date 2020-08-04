//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//
//int main() {
//	int N, M;
//	cin >> N >> M;
//	vector<int> card(N);
//	for (int i = 0; i < N; i++)
//		cin >> card[i];
//
//	int result = 0;
//	int ans = 0;
//	for (int i = 0; i < N-2; i++) {
//		for (int j = i + 1; j < N-1; j++) {
//			for (int k = j + 1; k < N; k++) {
//				result = card[i] + card[j] + card[k];
//				if (M >= result&&result > ans)
//					ans = result;
//			}
//		}
//	}
//
//	cout << ans << endl;
//}