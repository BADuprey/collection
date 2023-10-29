/**
 * Stack class header
 * CS 124
 * University of Vermont
 * Lisa Dion
 * 2019-Sep-09
 *
 * Clayton Cafiero
 * 2020-Jun-22
 * Minor revisions:
 *   - Minor formatting and changes to comments
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "Node.h"

/**
 * Stack Class
 * Each Node will point to the one below it.
 * We will keep track of the top node with a pointer.
 * Stacks are LIFO (last in, first out)
 */
template<typename Object>
class Stack {
private:
    Node<Object>* top;

public:

    // Constructor
    Stack() {
        top = nullptr;  // By default the stack will be empty
    }

    // Destructor
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    // Push an item onto the stack
    void push(Object item) {
        Node<Object>* newNode = new Node<Object>(item, top);
        top = newNode;
    }

    // Pop an item off the stack
    Object pop() {
        if (top == nullptr) {
            // The stack is empty so return a default object
            return Object();
        }
        Object item = top->getItem();
        Node<Object>* topCopy = top;
        top = top->getNext();
        delete topCopy;
        return item;
    }

    // Determine if an item is in the stack
    bool find(Object item) {
        Node<Object>* currentObject = top;
        while (currentObject != nullptr) {
            if (currentObject->getItem() == item) {
                return true;
            }
            currentObject = currentObject->getNext();
        }
        return false;
    }

    // Is the stack empty?
    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        return false;
    }

    // Print the stack
    void print() {
        std::cout << "Top of stack" << std::endl;
        Node<Object>* currentObject = top;
        while (currentObject != nullptr) {
            std::cout << currentObject->getItem() << std::endl;
            currentObject = currentObject->getNext();
        }
        std::cout << "Bottom of stack" << std::endl;
    }

};

#endif // STACK_H
