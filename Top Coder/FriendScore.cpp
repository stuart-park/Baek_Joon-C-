#include <vector>
#include <iostream>
#include <string>
#include  <algorithm>

using namespace std;

class FriendScore {
public:
	int highestScore(vector <string> friends) {
		int num = friends.size();
		vector <int> ans;
		vector<vector<bool>> update(num, vector<bool>(num, false));
		for (int i = 0; i < num; i++)
			for (int j = 0; j < num; j++) {
				if (friends[i].at(j) == 'Y' && update[i][j] == false)
					for (int k = 0; k < num; k++)
						if ((i != k) && (friends[j].at(k) == 'Y') && (update[j][k] == false) && (friends[i].at(k) != 'Y')) {
							friends[i].at(k) = 'Y';
							update[i][k] = true;
						}
			}
		for (int i = 0; i < num; i++) {
			int temp = 0;
			for (int j = 0; j < num; j++) {
				if (friends[i].at(j) == 'Y')
					temp += 1;
			}
			ans.push_back(temp);
		}
		sort(ans.begin(), ans.end());
		return ans[num-1];
	}
};