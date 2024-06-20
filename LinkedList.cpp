#include "LinkedList.h"
#include <iostream>
#include <cstddef>
#include <string>



Node::Node(int value) : next(nullptr), value(value) {}


LinkedList::LinkedList() : _head(nullptr), _size(0) {}

LinkedList::~LinkedList() {
    while (_head) {
        destroy(0);
    }
}

Node* LinkedList::getNodeAtIndex(const size_t index) const {
    Node* currentNode = _head;
    size_t currentIndex = 0;

    while (currentNode != nullptr && currentIndex < index) {
        currentNode = currentNode->next;
        currentIndex++;
    }

    return currentNode;
}

size_t LinkedList::size() const {
    return _size;
}

void LinkedList::append(int value) {
    insert(value, _size);
}

void LinkedList::insert(int value, size_t index) {
    if (index > _size) {
        return;
    }

    Node* newNode = new Node(value);

    if (index == 0) {
        newNode->next = _head;
        _head = newNode;
    } 
    else {
        Node* atIndex = getNodeAtIndex(index - 1);
        if (!atIndex) {
            delete newNode;

            return;
        }

        newNode->next = atIndex->next;
        atIndex->next = newNode;
    }

    _size++;
}

void LinkedList::destroy(size_t index) {
    if (index >= _size) {
        return;
    }

    Node* targetNode;

    if (index == 0) {
        targetNode = _head;
        _head = _head->next;
    } 
    else {
        Node* atIndex = getNodeAtIndex(index - 1);
        if (!atIndex || !atIndex->next) {
            return;
        }

        targetNode = atIndex->next;
        atIndex->next = targetNode->next;
    }

    delete targetNode;

    _size--;
}

void LinkedList::print() const {
    if (_size == 0) {
        std::cout << "Empty" << std::endl;

        return;
    }

    std::string result = "";

    for (Node* node = _head; node != nullptr; node = node->next) {
        result += std::to_string(node->value);

        if (node->next) {
            result += " -> ";
        }
    }

    std::cout << result << std::endl;
}
