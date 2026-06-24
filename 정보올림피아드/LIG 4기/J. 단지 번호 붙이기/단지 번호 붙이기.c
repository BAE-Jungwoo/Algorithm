#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 25

int map[MAX][MAX] = { 0 };      // 지도
int visited[MAX][MAX] = { 0 };  // 방문 여부

int dr[4] = { -1,1,0,0 };       // -1: 상, 1: 하
int dc[4] = { 0,0,-1,1 };       // -1: 좌, 1: 우

int degree[MAX * MAX / 2] = { 0 };
int cnt = 0;                    // 단지의 수
int houseCnt = 0;               // 단지 내 집의 수

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void block(int row, int col, int N) {
    visited[row][col] = 1;
    houseCnt++;

    for (int i = 0; i < 4; ++i) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        // 범위 밖
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

        // 집이 아니면
        if (map[nr][nc] == 0) continue;

        // 이미 방문했으면
        if (visited[nr][nc] == 1) continue;

        block(nr, nc, N);
    }
}

int main() {
    int N;
    (void)scanf("%d", &N);

    for (int i = 0; i < N; i++) {    // 문자열로 읽어도 됨
        for (int j = 0; j < N;j++) {
            (void)scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                houseCnt = 0;
                block(i, j, N);
                degree[cnt++] = houseCnt;
            }
        }
    }
    qsort(degree, cnt, sizeof(int), compare);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d\n", degree[i]);
    return 0;
}
/**************************************************************
    Problem: 1658
    User: john4573 [뫄이]
    Language: C
    Result: 모두 맞음
    Time:0 ms
    Memory:1140 kb
****************************************************************/
