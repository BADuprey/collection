/**
 * Brodie Duprey
 * CS2240 OL1
 * main driver for Project 2
 */

#include "Stack.h"
#include "Queue.h"
#include "InternationalTrade.h"
#include <iostream>
#include <cassert>
#include <vector>


int main() {
    //Queue testing on ints
    Queue<int> intQueue;

    intQueue.enqueue(1);
    intQueue.print();

    assert(intQueue.dequeue() == 1);

    intQueue.enqueue(2);
    intQueue.enqueue(3);
    intQueue.print();

    assert(intQueue.find(2));
    assert(!intQueue.find(4));

    assert(!intQueue.isEmpty());

    assert(intQueue.dequeue() == 2);
    assert(intQueue.dequeue() == 3);
    assert(intQueue.isEmpty());


    //Queue testing on strings
    Queue<std::string> stringQueue;

    stringQueue.enqueue("a");
    stringQueue.print();

    assert(stringQueue.dequeue() == "a");

    stringQueue.enqueue("b");
    stringQueue.enqueue("c");
    stringQueue.print();

    assert(stringQueue.find("b"));
    assert(!stringQueue.find("d"));

    assert(!stringQueue.isEmpty());

    assert(stringQueue.dequeue() == "b");
    assert(stringQueue.dequeue() == "c");
    assert(stringQueue.isEmpty());

    //Queue testing on custom object
    Queue<InternationalTrade> tradeQueue;

    InternationalTrade trade1 = InternationalTrade(1, "a", "b", "c", 2, 3);
    InternationalTrade trade2 = InternationalTrade(2, "b", "c", "d", 3, 4);
    InternationalTrade trade3 = InternationalTrade(3, "c", "d", "e", 4, 5);
    InternationalTrade trade4 = InternationalTrade();

    tradeQueue.enqueue(trade1);
    tradeQueue.print();

    assert(tradeQueue.dequeue() == trade1);

    tradeQueue.enqueue(trade2);
    tradeQueue.enqueue(trade3);
    tradeQueue.print();

    assert(tradeQueue.find(trade2));
    assert(!tradeQueue.find(trade4));

    assert(!tradeQueue.isEmpty());

    assert(tradeQueue.dequeue() == trade2);
    assert(tradeQueue.dequeue() == trade3);
    assert(tradeQueue.isEmpty());

    //Demonstrating functionality of custom object in queue and stack
    std::vector<InternationalTrade> tradeVector;
    loadFromFile("../data1.csv", tradeVector);

    //creating stack for custom object
    Stack<InternationalTrade> tradeStack;

    for(int i = 0; i < 10; i++){
        InternationalTrade currentTrade = tradeVector.at(i);
        std::cout << currentTrade << std::endl;
        tradeQueue.enqueue(currentTrade);
    }

    for(int i = 0; i < 10; i++){
        tradeStack.push(tradeQueue.dequeue());
    }

    for(int i = 0; i < 10; i++){
         std::cout << tradeStack.pop() << std::endl;
    }




    return 0;
}
