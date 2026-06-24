#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int fact(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fact(n - 1);
}

int main() {
    int N; // 소의 수 N
    cin >> N;

    vector<int> cow(N); // 소의 번호
    for (int i = 0; i < N; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int start = cow[i];
        for (int j = i + 1; j < N; j++) {
            int mid = cow[j];
            for (int k = j + 1; k < N; k++) {
                int end = cow[k];
                if ((end - mid >= mid - start) && ((2 * (mid - start)) >= (end - mid))) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
/**************************************************************
    Problem: 1673
    User: john4573 [뫄이]
    Language: C++
    Result: 모두 맞음
    Time:124 ms
    Memory:2152 kb
****************************************************************/
