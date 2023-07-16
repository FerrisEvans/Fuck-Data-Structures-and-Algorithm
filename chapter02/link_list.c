//
// Created by Macintosh on 2023/7/16.
//
#include "../status_def.h"

typedef struct Lnode { /* 声明结点的类型和指向结点的指针类型 */
    ElemType data; /* 结点的数据域 */
    struct Lnode *next; /* 结点的指针域 */
} Lnode, *LinkList; /* LinkList为指向结构体Lnode的指针类型 */

int main() {
    return OK;
}