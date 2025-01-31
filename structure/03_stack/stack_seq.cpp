//
// Created by Ferris on 10/13/24.
//
#include "iostream"
#include "stdexcept"

using namespace std;

template<typename T>
class Stack {
private:
    T *data;
    int size;
    int capacity;
    void resize();

public:
    Stack() : data(new T[10]), size(0), capacity(10) {}
    ~Stack();
    void push(T element);
    T pop();
    T top() const;
    int getSize() const;
};