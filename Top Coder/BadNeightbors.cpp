#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

class BadNeightbors {
public: 
	int maxDonations(vector<int> donations) {
		int n = donations.size();
		vector<int> temp1;
		vector<int> temp2;

		for (int i = 0; i < n - 1; i++) {
			if (i == 0) temp1.push_back(donations[i]);
			else if (i == 1) temp1.push_back(donations[i]);
			else if (i == 2) temp1.push_back(temp1[0] + donations[i]);
			else temp1.push_back(max(temp1[i - 2] + donations[i], temp1[i - 3] + donations[i]));
		}

		for (int i = 1; i < n; i++) {
			if (i == 1) temp2.push_back(donations[i]);
			else if (i == 2) temp2.push_back(donations[i]);
			else if (i == 3) temp2.push_back(temp2[0] + donations[i]);
			else temp2.push_back(max(temp2[i - 3] + donations[i], temp2[i - 4] + donations[i]));

		}
		return max(temp1.back(), temp2.back());
	}
};


int main() {
	BadNeightbors bn;
	vector <int> k = {  };
	int a=bn.maxDonations(k);
	cout << a;
}