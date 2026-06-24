#include <iostream>
using namespace std;

int paper[101][101] = { 0 };

int main() {
    int n, x, y;
    int cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                if (paper[j][k] == 0) {
                    cnt++;
                    paper[j][k] = 1;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
/**************************************************************
    Problem: 1674
    User: john4573 [뫄이]
    Language: C++
    Result: 모두 맞음
    Time:0 ms
    Memory:2192 kb
****************************************************************/
