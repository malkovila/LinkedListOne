#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <time.h>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* perv, * next;
public:
    Node(int data){
        this->data = data;
        perv = NULL;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head, *tail;
public:
    LinkedList() {
        this->tail = this->head = NULL;
    }
    void push_front(int data) {
        Node* node = new Node(data);
        if (head == NULL and tail == NULL) {
            head = tail = node;
            return;
        }
        node->next = head;
        head = node;
        return;
    }
    void pop_front() {
        if (head == NULL) return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* node = head;
        head = node->next;
        delete node;
        return;

    }
    void show() {
        Node* c = head;
        while (c != NULL) {
            cout << c->data << ' ';
            c = c->next;
        }
        return;
    }
    
};
int main()
{
    LinkedList lst;
    lst.push_front(1);
    lst.push_front(2);
    lst.push_front(3);
    lst.pop_front();
    lst.show();

}