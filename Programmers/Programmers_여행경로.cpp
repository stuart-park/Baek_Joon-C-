#include <string>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void dfs(string s, vector<bool> &visit, vector<string> &answer, vector<vector<string>> &tickets, int pos) {
	answer.push_back(s);
	visit[pos] = true;

	for (int i = 0; i < tickets.size(); i++) {
		if (s == tickets[i][0] && visit[i] == false) {
			dfs(tickets[i][1], visit, answer, tickets, i);
		}
	}

	if (answer.size() == tickets.size() + 1)
		return;

	answer.pop_back();
	visit[pos] = false; //back-tracking

}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> visit(tickets.size());
	sort(tickets.begin(), tickets.end());
	answer.push_back("ICN");
	for (int i = 0; i < tickets.size(); i++)
		if (tickets[i][0] == "ICN" && visit[i] == false) {
			dfs(tickets[i][1], visit, answer, tickets, i);
		}
	return answer;
}

int main() {
	vector<vector<string>> tickets = { {"ICN","COO"},{"ICN","COO"},{"COO","DOO"},{"COO","ICN"} };
	vector<string> temp = solution(tickets);
	for (int i = 0; i < temp.size(); i++)
		cout << temp[i] << " ";
}