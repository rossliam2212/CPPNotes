//
// Created by Liam Ross on 15/10/2022.
//

#include <iostream>

class Deep {
private:
    int* data;

public:
    void setDataValue(int d) { *data = d; }
    int getDataValue() const { return *data; }

    // Constructor
    Deep(int d);

    // Copy Constructor
    Deep(const Deep& source);

    // Destructor
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::Deep(const Deep& source)
        : Deep{*source.data} {
    std::cout << "Copy constructor - deep copy" << std::endl;
}

Deep::~Deep() {
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}


void displayShallow(Deep s) {
    std::cout << s.getDataValue() << std::endl;
}

int main() {
    Deep obj1{100};
    displayShallow(obj1);

    Deep obj2{1000};
    obj2.setDataValue(1000);
    return 0;
}