//
// Created by Macintosh on 2023/7/16.
//
#include "../status_def.h"

#define MAX_SIZE 20

typedef struct Node { /* 声明结点的类型和指向结点的指针类型 */
    ElemType data; /* 结点的数据域 */
    struct Node *next; /* 结点的指针域 */
} Node, *LinkList; /* LinkList为指向结构体Node的指针类型 */

Status visit(ElemType c) {
    printf("%d ", c);
    return OK;
}

/* 初始化链式线性表 */
Status InitList(LinkList *L) {
    /* 产生头结点,并使L指向此头结点 */
    *L = (LinkList) malloc(sizeof(Node));
    if (!(*L)) return ERROR; /* 分配失败 */
    (*L)->next = NULL; /* 指针域未空 */

    return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L) {
    if (L->next) return FALSE;
    else return TRUE;
}



int main() {
    return 0;
}