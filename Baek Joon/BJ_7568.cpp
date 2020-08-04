//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<pair<int, int>> wh;
//	for (int i = 0; i < n; i++) {
//		int weight;
//		int height;
//		cin >> weight >> height;
//		wh.push_back(make_pair(weight, height));
//	}
//
//	for (int i = 0; i < n; i++) {
//		int cnt = 0;
//		for (int j = 0; j < n; j++) {
//			if (wh[i].first < wh[j].first && wh[i].second < wh[j].second)
//				cnt++;
//		}
//		cout << cnt+1 << " ";
//	}
//}