/**
 * Node class header
 * CS 124
 * University of Vermont
 * Lisa Dion
 * 2019-Sep-06
 *
 * Clayton Cafiero
 * 2020-Jun-22
 * Minor revisions:
 *   - Minor formatting and addition of some comments
 *
 * 2020-Dec-18
 *   - Grouped setters and getters
 *   - Slimmed down comments
 */

#ifndef NODE_H
#define NODE_H

/**
 * Represents one node to be used in a linked list
 * Contains data (object) and reference to next in list
 */
template<typename Object>
class Node {
private:
    Object item;
    Node* next;

public:
    // Constructors
    Node(Object newItem) {
        item = newItem;
        next = nullptr;
    }

    Node(Object newItem, Node* nextNode) {
        item = newItem;
        next = nextNode;
    }

    // Setters
    void setItem(Object newItem) {
        item = newItem;
    }

    void setNext(Node* nextNode) {
        next = nextNode;
    }

    // Getters
    Object getItem() {
        return item;
    }

    Node* getNext() {
        return next;  // Returns a pointer
    }
};

#endif // NODE_H
