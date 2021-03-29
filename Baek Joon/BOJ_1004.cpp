#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int T;
	int x1, y1, x2, y2;
	int n;
	double k1, k2;
	int c1[50], c2[50], r[50];

	cin >> T;
	int *a = new int[T];
	for (int i = 0; i < T; i++)
		a[i] = 0;

	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> c1[j] >> c2[j] >> r[j];
			k1 = sqrt((x1 - c1[j])*(x1 - c1[j]) + (y1 - c2[j])*(y1 - c2[j]));
			k2 = sqrt((x2 - c1[j])*(x2 - c1[j]) + (y2 - c2[j])*(y2 - c2[j]));
			if (k1 < r[j] || k2 < r[j])
				a[i]++;
			if (k1 < r[j] && k2 < r[j])
				a[i]--;
		}
	}

	for (int i = 0; i < T; i++)
		cout << a[i] << endl;

	delete[]a;
	return 0;
}