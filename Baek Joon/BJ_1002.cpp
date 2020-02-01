#include <iostream>
#include <cmath>
using namespace std;

double distance(int x1, int y1, int x2, int y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int sum(int r1, int r2)
{
	if (r1 > r2)
		return  r1 - r2;
	else
		return r2 - r1;
}

int point(double k, int r, int R)
{
	if (r < k&&k < R)
		return 2;
	else if (k == R || k == r)
		return 1;
	else
		return 0;
}

int main(void)
{
	int T;
	int x1, x2, y1, y2, r1, r2;
	int r, R;
	double k;

	cin >> T;
	int *ptr = new int[T];
	for (int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2 && r1 == r2)
			ptr[i] = -1;
		else
		{
			k = distance(x1, y1, x2, y2);
			r = sum(r1, r2);
			R = r1 + r2;
			ptr[i] = point(k, r, R);
		}
	}

	for (int i = 0; i < T; i++)
		cout << ptr[i] << endl;

	delete ptr;

	return 0;
}