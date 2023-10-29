/**
 * Brodie Duprey
 * Cs2240OL1
 * Queue Header for Project 2
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

template<typename Object>
class Queue {
private:
    Node<Object>* front;

public:
    //constructor
    Queue(){
        front = nullptr;
    }

    //destructor
    ~Queue(){
        while(front != nullptr){
            dequeue();
        }
    }

    //Enqueues an item
    void enqueue(Object item){
        Node<Object>* newNode = new Node<Object>(item, nullptr);

        if(front == nullptr){
            front = newNode;
        } else {
            Node<Object>* tracker = front;
            bool atBack = false;

            while(!atBack) {
                if (tracker->getNext() != nullptr) {
                    tracker = tracker->getNext();
                } else {
                    tracker->setNext(newNode);
                    atBack = true;
                }
            }
        }

    }

    //Dequeues an item
    Object dequeue(){
        if(front == nullptr) {
            return Object();
        }

        Object item = front->getItem();
        Node<Object>* frontCopy = front;
        front = front->getNext();
        delete frontCopy;
        return item;
    }

    //Finds if an item is in queue
    bool find(Object item){
        Node<Object>* currentObject = front;
        while (currentObject != nullptr){
            if(currentObject->getItem() == item){
                return true;
            }
            currentObject = currentObject->getNext();
        }
        return false;
    }

    //Determines if queue is empty
    bool isEmpty(){
        if(front == nullptr){
            return true;
        }
        return false;
    }

    //Prints Queue
    void print(){
        std::cout << "Front of Queue" << std::endl;
        Node<Object>* currentObject = front;
        while(currentObject != nullptr){
            std::cout << currentObject->getItem() << std::endl;
            currentObject = currentObject->getNext();
        }
        std::cout << "Back of Queue" << std::endl;
    }
};

#endif //QUEUE_H
