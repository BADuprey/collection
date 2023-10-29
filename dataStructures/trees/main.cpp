#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "InternationalTrade.h"
#include "AvlTree.h"
#include "SplayTree.h"


int main() {
    BinarySearchTree intBST = BinarySearchTree<int>();

    for(int i = 1; i <= 100; i++){
        intBST.add(i);
    }

    int depth;
    std::ofstream outFileintBST;
    outFileintBST.open("../intBSToutput.csv");
    for(int i = 1; i <= 100; i++){
        outFileintBST << intBST.find(i, depth) << std::endl;
    }
    outFileintBST.close();

    std::vector<int> randomIntVector;

    for(int i = 1; i <= 100; i++){
        randomIntVector.push_back(i);
    }

    //shuffle method from algorithm library (researched from cppreference)
    std::random_shuffle(randomIntVector.begin(), randomIntVector.end());

    BinarySearchTree randIntBST = BinarySearchTree<int>();

    for(int i = 0; i < 100; i++){
        randIntBST.add(randomIntVector.at(i));
    }

    std::ofstream outFilerandintBST;
    outFilerandintBST.open("../randintBSToutput.csv");
    for(int i = 1; i <= 100; i++){
        outFilerandintBST << randIntBST.find(i, depth) << std::endl;
    }
    outFilerandintBST.close();

    BinarySearchTree tradeBST = BinarySearchTree<InternationalTrade>();
    std::vector<InternationalTrade> tradeVector;
    loadFromFile("../data.csv", tradeVector);

    for(int i = 0; i < tradeVector.size(); i++){
        tradeBST.add(tradeVector.at(i));
    }

    std::ofstream outFileCustomBST;
    outFileCustomBST.open("../customBSToutput.csv");

    for(int i = 0; i < tradeVector.size(); i++){
        outFileCustomBST << tradeBST.find(tradeVector.at(i), depth) << std::endl;
    }
    outFileCustomBST.close();



//AVL TREES
    AvlTree intAVL = AvlTree<int>();

    for(int i = 1; i <= 100; i++){
        intAVL.add(i);
    }

    std::ofstream outFileintAVL;
    outFileintAVL.open("../intAVLoutput.csv");
    for(int i = 1; i <= 100; i++){
        outFileintAVL << intAVL.find(i, depth) << std::endl;
    }
    outFileintAVL.close();

    AvlTree randIntAVL = AvlTree<int>();

    for(int i = 0; i < 100; i++){
        randIntAVL.add(randomIntVector.at(i));
    }

    std::ofstream outFilerandintAVL;
    outFilerandintAVL.open("../randintAVLoutput.csv");
    for(int i = 1; i <= 100; i++){
        outFilerandintAVL << randIntAVL.find(i, depth) << std::endl;
    }
    outFilerandintAVL.close();

    AvlTree tradeAVL = AvlTree<InternationalTrade>();

    for(int i = 0; i < tradeVector.size(); i++){
        tradeAVL.add(tradeVector.at(i));
    }

    std::ofstream outFileCustomAVL;
    outFileCustomAVL.open("../customAVLoutput.csv");

    for(int i = 0; i < tradeVector.size(); i++){
        outFileCustomAVL << tradeAVL.find(tradeVector.at(i), depth) << std::endl;
    }

    outFileCustomAVL.close();

//Splay Tree

    SplayTree intSplay = SplayTree<int>(false);

    for(int i = 1; i <= 100; i++){
        intSplay.add(i);
    }

    std::ofstream outFileintSplay;
    outFileintSplay.open("../intSplayoutput.csv");

    for(int i = 1; i <= 100; i++){
        outFileintSplay << intSplay.find(i, depth) << std::endl;
    }
    outFileintSplay.close();

    SplayTree randIntSplay = SplayTree<int>(false);

    for(int i = 0; i < 100; i++){
        randIntSplay.add(randomIntVector.at(i));
    }

    std::ofstream outFilerandintSplay;
    outFilerandintSplay.open("../randintSplayoutput.csv");
    for(int i = 1; i <= 100; i++){
        outFilerandintSplay << randIntSplay.find(i, depth) << std::endl;
    }
    outFilerandintSplay.close();

    SplayTree tradeSplay = SplayTree<InternationalTrade>(false);

    for(int i = 0; i < tradeVector.size(); i++){
        tradeSplay.add(tradeVector.at(i));
    }

    std::ofstream outFileCustomSplay;
    outFileCustomSplay.open("../customSplayoutput.csv");

    for(int i = 0; i < tradeVector.size(); i++){
        outFileCustomSplay << tradeSplay.find(tradeVector.at(i), depth) << std::endl;
    }

    outFileCustomSplay.close();

    SplayTree intSplay2 = SplayTree<int>(false);
    for(int i = 1; i <= 100; i++){
        intSplay2.add(i);
    }

    std::ofstream outFileIntSplay2;
    outFileIntSplay2.open("../intSplay2output.csv");
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 5; j++){
            outFileIntSplay2 << intSplay2.find(randomIntVector.at(i), depth) << std::endl;
        }
    }


    return 0;
}
