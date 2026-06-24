#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 600001
#define MAX_ARR 600001

int N;

typedef char ElementType_LL;
typedef struct _node_DLL {
    ElementType_LL data;
    struct _node_DLL* prev;
    struct _node_DLL* next;
} node_LL;

node_LL* Create_NodeLL(ElementType_LL data) {
    node_LL* newNode = NULL;
    newNode = (node_LL*)malloc(sizeof(node_LL));
    if (newNode == NULL) {
        printf("Leak of memory!\n");
        exit(2);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void init_HT(node_LL** head, node_LL** tail) {
    *head = Create_NodeLL('0');
    *tail = Create_NodeLL('0');
    (*head)->next = (*tail);
    (*tail)->prev = (*head);
}

static void Insert_NodeLL(node_LL* prevNode, node_LL* newNode, node_LL* nextNode) {
    newNode->prev = prevNode;
    newNode->next = nextNode;
    prevNode->next = newNode;
    nextNode->prev = newNode;
}

// tnode - newNode - tnode ->next
void InsertAfter(node_LL* tNode, node_LL* newNode) {
    Insert_NodeLL(tNode, newNode, tNode->next);
}

// tnode->prev - newNode - tnode
void InsertBefore(node_LL* tNode, node_LL* newNode) {
    Insert_NodeLL(tNode->prev, newNode, tNode);
}

void Delete_NodeLL(node_LL* snode) {
    snode->prev->next = snode->next;
    snode->next->prev = snode->prev;
}

void print_NodeLL(node_LL* head, node_LL* tail) {
    char* arr = (char*)calloc(MAX_ARR + 1, sizeof(char));
    if (arr == NULL) return;
    int i = 0;
    for (node_LL* curr = head->next; curr != tail; curr = curr->next) {
        arr[i++] = curr->data;
    }
    printf("%s\n", arr);
    free(arr);
}

int main() {
    char* temp = (char*)malloc(sizeof(char) * MAX_N);
    if (temp == NULL) return;
    node_LL* head, * tail;
    init_HT(&head, &tail);

    (void)scanf("%s", temp);
    for (int i = 0; temp[i] != '\0'; i++) {
        InsertBefore(tail, Create_NodeLL(temp[i]));
    }

    node_LL* cursor = tail;
    (void)scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char txt;
        (void)scanf(" %c", &txt);
        if (txt == 'L' && cursor->prev != head) {    // 커서를 한 문자 왼쪽으로 이동
            cursor = cursor->prev;
        }
        else if (txt == 'D' && cursor != tail) {    // 커서를 한 문자 오른쪽으로 이동
            cursor = cursor->next;
        }
        else if (txt == 'B' && cursor->prev != head) {   // 커서 왼쪽의 문자를 삭제
            Delete_NodeLL(cursor->prev);
        }
        else if (txt == 'P') {  // 커서 왼쪽에 문자 $를 추가
            char ch;
            (void)scanf(" %c", &ch);
            InsertBefore(cursor, Create_NodeLL(ch));
        }
    }
    print_NodeLL(head, tail);
    free(temp);
    return 0;
}
/**************************************************************
    Problem: 1019
    User: john4573 [뫄이]
    Language: C
    Result: 모두 맞음
    Time:51 ms
    Memory:9572 kb
****************************************************************/
