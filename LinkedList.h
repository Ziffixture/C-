#pragma once
#include <cstddef>



class Node {
public:
    Node* next;
    int value;

    Node(int value);
};


class LinkedList {
private:
    Node* _head;
    size_t _size;

    Node* getNodeAtIndex(const size_t index) const;

public:
    LinkedList();
    ~LinkedList();

    size_t size() const;
    void append(int value);
    void insert(int value, size_t index);
    void destroy(size_t index);
    void print() const;
};
