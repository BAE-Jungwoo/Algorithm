#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int list[102][102] = { 0 };
int degree[102] = { 0 };
int visited[102] = { 0 };
int cnt = 0;

void dfs(int curr) {
    visited[curr] = 1;

    for (int i = 1; i <= degree[curr]; i++) {
        int next = list[curr][i];

        if (visited[next] == 0) {
            cnt++;
            dfs(next);
        }
    }
}

int main() {
    // (void)freopen("quiz_H.txt", "r", stdin);
    int V, E; // 컴퓨터의 수, 연결되어 있는 컴퓨터 쌍의 수
    (void)scanf("%d %d", &V, &E);

    int a, b;
    for (int i = 1; i <= E; i++) {
        (void)scanf("%d %d", &a, &b);
        list[a][degree[a] + 1] = b;
        degree[a]++;

        list[b][degree[b] + 1] = a;
        degree[b]++;
    }

    for (int i = 1; i <= V; i++) {
        list[i][0] = degree[i];
    }
    /*
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j <= V;j++) {
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */
    dfs(1);
    printf("%d", cnt);

    return 0;
}
/**************************************************************
    Problem: 1662
    User: john4573 [뫄이]
    Language: C
    Result: 모두 맞음
    Time:0 ms
    Memory:1176 kb
****************************************************************/
