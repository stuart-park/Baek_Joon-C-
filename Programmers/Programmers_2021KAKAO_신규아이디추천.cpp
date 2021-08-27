#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    //1단게
    for (int i = 0; i < new_id.size(); i++) 
        if (new_id[i] >= 65 && new_id[i] <= 90)
            new_id[i] = new_id[i] + 32;

    //2단계
    for (int i = 0; i < new_id.size(); i++)
        if (new_id[i] == '-' || new_id[i] == '_'  || new_id[i] == '.'||(new_id[i] >= 97 && new_id[i] <= 122) || (new_id[i] >= 48 && new_id[i] <= 57))
            temp += new_id[i];
       
    //3단계
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '.') {
            answer += temp[i];
            int j = i + 1;
            while (true) {
                if (temp[i] != temp[j]) {
                    j--;
                    break;
                }
                else
                    j++;
            }
            i = j;
        }
        else
            answer += temp[i];
    }
     
    //4단계
    if (answer[0] == '.')
        answer = answer.substr(1, answer.size());
    if (answer[answer.size() - 1] == '.')
        answer = answer.substr(0, answer.size() - 1);
        
    //5단계
    if (answer.size() == 0)
        answer += "a";

    //6단계
    if (answer.size() >= 16) {
        if (answer[14] == '.')
            answer = answer.substr(0, 14);
        else
            answer = answer.substr(0, 15);
    }

    //7단계
    while (answer.size() <= 2)
        answer += answer[answer.size() - 1];
 
    return answer;
}

int main() {
    string ans = solution("z-+.^.");
    cout << ans;
}