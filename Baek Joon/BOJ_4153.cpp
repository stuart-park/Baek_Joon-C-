#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;

		if (a*a + b * b + c * c == 2 * max({ a*a, b*b, c*c }))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
}


//#include <iostream>
//using namespace std;
//
//int main() {
//	int a, b, c;
//	while (1) {
//		cin >> a >> b >> c;
//
//		if (a == 0 && b == 0 && c == 0)
//			break;
//
//		if ((c*c) == (a*a) + (b*b))
//			cout << "right" << endl;
//		else if((a*a) == (c*c) + (b*b))
//			cout << "right" << endl;	
//		else if ((b*b) == (c*c) + (a*a))
//			cout << "right" << endl;
//		else 
//			cout << "wrong" << endl;
//	}
//}