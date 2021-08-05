#include <iostream>
using namespace std;

int switches[100];
int students[100][2];

int main() {
	std::ios_base::sync_with_stdio(false);	

	int switch_num, student_num;
	cin >> switch_num;

	for (int i = 0; i < switch_num; i++) 
		cin >> switches[i];

	cin >> student_num;
	for (int i = 0; i < student_num; i++)
		cin >> students[i][0] >> students[i][1];

	//solve()
	for (int i = 0; i < student_num; i++) {
		if (students[i][0] == 1) {
			for (int j = 0; j < switch_num; j++) {
				if ((j+1) % students[i][1] == 0)
					switches[j] == 0 ? switches[j] = 1 : switches[j] = 0;
			}
		}
		else if (students[i][0] == 2) {
			int cur_pos = students[i][1] - 1;
			int n = 1;
			switches[cur_pos] == 0 ? switches[cur_pos] = 1 : switches[cur_pos] = 0;
			while (1) {
				if (cur_pos- n < 0 || cur_pos + n >= switch_num || switches[cur_pos-n] != switches[cur_pos+n])
					break;
				else if (switches[cur_pos - n] == switches[cur_pos + n]) {
					switches[cur_pos - n] == 0 ? switches[cur_pos - n] = 1 : switches[cur_pos - n] = 0;
					switches[cur_pos + n] == 0 ? switches[cur_pos + n] = 1 : switches[cur_pos + n] = 0;
					n++;
				}
			}
		}
	}

	for (int i = 0; i < switch_num; i++) {
		if ((i + 1) % 20 == 0) {
			cout << switches[i];
			cout << "\n";
		}
		else
			cout << switches[i] << " ";
	}
}