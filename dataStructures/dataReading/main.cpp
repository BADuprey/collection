/**
* Brodie Duprey
* CS2240
* Section OL1
*/

#include <vector>
#include <iostream>
#include "InternationalTrade.h"

int main() {
    std::vector<InternationalTrade> trades;
    std::string fileName = "../data1.csv";

    if (loadFromFile(fileName, trades)) {
        std::cout << trades.size()
                  << " records read from file" << std::endl;
        int firstId = trades.front().getPKey();
        std::cout << "The first primary key was " << firstId << std::endl;
        int lastId = trades.back().getPKey();
        std::cout << "The last primary key was " << lastId << std::endl;
    } else {
        std::cout << "Something is wrong" << std::endl;
    }

    tradeTest();

    verifyAllFieldsSet(trades);

    std::cout << "The average difference is: " << averageDifference(trades) <<std::endl;

    std::cout << std::endl;

    std::cout << std::setw(8) << "Pri. Key " << " LoId " << " PaId " << " PoId " << " Export " << " Import" << std::endl;
    std::cout << std::string(97, '-') << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << trades.at(i) << std::endl;
    }
}
