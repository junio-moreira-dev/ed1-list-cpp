//
// Created by Junio Moreira on 24/09/26.
//

#include <iostream>
#include "../include/ArrayList.h"

using namespace std;

void initialTests() {
    cout << "\n--- [ArrayList] Initial Tests (addLast, size, find, and get) ---\n";
    ArrayList<int> list(5);
    list.addLast(1);

    cout << "Expected size (1): " << list.size() << "\n";
    cout << "Current list: " << list.toString() << "\n";

    list.addLast(2);
    cout << "Current list: " << list.toString() << "\n";

    list.addLast(3);
    cout << "Current list: " << list.toString() << "\n";

    cout << "******* Search by element *******\n";
    cout << "Position of element 1 (expected 0): " << list.find(1) << "\n";
    cout << "Position of element 0 (expected -1): " << list.find(0) << "\n";

    cout << "******* Search by position *******\n";
    cout << "Element at pos 0 (expected 1): " << list.get(0) << "\n";
}

void testAddFirst() {
    cout << "\n--- [ArrayList] Test Add First (addFirst) ---\n";
    ArrayList<int> list(5);

    list.addFirst(3);
    list.addFirst(2);
    list.addFirst(1);

    cout << "Expected list [1, 2, 3]: " << list.toString() << "\n";
}

void testInsertAt() {
    cout << "\n--- [ArrayList] Test Insert At Position (insertAt) ---\n";
    ArrayList<int> list(10);
    list.addLast(1);
    list.addLast(2);
    list.addLast(4);

    list.insertAt(0, 0); // Beginning
    list.insertAt(4, 5); // End (position equal to current size)
    list.insertAt(2, 3); // Middle

    cout << "Expected list [0, 1, 2, 3, 4, 5]: " << list.toString() << "\n";
}

void testRemoveFirst() {
    cout << "\n--- [ArrayList] Test Remove First (removeFirst) ---\n";
    ArrayList<int> list(5);
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);

    cout << "Expected removed (1): " << list.removeFirst() << "\n";
    cout << "Expected remaining list [2, 3]: " << list.toString() << "\n";
}

void testRemoveLast() {
    cout << "\n--- [ArrayList] Test Remove Last (removeLast) ---\n";
    ArrayList<int> list(5);
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);

    cout << "Expected removed (3): " << list.removeLast() << "\n";
    cout << "Expected remaining list [1, 2]: " << list.toString() << "\n";
}

void testRemoveAt() {
    cout << "\n--- [ArrayList] Test Remove At Position (removeAt) ---\n";
    ArrayList<int> list(5);
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);

    cout << "Element removed at pos 4 (expected 5): " << list.removeAt(4) << "\n";
    cout << "Expected remaining list [1, 2, 3, 4]: " << list.toString() << "\n";
}

void testRemoveByElement() {
    cout << "\n--- [ArrayList] Test Remove By Element (remove) ---\n";
    ArrayList<int> list(5);
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);

    cout << boolalpha; // Prints 'true' or 'false' in the console instead of 1 or 0
    cout << "Removed 20? (true): " << list.remove(20) << "\n";
    cout << "Expected remaining list [10, 30]: " << list.toString() << "\n";
    cout << "Trying to remove 99 again (false): " << list.remove(99) << "\n";
}

void testSetMethod() {
    cout << "\n--- [ArrayList] Test Element Modification (set) ---\n";
    ArrayList<int> list(5);
    list.addLast(10);
    list.addLast(20);

    cout << "List before set: " << list.toString() << "\n";
    list.set(1, 99); // Replaces 20 with 99
    cout << "List after set (expected [10, 99]): " << list.toString() << "\n";
}

void testAddSorted() {
    cout << "\n--- [ArrayList] Test Sorted Insertion (addSorted) ---\n";
    ArrayList<int> list(5);

    list.addSorted(30);
    list.addSorted(10);
    list.addSorted(20);
    list.addSorted(5);

    cout << "Expected auto-sorted list [5, 10, 20, 30]: " << list.toString() << "\n";
}

void testFullList() {
    cout << "\n--- [ArrayList] Test Static Limit (Full List) ---\n";
    ArrayList<int> list(2);
    list.addLast(100);
    list.addLast(200);

    cout << "Trying to insert the third element into an array of capacity 2:\n";
    list.addLast(300); // Should print: Error: List is full!
}

int main() {
    initialTests();
    // testAddFirst();
    // testInsertAt();
    // testRemoveFirst();
    // testRemoveLast();
    // testRemoveAt();
    // testRemoveByElement();
    // testSetMethod();
    // testAddSorted();
    // testFullList();

    return 0;
}