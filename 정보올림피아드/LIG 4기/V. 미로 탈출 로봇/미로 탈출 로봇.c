#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (100+2)
typedef struct _node {
    int r, c;
    int dist;
}node;

node queue[MAX_N * MAX_N];
int front, rear;

void enqueue1(int r, int c, int dist) {
    queue[rear].r = r;
    queue[rear].c = c;
    queue[rear++].dist = dist;
}
void enqueue(node data) {
    queue[rear++] = data;
}

node dequeue(void) {
    return queue[front++];
}

int mat[MAX_N][MAX_N] = { 0 };
int C, R;
int sC, sR, eC, eR;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void input_data(void) {
    char temp[MAX_N];
    (void)scanf("%d %d %d %d %d %d", &C, &R, &sC, &sR, &eC, &eR);
    for (int i = 1; i <= R; ++i) {
        (void)scanf("%s", temp + 1);
        for (int j = 1; j <= C; ++j) {
            mat[i][j] = !(temp[j] - '0');
        }
    }
}

void print_data(void) {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            printf("%2d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int miro_BFS(int sR, int sC) {
    node curr = { 0 };
    int nR, nC;

    front = rear = 0;  // Q 초기화
    enqueue((node) { sR, sC, 0 });  // 시작점을 Q에 넣기
    mat[sR][sC] = 2;  // 방문표시 (2 → 3 → 4 ....)

    while (front != rear) {
        curr = dequeue();
        if (curr.r == eR && curr.c == eC) {
            return curr.dist;
        }
        for (int i = 0; i < 4; ++i) {
            nR = curr.r + dr[i];
            nC = curr.c + dc[i];
            if (mat[nR][nC] == 1) {
                enqueue((node) { nR, nC, curr.dist + 1 });
                mat[nR][nC] = mat[curr.r][curr.c] + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    // (void)freopen("quiz_V.txt", "r", stdin);
    int result;
    input_data();
    // print_data();
    result = miro_BFS(sR, sC);
    printf("%d\n", result);
    // print_data();
    return 0;
}
/**************************************************************
    Problem: 1708
    User: john4573 [뫄이]
    Language: C
    Result: 모두 맞음
    Time:0 ms
    Memory:1296 kb
****************************************************************/
