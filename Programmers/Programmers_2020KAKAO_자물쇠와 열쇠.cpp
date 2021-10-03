#include <string>
#include <vector>

using namespace std;

int N, M;
int d1[] = { 0, 0, 1, 0 };
int d2[] = { 0, 0, 0, -1 };
int d3[] = { 0, 1, 0, 0 };
int d4[] = { -1, 0, 0, 0 };
int d5[] = { 0, 0, -1, 1 };
int d6[] = { 1, -1,0, 0 };
vector<vector<int>> lock;

bool isKey(int key[][20]) {
    for(int i=0;i<)
}

bool findKey(vector<vector<int>> key) {
    for (int i = 0; i < 4; i++) {
        int temp_key[20][20];

        for (int j = 0; j < M; j++)
            for (int k = 0; k < M; k++)
                temp_key[j][k] = 0;

        for (int p = 0 + d1[i]; p < M + d2[i]; p++)
            for (int q = 0 + d3[i]; q < M + d4[i]; q++)
                temp_key[p + d5[i]][q + d6[i]] = key[p][q];

        if (isKey(temp_key))
            return true;
    }
    
    return false;
}

vector<vector<int>> rotate(vector<vector<int>> key) {
    vector<vector<int>> temp;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            temp[i][j] = key[M - j - 1][i];

    return temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> l) {
    lock = l;

    M = key.size();
    N = lock.size();

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            key[i][j] = key[i][j] == 1 ? 0 : 1;

    bool answer = true;
    return answer;
}