/**
* Brodie Duprey
* CS2240
* Section OL1
*/

#ifndef InternationalTrade_H
#define InternationalTrade_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cassert>

class InternationalTrade {
private:
    std::string locationCode, partnerCode, productId;
    int pKey, exportValue, import;

public:
    //Constructors
    InternationalTrade() {
    }

    InternationalTrade(int pKey,
                       std::string locationCode,
                       std::string partnerCode,
                       std::string productId,
                       int exportValue,
                       int import) {
        this->pKey = pKey;
        this->locationCode = locationCode;
        this->partnerCode = partnerCode;
        this->productId = productId;
        this->exportValue = exportValue;
        this->import = import;
    }

    //Getters
    int getPKey() const {
        return pKey;
    }

    std::string getLocationCode() const {
        return locationCode;
    }

    std::string getPartnerCode() const {
        return partnerCode;
    }

    std::string getProductId() const {
        return productId;
    }

    int getExportValue() const {
        return exportValue;
    }

    int getImport() const {
        return import;
    }

    //Setters
    void setPKey(int pKey) {
        this->pKey = pKey;
    }

    void setLocationCode(std::string locationCode) {
        this->locationCode = locationCode;
    }

    void setPartnerCode(std::string partnerCode) {
        this->partnerCode = partnerCode;
    }

    void setProductId(std::string productId) {
        this->productId = productId;
    }

    void setExportValue(int exportValue) {
        this->exportValue = exportValue;
    }

    void setImport(int import) {
        this->import = import;
    }

    /**
    * Overloaded stream insertion operator
    */
    friend std::ostream& operator << (std::ostream& outs, const InternationalTrade& obj) {
        outs << std::fixed
             << std::right
             << std::setw(8) << obj.getPKey()
             << std::setw(7) << obj.getLocationCode()
             << std::setw(6) << obj.getPartnerCode()
             << std::setw(5) << obj.getProductId()
             << std::setw(7) << obj.getExportValue()
             << std::setw(10) << obj.getImport();
        return outs;
    }


    //Overloaded operators from example from project 1

    /**
     * Overload < operator for object comparison
     */
    friend bool operator < (const InternationalTrade& lhs, const InternationalTrade& rhs) {
        return lhs.getPKey() < rhs.getPKey();
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator > (const InternationalTrade& lhs, const InternationalTrade& rhs) {
        return lhs.getPKey() > rhs.getPKey();
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const InternationalTrade& lhs, const InternationalTrade& rhs) {
        return lhs.getPKey() <= rhs.getPKey();
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const InternationalTrade& lhs, const InternationalTrade& rhs) {
        return lhs.getPKey() >= rhs.getPKey();
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const InternationalTrade& lhs, const InternationalTrade& rhs) {
        return lhs.getPKey() == rhs.getPKey();
    }

    /**
     * Overload != operator for object comparison
     */
    friend bool operator != (const InternationalTrade& lhs, const InternationalTrade& rhs) {
        return lhs.getPKey() != rhs.getPKey();
    }
};

//Loads a vector from a CSV file. True if successful, false if not
bool loadFromFile(std::string fn, std::vector<InternationalTrade>& objs) {
    std::ifstream fin;
    fin.open(fn);

    if (!fin) {
        std::cout << "Invalid File" << std::endl;
        return false;
    }

    int counter = 1;

    std::string extra = "INVALID";
    getline(fin, extra);

    while (fin && fin.peek() != EOF) {
        int pKey = -1;
        std::string locationCode = "INVALID";
        std::string partnerCode = "INVALID";
        std::string productId = "INVALID";
        int exportValue = -1;
        int import = -1;

        char comma = ',';

        getline(fin, extra, comma);

        fin >> pKey;
        fin >> comma;

        if (pKey != counter) {
            std::cout << pKey << " != " << counter << std::endl;
            return false;
        }

        getline(fin, locationCode, comma);
        getline(fin, partnerCode, comma);
        getline(fin, productId, comma);

        fin >> exportValue;
        fin >> comma;
        fin >> import;

        InternationalTrade trade(pKey, locationCode, partnerCode, productId, exportValue, import);

        objs.push_back(trade);
        counter++;
    }

    fin.close();
    return true;
}

//Finds the average difference between import and export values. If > 0: import is higher, else export is
int averageDifference(std::vector<InternationalTrade>& objs) {
    int difference = 0;

    for (InternationalTrade& trade : objs) {
        difference = trade.getImport() - trade.getExportValue();
    }

    difference = difference / objs.back().getPKey();
    return difference;

}

//Verify fields. no fields should have missing values
void verifyAllFieldsSet(std::vector<InternationalTrade>& objs) {
    int i = 0;
    for (InternationalTrade& trade : objs) {
        if (trade.getPKey() != i + 1) {
            std::cout << "Bad value for pKey at record " << i << std::endl;
        }

        if (trade.getLocationCode() == "INVALID") {
            std::cout << "Bad value for Location code at record " << i << std::endl;
        }

        if (trade.getPartnerCode() == "INVALID") {
            std::cout << "Bad value for partner code at record " << i << std::endl;
        }

        if (trade.getProductId() == "INVALID") {
            std::cout << "Bad value for product id at record " << i << std::endl;
        }

        if (trade.getExportValue() == -1) {
            std::cout << "Bad value for export at record " << i << std::endl;
        }

        if (trade.getImport() == -1) {
            std::cout << "Bad value for import at record " << i << std::endl;
        }

        i++;
    }
}

void tradeTest() {
    InternationalTrade testObject = InternationalTrade();

    //test (s/g)etters
    testObject.setPKey(1);
    assert(testObject.getPKey() == 1);
    testObject.setLocationCode("ABC");
    assert(testObject.getLocationCode() == "ABC");
    testObject.setPartnerCode("XYZ");
    assert(testObject.getPartnerCode() == "XYZ");
    testObject.setProductId("123");
    assert(testObject.getProductId() == "123");
    testObject.setExportValue(123);
    assert(testObject.getExportValue() == 123);
    testObject.setImport(456);
    assert(testObject.getImport() == 456);

    //test initialization
    InternationalTrade testObject2 = InternationalTrade(1, "ABC", "DEF", "123", 123, 234);
    assert(testObject2.getPKey() == 1);
    assert(testObject2.getLocationCode() == "ABC");
    assert(testObject2.getPartnerCode() == "DEF");
    assert(testObject2.getProductId() == "123");
    assert(testObject2.getExportValue() == 123);
    assert(testObject2.getImport() == 234);
}

#endif // InternationalTrade_H
