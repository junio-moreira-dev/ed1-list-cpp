//
// Created by Junio Moreira on 24/09/26.
//

#ifndef ED1_LIST_CPP_LIST_H
#define ED1_LIST_CPP_LIST_H

#include <cstddef> // Para size_t

template <typename T>
class List {
public:
    virtual ~List() = default;

    // Insertion Operations
    virtual void addFirst(const T& item) = 0;
    virtual void addLast(const T& item) = 0;
    virtual void insertAt(int index, const T& item) = 0;
    virtual void addSorted(const T& item) = 0;

    // Removal Operations
    virtual T removeFirst() = 0;
    virtual T removeLast() = 0;
    virtual T removeAt(int index) = 0;
    virtual bool remove(const T& item) = 0;
    virtual void clear() = 0;

    // Search & Retrieval
    virtual int find(const T& item) const = 0;
    virtual T get(int index) const = 0;
    virtual void set(int index, const T& item) = 0;

    // Information
    virtual int size() const = 0;
};

#endif // ED1_LIST_CPP_LIST_H