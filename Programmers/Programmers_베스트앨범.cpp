#include <string>
#include <vector>
#include <iostream>

using namespace std;


void sort(vector<pair<string, int>> & genresType) {
	vector<pair<string, int>> temp(1);
	for (int i = 0; i < genresType.size() - 1; i++) {
		for (int j = i+1; j < genresType.size(); j++) {
			if (genresType[i].second < genresType[j].second) {
				temp[0] = genresType[i];
				genresType[i] = genresType[j];
				genresType[j] = temp[0];
			}
		}
	}
}

bool hasType(int pos, string temp, vector<pair<string,int>> & genersType, vector<int> & plays ) {
	for (int i = 0; i < genersType.size(); i++)
		if (genersType[i].first == temp) {
			genersType[i].second += plays[pos];
			return true;
		}
	return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	vector<pair<string, int>> genresType;
	genresType.push_back(make_pair(genres[0], plays[0]));
	for (int i = 1; i < genres.size(); i++)
		if (!hasType(i, genres[i], genresType, plays))
			genresType.push_back(make_pair(genres[i], plays[i]));

	sort(genresType);

	for (int i = 0; i < genresType.size(); i++) {
		vector<int> tempNum;
		for (int j = 0; j < genres.size(); j++)
			if (genresType[i].first == genres[j])
				tempNum.push_back(j);

		for (int j = 0; j < tempNum.size() - 1; j++) {
			for (int k = j+1; k < tempNum.size(); k++) {
				if (plays[tempNum[j]] < plays[tempNum[k]]) {
					int temp = tempNum[k];
					tempNum[k] = tempNum[j];
					tempNum[j] = temp;
				}
				else if (plays[tempNum[j]] == plays[tempNum[k]] && tempNum[j] > tempNum[k]) {
					int temp = tempNum[k];
					tempNum[k] = tempNum[j];
					tempNum[j] = temp;
				}
			}
		}

		if (tempNum.size() == 1)
			answer.push_back(tempNum[0]);
		else
			for (int j = 0; j < 2; j++)
				answer.push_back(tempNum[j]);
	}
	 
	return answer;
}

//int main() {
//	vector<string> genres = {"A","B","A" ,"A" ,"B"};
//	vector<int> plays = {500, 600, 150, 800, 2500};
//	vector<int> answer = solution(genres, plays);
//	for (int i = 0; i < answer.size(); i++)
//		cout << answer[i] << " ";
//}