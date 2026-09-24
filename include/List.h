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

    // Inserção
    virtual void addFirst(const T& item) = 0;
    virtual void addLast(const T& item) = 0;
    virtual void insertAt(int i, const T& item) = 0;
    virtual void addSorted(const T& element) = 0;

    // Remoção
    virtual T removeFirst() = 0;
    virtual T removeLast() = 0;
    virtual T removeAt(int i) = 0;
    virtual bool remove(const T& item) = 0;
    virtual void clear() = 0;

    // Busca e Acesso
    virtual int find(const T& item) const = 0;
    virtual T get(int i) const = 0;
    virtual void set(int i, const T& item) = 0;

    // Informações
    virtual int size() const = 0;
};

#endif //ED1_LIST_CPP_LIST_H