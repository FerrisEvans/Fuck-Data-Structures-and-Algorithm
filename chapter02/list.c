//
// Created by Macintosh on 2023/7/8.
//
#include "../status_def.h"

#define LIST_INIT_SIZE 100 /* 线性表存储空间的初始分配量 */


typedef int ElemType;
typedef int Status;
typedef struct {
    ElemType elem[LIST_INIT_SIZE];
    int length;
} SqList; /* Sequence List */

Status visit(ElemType);

/* 初始化顺序线性表 */
Status InitList(SqList *L);

/* 销毁已经存在的线性表L */
Status DestroyList(SqList *L);

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L);

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L);

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L);
/* 初始条件：顺序线性表L已存在，1 ≤ i ≤ ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L, int i, ElemType *e);
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L, ElemType e);
/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L, int i, ElemType e);
/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L, int i, ElemType *e);
/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L);

/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void unionL(SqList *La, SqList Lb);

int main() {

    return 0;
}

Status visit(ElemType c) {
    printf("<%d> ", c);
    return OK;
}

Status InitList(SqList *L) {
    L->length = 0;
    return OK;
}

Status DestroyList(SqList *L) {
    free(L);
    return OK;
}

Status ListEmpty(SqList L) {
    if (L.length == 0) return TRUE;
    return FALSE;
}

Status ClearList(SqList *L) {
    L->length = 0;
    return OK;
}

int ListLength(SqList L) {
    return L.length;
}

Status GetElem(SqList L, int i, ElemType *e) {
    /* 判断i是否非法，i从1开始 */
    if (L.length <= 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.elem[i - 1];
    return OK;
}

int LocateElem(SqList L, ElemType e) {
    if (L.length <= 0) {
        return 0;
    }

    for (int i = 0; i < L.length; ++i) {
        if (e == L.elem[i]) {
            return i + 1;
        }
    }

    return 0;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    return OK;
}

Status ListTraverse(SqList L) {
    return OK;
}

void unionL(SqList *La, SqList Lb) {

}