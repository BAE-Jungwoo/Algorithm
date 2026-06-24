#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 15

int N, cnt;
int col[MAX_N];
int up[MAX_N * 2];
int down[MAX_N * 2];

// Queen을 L번째 행에 배치
void queenDFS(int L) {
    if (L > N) {
        cnt++;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (col[i] == 0 && up[L + i] == 0 && down[L - i + N] == 0) {
            col[i] = up[L + i] = down[L - i + N] = 1;
            queenDFS(L + 1);
            col[i] = up[L + i] = down[L - i + N] = 0;
        }
    }
}


int main() {
    (void)scanf("%d", &N);
    cnt = 0;
    queenDFS(1);
    printf("%d", cnt);
    return 0;
}
/**************************************************************
    Problem: 1660
    User: john4573 [뫄이]
    Language: C
    Result: 모두 맞음
    Time:82 ms
    Memory:1136 kb
****************************************************************/
