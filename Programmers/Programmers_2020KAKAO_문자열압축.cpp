#include <string>
#include <vector>
#include <iostream>

int a = 1000000;
using namespace std;

void startZip(string s, int size) {
    string ans = "";

    int cnt = 1;
    string start = s.substr(0, size);
    for (int i = size; i < s.size(); i+=size) {
        string subString = s.substr(i, size);
        if (start != subString) {
            if (cnt == 1)
                ans = ans + start;
            else
                ans = ans + to_string(cnt) + start;
            cnt = 1;
            start = subString;
        }
        else
            cnt++;
    }
    if (cnt == 1)
        ans = ans + start;
    else
        ans = ans + to_string(cnt) + start;

    if (ans.size() < a)
        a = ans.size();
}

int solution(string s) {
    for (int i = 1; i <= s.size(); i++) 
        startZip(s, i);

    int answer = a;
    return answer;
}