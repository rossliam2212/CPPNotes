//
// Created by Liam Ross on 13/10/2022.
//

#include <iostream>

class Shallow {
private:
    int* data;

public:
    void setDataValue(int d) { *data = d; }
    int getDataValue() const { return *data; }

    // Constructor
    Shallow(int d);

    // Copy Constructor
    Shallow(const Shallow& source);

    // Destructor
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow& source)
    : data{source.data} {
    std::cout << "Copy constructor - shallow copy" << std::endl;
}

Shallow::~Shallow() {
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}


void displayShallow(Shallow s) {
    std::cout << s.getDataValue() << std::endl;
}

int main() {
    Shallow obj1{100};
    displayShallow(obj1);

    Shallow obj2{1000};
    obj2.setDataValue(1000);
    return 0;
}