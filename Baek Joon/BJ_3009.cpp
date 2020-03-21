#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> d >> b >> e >> c >> f;
	int x = a == b ? c : a == c ? b : a;
	int y = d == e ? f : d == f ? e : d;
	cout << x << ' ' << y << endl;
}


//#include <iostream>
//using namespace std;
//
//int main() {
//	int arr[2][3];
//	int ans[2];
//	int cnt1 = 0, cnt2 = 0;
//
//	for (int i = 0; i < 3; i++)
//		for (int j = 0; j < 2; j++)
//			cin >> arr[i][j];
//
//	for (int i = 1; i < 3; i++) {
//		if (arr[0][0] == arr[i][0])
//			cnt1++;
//		if (arr[0][1] == arr[i][1])
//			cnt2++;
//	}
//
//	if (cnt1 == 0)
//		ans[0] = arr[0][0];
//	else
//		for (int i = 1; i < 3; i++)
//			if (arr[0][0] != arr[i][0])
//				ans[0] = arr[i][0];
//
//	if (cnt2 == 0)
//		ans[1] = arr[0][1];
//	else
//		for (int i = 1; i < 3; i++)
//			if (arr[0][1] != arr[i][1])
//				ans[1] = arr[i][1];
//
//	cout << ans[0] << ' ' << ans[1] << endl;
//}