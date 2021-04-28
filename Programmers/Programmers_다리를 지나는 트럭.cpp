#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int i = 1, cur_weight = 0, answer = 0;
    queue<int> bridge;
    bridge.push(truck_weights[0]);
    cur_weight += truck_weights[0];
    answer++;

    while (!bridge.empty()) {
        if (i == truck_weights.size()) {
            answer = answer + bridge_length;
            break;
        }
        if (bridge.size() == bridge_length) {
            cur_weight -= bridge.front();
            bridge.pop();
        }
        if (cur_weight + truck_weights[i] <= weight && i < truck_weights.size()) {
            bridge.push(truck_weights[i]);
            cur_weight += truck_weights[i];
            i++;
        }
        else if (i < truck_weights.size())
            bridge.push(0);
        answer++;
    }

    return answer;
}