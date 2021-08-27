#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<char> menus;
vector<char> selectedMenu;
vector<pair<int, string>> max_menu;
bool isSelected[26];
int max_order = 0;

void countOrder(vector<string> orders) {
    int order = 0;

    for (int i = 0; i < orders.size(); i++) {
        if (selectedMenu.size()> orders[i].size())
            continue;

        int cnt = 0;
        for (int j = 0; j < selectedMenu.size(); j++) {
            for (int k = 0; k < orders[i].size(); k++) {
                if (orders[i][k] == selectedMenu[j]) {
                    cnt++;
                    break;
                }
            }
            if (j >= cnt)
                break;
        }
        if (cnt == selectedMenu.size())
            order++;
    }

    if (order < 2)
        return;

    vector<char> tmpMenu;
    for (int i = 0; i < selectedMenu.size(); i++)
        tmpMenu.push_back(selectedMenu[i]);

    if (max_order <= order) {
        max_order = order;
        string course = "";
        sort(tmpMenu.begin(), tmpMenu.end());
        for (int i = 0; i < tmpMenu.size(); i++)
            course += tmpMenu[i];
        max_menu.push_back(make_pair(order, course));
    }
}

void makeCourse(int idx, int cnt, int N, vector<string> orders) {
    if (cnt == N) {
        countOrder(orders);
        return;
    }

    for (int i = idx; i < menus.size(); i++) {
        selectedMenu.push_back(menus[i]);
        makeCourse(i + 1, cnt + 1, N, orders);
        selectedMenu.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++)
        for (int j = 0; j < orders[i].size(); j++) {
            if (!isSelected[orders[i][j] - 'A']) {
                isSelected[orders[i][j] - 'A'] = true;
                menus.push_back(orders[i][j]);
            }
        }

    for (int num : course) {
        max_order = 0;
        selectedMenu.clear();
        max_menu.clear();

        makeCourse(0, 0, num, orders);

        if (max_order < 2)
            continue;

        for (pair<int, string> menu : max_menu)
            if (max_order == menu.first)
                answer.push_back(menu.second);
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    vector<string> orders = { "ABCDEF", "GHIJKL" ,"MNOPQRS" ,"TUVWXYZ" ,"ABCDE" };
    vector<int> course = { 2 };
    vector<string> ans = solution(orders, course);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}