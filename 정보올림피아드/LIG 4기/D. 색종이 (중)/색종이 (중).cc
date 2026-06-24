#include <iostream>
using namespace std;

int paper[102][102] = { 0 };

int main() {
    int num;
    int x, y;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> x >> y;
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                paper[j][k] = 1;
            }
        }
    }

    int len = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (paper[i][j] == 1) {
                if (i == 0 || paper[i - 1][j] == 0) len++;
                if (paper[i + 1][j] == 0) len++;
                if (j == 0 || paper[i][j - 1] == 0) len++;
                if (paper[i][j + 1] == 0) len++;
            }
        }
    }
    cout << len;
    return 0;
}
/**************************************************************
    Problem: 1675
    User: john4573 [뫄이]
    Language: C++
    Result: 모두 맞음
    Time:0 ms
    Memory:2192 kb
****************************************************************/
