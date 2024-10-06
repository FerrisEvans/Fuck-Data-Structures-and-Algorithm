//
// Created by Ferris on 4/25/24.
//
#include "../status_def.h"

struct SequentialList {
    ElemType *element;
    int size;
    int capacity;
};

void console(SequentialList *);

// https://acm.hdu.edu.cn/showproblem.php?pid=2006
void pid2006();

// https://acm.hdu.edu.cn/showproblem.php?pid=2008
void pid2008();

void initialize(SequentialList *list, int capacity) {
    list->element = new ElemType[capacity];
    list->size = 0;
    list->capacity = capacity;
}

void destroy(SequentialList *list) {
    delete[] list->element;
}

int size(SequentialList *list) {
    return list->size;
}

bool isEmpty(SequentialList *list) {
    return list->size == 0;
}

void insert(SequentialList *list, ElemType e, int index) {
    if (index < 0 || index > list->size) {
        throw std::invalid_argument("Invalid index");
    }
    if (list->size == list->capacity) {
        int newCapacity = list->capacity * 2;
        auto *newElements = new ElemType[newCapacity];
        for (int i = 0; i < list->size; ++i) {
            newElements[i] = list->element[i];
        }
        delete[] list->element;
        list->element = newElements;
        list->capacity = newCapacity;
    }
    for (int i = list->size; i > index; --i) {
        list->element[i] = list->element[i - 1];
    }
    list->element[index] = e;
    list->size++;
}

void deleteElement(SequentialList *list, int index) {
    if (index < 0 || index >= list->size) {
        throw std::invalid_argument("Invalid index");
    }
    for (int i = index; i < list->size; ++i) {
        list->element[i] = list->element[i + 1];
    }
    list->size--;
}

int findElement(SequentialList *list, ElemType e) {
    for (int i = 0; i < list->size; ++i) {
        if (list->element[i] == e) {
            return i;
        }
    }
    return -1;
}

ElemType getElement(SequentialList *list, int index) {
    if (index < 0 || index >= list->size) {
        throw std::invalid_argument("Invalid index");
    }
    return list->element[index];
}

void updateElement(SequentialList *list, ElemType e, int index) {
    if (index < 0 || index >= list->size) {
        throw std::invalid_argument("Invalid index");
    }
    list->element[index] = e;
}

int main() {
//    pid2006();
    pid2008();
    return 0;
}

void console(SequentialList *list) {
    for (int i = 0; i < size(list); ++i) {
        cout << getElement(list, i) << " ";
    }
    cout << endl;
}

void pid2008() {
    int n;
    while (cin >> n && n) {
        double arr[n];
        for (int i = 0; i < n; ++i) {
            double x;
            cin >> x;
            arr[i] = x;
        }
        cout << endl;

        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; ++i) {
            double e = arr[i];
            if (e < -1e-8) a++;
            else if (e > 1e-8) c++;
            else b++;
        }

        cout << a << ' ' << b << ' ' << c << endl;
    }

}

void pid2006() {
    int n;
    while (cin >> n) {
        SequentialList list;
        initialize(&list, 1);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            insert(&list, x, i);
        }

        int val = 1;
        for (int i = 0; i < list.size; ++i) {
            int e = getElement(&list, i);
            if (e % 2 == 1) {
                val *= e;
            }
        }
        cout << val << endl;
        destroy(&list);
    }
}