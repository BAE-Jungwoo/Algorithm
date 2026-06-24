#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (100 + 2)
typedef struct _node {
    int row, col;
} node;

node queue[MAX_N * MAX_N * 10];
int front, rear;

void enqueue(node data) {
    queue[rear++] = data;
}

node dequeue(void) {
    return queue[front++];
}

int mat[MAX_N][MAX_N];  // 산의 지형 정보
int cost[MAX_N][MAX_N]; // 각 지점까지의 최소비용(걸림 힘)
int N;                  // 산의 크기
int tRow, tCol;         // 산의 꼭대기 위치

void input_data(void) {
    (void)scanf("%d %d %d", &N, &tRow, &tCol);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            (void)scanf("%d", &mat[i][j]);
        }
    }
    memset(cost, 0x0F, sizeof(cost));
}

void print_data(int (*arr)[MAX_N], int s, int e) {
    for (int i = s; i <= e; ++i) {
        for (int j = s; j <= e; ++j) {
            if (arr[i][j] == 0x0F0F0F0F) {
                printf(" - ");
            }
            else {
                printf("%2d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

//큐 생성, 테두리 0으로 만들기 그리고 큐에 넣기
void init_queue() {
    front = rear = 0;
    for (int i = 1; i <= N; ++i) {
        enqueue((node) { 1, i });   // 위쪽
        cost[1][i] = mat[1][i] * mat[1][i];
        enqueue((node) { N, i });   // 아래쪽
        cost[N][i] = mat[N][i] * mat[N][i];
    }

    for (int i = 2; i < N; ++i) {
        enqueue((node) { i, 1 });   // 왼쪽, 모서리 제외
        cost[i][1] = mat[i][1] * mat[i][1];
        enqueue((node) { i, N });   // 오른쪽, 모서리 제외
        cost[i][N] = mat[i][N] * mat[i][N];
    }
}

int dR[] = { -1,1,0,0 };
int dC[] = { 0,0,-1,1 };

void mount_BFS(void) {
    node curr = { 0 };
    int cR, cC, nR, nC;
    while (front != rear) {
        curr = dequeue();
        cR = curr.row;
        cC = curr.col;

        for (int i = 0; i < 4; i++) {
            nR = cR + dR[i];
            nC = cC + dC[i];
            if (mat[nR][nC] == 0) continue;

            int nextCost;
            int diff = mat[nR][nC] - mat[cR][cC];

            if (mat[nR][nC] > mat[cR][cC])
                nextCost = cost[cR][cC] + diff * diff;
            else
                nextCost = cost[cR][cC] - diff;

            if (cost[nR][nC] > nextCost) {
                cost[nR][nC] = nextCost;
                enqueue((node) { nR, nC });
            }
        }
    }
}

int main(void) {
    // (void)freopen("quiz_Q.txt", "r", stdin);
    input_data();
    // print_data(mat, 1, N);
    // print_data(cost, 0, N + 1);
    init_queue();
    // print_data(cost, 0, N + 1);

    mount_BFS();

    printf("%d\n", cost[tRow][tCol]);
    return 0;
}
/**************************************************************
    Problem: 1669
    User: john4573 [뫄이]
    Language: C
    Result: 모두 맞음
    Time:1 ms
    Memory:2028 kb
****************************************************************/
