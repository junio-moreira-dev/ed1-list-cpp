//
// Created by Junio Moreira on 20/10/26.
//

#ifndef ED1_LINKED_LIST_CPP_LINKEDLIST_H
#define ED1_LINKED_LIST_CPP_LINKEDLIST_H

#include "List.h"
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

template <typename T>
class LinkedList : public List<T> {
private:
    // Internal struct to represent a node
    struct Node {
        T item;
        Node* next;

        explicit Node(const T& item) : item(item), next(nullptr) {}
        Node(const T& item, Node* next) : item(item), next(next) {}
    };

    Node* head;
    Node* tail;
    int count; // Standardized as 'count' to avoid shadowing the size() member function

    const int NOT_FOUND = -1;
    const std::string DOES_NOT_EXIST = "Position does not exist.";
    const std::string LIST_EMPTY = "List is empty.";

    bool positionDoesNotExist(int position) const {
        return !(position >= 0 && position < count);
    }

    // Traverses the chain and returns a pointer to the node at the specified position
    Node* searchNode(int position) const {
        if (positionDoesNotExist(position)) {
            throw std::invalid_argument(DOES_NOT_EXIST);
        }

        Node* currentNode = head;
        for (int i = 0; i < position; i++) {
            currentNode = currentNode->next;
        }

        return currentNode;
    }

public:
    LinkedList() : head(nullptr), tail(nullptr), count(0) {}

    // Destructor to free dynamically allocated heap memory across all nodes
    ~LinkedList() override {
        clear();
    }

    int size() const override {
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    // Inserts a new item at the beginning of the list
    void addFirst(const T& item) override {
        Node* newNode = new Node(item, head);

        if (count == 0) {
            head = newNode;
            tail = newNode;
        } else {
            head = newNode;
        }

        count++;
    }

    // Inserts a new item at the end of the list using the tail pointer
    void addLast(const T& item) override {
        Node* newNode = new Node(item);

        if (count == 0) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
        count++;
    }

    // Inserts a new item at a specific index
    void insertAt(int index, const T& item) override {
        if (index < 0 || index > count) {
            throw std::invalid_argument(DOES_NOT_EXIST);
        }

        if (index == 0) {
            addFirst(item);
        } else if (index == count) {
            addLast(item);
        } else {
            Node* previousNode = searchNode(index - 1);
            Node* newNode = new Node(item, previousNode->next);
            previousNode->next = newNode;
            count++;
        }
    }

    // Inserts a new item in ascending sorted order (requires operator '<' for type T)
    void addSorted(const T& item) override {
        if (count == 0 || !(head->item < item)) {
            addFirst(item);
        } else if (!(item < tail->item)) {
            addLast(item);
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->item < item) {
                current = current->next;
            }
            Node* newNode = new Node(item, current->next);
            current->next = newNode;
            count++;
        }
    }

    // Removes and returns the first element of the list
    T removeFirst() override {
        if (count == 0) {
            throw std::runtime_error(LIST_EMPTY);
        }

        Node* nodeToDelete = head;
        T removed = nodeToDelete->item;

        head = head->next;
        delete nodeToDelete;
        count--;

        if (count == 0) {
            tail = nullptr;
        }

        return removed;
    }

    // Removes and returns the last element of the list
    T removeLast() override {
        if (count == 0) {
            throw std::runtime_error(LIST_EMPTY);
        }

        // Single element edge case
        if (count == 1) {
            return removeFirst();
        }

        Node* penultimateNode = searchNode(count - 2);
        Node* nodeToDelete = penultimateNode->next;
        T removed = nodeToDelete->item;

        penultimateNode->next = nullptr;
        tail = penultimateNode;
        delete nodeToDelete;
        count--;

        return removed;
    }

    // Removes and returns the element at a specific index
    T removeAt(int index) override {
        if (positionDoesNotExist(index)) {
            throw std::invalid_argument(DOES_NOT_EXIST);
        }

        if (index == 0) {
            return removeFirst();
        }

        if (index == count - 1) {
            return removeLast();
        }

        Node* previousNode = searchNode(index - 1);
        Node* current = previousNode->next;
        Node* nextNode = current->next;

        previousNode->next = nextNode;
        T removed = current->item;
        delete current;

        count--;
        return removed;
    }

    // Removes the first occurrence of the specified item
    bool remove(const T& item) override {
        int position = find(item);

        if (position == NOT_FOUND) {
            return false;
        }

        removeAt(position);
        return true;
    }

    // Deallocates all nodes and resets the list to an empty state
    void clear() override {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Performs a linear search and returns the index of the item, or NOT_FOUND (-1)
    int find(const T& item) const override {
        Node* current = head;
        int index = 0;

        while (current != nullptr) {
            if (current->item == item) {
                return index;
            }
            current = current->next;
            index++;
        }
        return NOT_FOUND;
    }

    // Retrieves the item stored at a specific index
    T get(int index) const override {
        return searchNode(index)->item;
    }

    // Updates the item stored at a specific index
    void set(int index, const T& item) override {
        Node* node = searchNode(index);
        node->item = item;
    }

    // Generates a string representation of the list in array format [item1, item2, ...]
    std::string toString() const {
        if (count == 0) {
            return "[]";
        }

        std::ostringstream builder;
        builder << "[";
        Node* current = head;

        while (current != nullptr) {
            builder << current->item;
            if (current->next != nullptr) {
                builder << ", ";
            }
            current = current->next;
        }

        builder << "]";
        return builder.str();
    }
};

#endif //ED1_LINKED_LIST_CPP_LINKEDLIST_H
