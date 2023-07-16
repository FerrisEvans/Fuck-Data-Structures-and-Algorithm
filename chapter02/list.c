//
// Created by Macintosh on 2023/7/8.
//
#include "../status_def.h"

#define LIST_INIT_SIZE 100 /* 线性表存储空间的初始分配量 */

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

    SqList L;
    SqList Lb;

    ElemType e;
    Status i;
    int j, k;
    i = InitList(&L);
    printf("初始化L后：L.length=%d\n", L.length);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);

    printf("L.length=%d \n", L.length);
    i = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n", i);

    i = ClearList(&L);
    printf("清空L后：L.length=%d\n", L.length);
    i = ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n", i);

    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L);

    printf("L.length=%d \n", L.length);

    ListInsert(&L, 1, 0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    printf("L.length=%d \n", L.length);

    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n", e);
    for (j = 3; j <= 4; j++) {
        k = LocateElem(L, j);
        if (k)
            printf("第%d个元素的值为%d\n", k, j);
        else
            printf("没有值为%d的元素\n", j);
    }


    k = ListLength(L); /* k为表长 */
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(&L, j, &e); /* 删除第j个数据 */
        if (i == ERROR)
            printf("删除第%d个数据失败\n", j);
        else
            printf("删除第%d个的元素值为：%d\n", j, e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L);

    j = 5;
    ListDelete(&L, j, &e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n", j, e);

    printf("依次输出L的元素：");
    ListTraverse(L);

    //构造一个有10个数的Lb
    i = InitList(&Lb);
    for (j = 6; j <= 15; j++)
        i = ListInsert(&Lb, 1, j);

    unionL(&L, Lb);

    printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L);

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
    if (L->length > LIST_INIT_SIZE) return ERROR;

    if (i < 1 || i > L->length + 1) return ERROR;

    if (i <= L->length) {
        for (int j = L->length - 1; j >= i - 1; --j) {
            L->elem[j + 1] = L->elem[j];
        }
    }
    L->elem[i - 1] = e;
    L->length++;

    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    if (L->length <= 0) return ERROR;
    if (i < 1 || i > L->length) return ERROR;

    *e = L->elem[i - 1];

    if (i < L->length) {
        for (int j = i; j < L->length; ++j) {
            L->elem[j - 1] = L->elem[j];
        }
    }
    L->length--;
    return OK;
}

Status ListTraverse(SqList L) {
    if (L.length < 0) return ERROR;
    for (int i = 0; i < L.length; ++i) visit(L.elem[i]);
    printf("\n");
    return OK;
}

void unionL(SqList *La, SqList Lb) {
    int La_len = ListLength(*La);
    int Lb_len = ListLength(Lb);

    ElemType e;
    for (int i = 1; i <= Lb_len; ++i) {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e)) ListInsert(La, ++La_len, e);
    }
}