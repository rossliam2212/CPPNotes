//
// Created by Liam Ross on 13/10/2022.
//

#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int health;
    int xp;

public:
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getXp() const { return xp; }
    Player(std::string name = "None", int health = 0, int xp = 0);

    // Copy Constructor
    Player(const Player& source);

    // Destructor
    ~Player() { std::cout << "Destructor for " << name << std::endl; }
};

Player::Player(std::string name, int health, int xp)
    : name{name},
      health{health},
      xp{xp} {
    std::cout << "Three-args constructor for " << name << std::endl;
}

// Copy Constructor
Player::Player(const Player& source)
//    : name{source.name}, health{source.health}, xp{source.xp} // Using initializer list
    : Player{source.name, source.health, source.xp} // Using delegating constructor
{
    std::cout << "Copy constructor - made copy of: " << source.name << std::endl;
}


void displayPlayer(Player p) {
    std::cout << "Name: " << p.getName() << std::endl;
    std::cout << "Health: " << p.getHealth() << std::endl;
    std::cout << "XP: " << p.getXp() << std::endl;
}


int main() {
    Player empty{"XXXXXX", 100, 50};

    Player myNewObject{empty};

    displayPlayer(empty);

//    Player liam{"Liam"};
//    Player{"Hero", 100};
//    Player{"Villain", 100, 55};

    return 0;
}
