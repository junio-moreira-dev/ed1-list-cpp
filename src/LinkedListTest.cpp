//
// Created by Junio Moreira on 20/10/26.
//

#include "LinkedList.h"
#include <forward_list>
#include <iostream>

using namespace std;

void initialTests() {
    cout << "\n--- [LinkedList] Initial Tests (addLast, size, find, and get) ---" << endl;
    LinkedList<int> list;
    list.addLast(1);

    cout << "Expected size (1): " << list.size() << endl;
    cout << "Current list: " << list.toString() << endl;

    list.addLast(2);
    cout << "Current list: " << list.toString() << endl;

    list.addLast(3);
    cout << "Current list: " << list.toString() << endl;

    cout << "******* Search by element *******" << endl;
    cout << "Position of element 1 (expected 0): " << list.find(1) << endl;
    cout << "Position of element 0 (expected -1): " << list.find(0) << endl;

    cout << "******* Search by position *******" << endl;
    cout << "Element at index 0 (expected 1): " << list.get(0) << endl;
}

void testAddFirst() {
    cout << "\n--- [LinkedList] Test Add First (addFirst) ---" << endl;
    LinkedList<int> list;

    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(1);

    cout << "Expected list [1, 2, 3]: " << list.toString() << endl;
}

void testInsertAt() {
    cout << "\n--- [LinkedList] Test Insert At Position (insertAt) ---" << endl;
    LinkedList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(4);

    list.insertAt(0, 0); // Beginning
    list.insertAt(4, 5); // End (position equals current size)
    list.insertAt(2, 3); // Middle

    cout << "Expected list [0, 1, 2, 3, 4, 5]: " << list.toString() << endl;
}

void testRemoveFirst() {
    cout << "\n--- [LinkedList] Test Remove First (removeFirst) ---" << endl;
    LinkedList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);

    cout << "Removed item (expected 1): " << list.removeFirst() << endl;
    cout << "Remaining list (expected [2, 3]): " << list.toString() << endl;
}

void testRemoveLast() {
    cout << "\n--- [LinkedList] Test Remove Last (removeLast) ---" << endl;
    LinkedList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);

    cout << "Removed item (expected 3): " << list.removeLast() << endl;
    cout << "Remaining list (expected [1, 2]): " << list.toString() << endl;
}

void testRemoveAt() {
    cout << "\n--- [LinkedList] Test Remove At Position (removeAt) ---" << endl;
    LinkedList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);

    cout << "Removed item at index 4 (expected 5): " << list.removeAt(4) << endl;
    cout << "Remaining list (expected [1, 2, 3, 4]): " << list.toString() << endl;
}

void testRemoveByElement() {
    cout << "\n--- [LinkedList] Test Remove By Element (remove) ---" << endl;
    LinkedList<int> list;
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);

    cout << boolalpha; // Formats boolean output as true/false
    cout << "Removed element 20? (expected true): " << list.remove(20) << endl;
    cout << "Remaining list (expected [10, 30]): " << list.toString() << endl;
    cout << "Trying to remove element 99 (expected false): " << list.remove(99) << endl;
}

void testSet() {
    cout << "\n--- [LinkedList] Test Set Method (set) ---" << endl;
    LinkedList<int> list;
    list.addLast(10);
    list.addLast(20);

    cout << "List before set: " << list.toString() << endl;
    list.set(1, 99);
    cout << "List after set (expected [10, 99]): " << list.toString() << endl;
}

void testAddSorted() {
    cout << "\n--- [LinkedList] Test Sorted Insertion (addSorted) ---" << endl;
    LinkedList<int> list;

    list.addSorted(30);
    list.addSorted(10);
    list.addSorted(20);
    list.addSorted(5);

    cout << "Expected sorted list [5, 10, 20, 30]: " << list.toString() << endl;
}

void testNativeForwardList() {
    cout << "\n--- Benchmark with C++ Standard Library (std::forward_list) ---" << endl;
    forward_list<int> nativeList = {1, 2, 3};
    nativeList.push_front(0);

    cout << "Standard C++ forward_list: [";
    for (auto it = nativeList.begin(); it != nativeList.end(); ++it) {
        cout << *it;
        auto nextIt = it;
        ++nextIt;
        if (nextIt != nativeList.end()) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    // Uncomment tests as each concept is introduced during the lecture:
    initialTests();
    testAddFirst();
    testInsertAt();
    testRemoveFirst();
    testRemoveLast();
    testRemoveAt();
    testRemoveByElement();
    testSet();
    testAddSorted();

    testNativeForwardList();

    return 0;
}