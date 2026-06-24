#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, d, k, c; // 접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
    cin >> N >> d >> k >> c;

    vector<int> sushi(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    vector<int> check(d + 1, 0);
    int type = 0, maxCnt = 0, coupon = 1;
    for (int i = 0; i < k; i++) {
        if (check[sushi[i]] == 0)
            type++; // 처음 k개 세팅

        check[sushi[i]]++;
    }

    for (int i = 0; i < N; i++) {
        int coupon = 0;
        if (check[c] == 0)
            coupon = 1;

        maxCnt = max(maxCnt, type + coupon);

        // 맨 앞 초밥 제거
        check[sushi[i]]--;
        if (check[sushi[i]] == 0)
            type--;

        // 새로 들어오는 초밥 추가
        int next = sushi[(i + k) % N];
        if (check[next] == 0)
            type++;
        check[next]++;
    }
    cout << maxCnt;
    return 0;
}
/**************************************************************
    Problem: 1677
    User: john4573 [뫄이]
    Language: C++
    Result: 모두 맞음
    Time:406 ms
    Memory:14032 kb
****************************************************************/
