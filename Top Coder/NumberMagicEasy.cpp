#include <iostream>
#include <string>
using namespace std;

class NumberMagicEasy {
public:
	int theNumber(string answer) {
		string card[16] = { "YYYY","YYYN","YYNY","YYNN", "YNYY", "YNYN", "YNNY", "YNNN", "NYYY", "NYYN", "NYNY", "NYNN", "NNYY", "NNYN", "NNNY", "NNNN" };

		for (int i = 0; i < 16; i++)
			if (card[i] == answer)
				return i + 1;
	}
};

int main() {
	NumberMagicEasy a;
	string b = "YNYY";
	int c=a.theNumber(b);
	cout << c;
}