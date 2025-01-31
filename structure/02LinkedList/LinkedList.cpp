#include "iostream"
#include "stdexcept"

using namespace std;

typedef int EleType;

struct ListNode {
    EleType data;
    ListNode *next;

    explicit ListNode(EleType e) : data(e), next(nullptr) {}
};

class LinkedList {
private:
    ListNode *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList();

    void insert(int i, EleType val);

    void remove(int i);

    ListNode *find(EleType val);

    ListNode *get(int i);

    void update(int i, EleType val);

    void print();

    [[nodiscard]] int len() const {
        return size;
    }
};

LinkedList::~LinkedList() {
    ListNode *curr = head;
    while (curr != nullptr) {
        ListNode *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

void LinkedList::insert(int i, int val) {
    if (i < 0 || i > size) throw out_of_range("Invalid position");
    auto *newNode = new ListNode(val);
    if (i == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        ListNode *curr = head;
        for (int j = 0; j < i - 1; ++j) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
    size++;
}

void LinkedList::remove(int i) {
    if (i < 0 || i > size) throw out_of_range("Invalid position");
    if (i == 0) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    } else {
        ListNode *curr = head;
        for (int j = 0; j < i - 1; ++j) {
            curr = curr->next;
        }
        ListNode *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    size--;
}

ListNode *LinkedList::find(EleType val) {
    ListNode *curr = head;
    while (curr && curr->data != val) {
        curr = curr->next;
    }
    return curr;
}

ListNode *LinkedList::get(int i) {
    if (i < 0 || i >= size) throw out_of_range("Invalid position");
    ListNode *curr = head;
    for (int j = 0; j < i; ++j) {
        curr = curr->next;
    }
    return curr;
}

void LinkedList::update(int i, EleType val) {
    get(i)->data = val;
}

void LinkedList::print() {
    ListNode *curr = head;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    LinkedList list;
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 40);
    list.insert(4, 50);
    list.print();
    list.remove(1);
    list.print();
    list.update(1, 60);
    list.print();
    cout << list.get(2)->data << endl;
    cout << list.len() << endl;
    return 0;
}