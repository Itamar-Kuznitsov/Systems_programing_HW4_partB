#include "Cowboy.hpp"
#include <iostream>
using namespace std;
using namespace ariel;

// constructor
Cowboy:: Cowboy(string name_, Point location_)
    : Character(name_, location_), bullets_amount(6){
        set_character_hit_points(110);
        set_char_type(0);
    }

Cowboy:: Cowboy(Character*)
    : bullets_amount(6) {
        set_character_hit_points(110);
        set_char_type(0);
}


// if the Cowboy stil alive and ahve bullets -> run the enemy
void Cowboy:: shoot(Character* enemy){
    if (enemy == nullptr) {
        throw std::runtime_error("Error: null enemy");
    }

    if (enemy == this) {
        throw std::runtime_error("Error: cowboys cannot shoot themselves");
    }

    if (!enemy->isAlive() || !this->isAlive()) {
        throw std::runtime_error("Error: attack dead character");
    }

    if (this->isAlive() && this->bullets_amount > 0) {
        enemy->hit(10);
        this->bullets_amount -= 1;
    }
}

// return 1 if there are bullets in the stack otherwise 0
bool Cowboy:: hasboolets(){
    return (this->bullets_amount>0);
}

// reload the bullets stack with 6 new bullets
void Cowboy:: reload(){
    if (!this->isAlive()) {
        throw std::runtime_error("Error: dead cowboy cannot reload");
    }

    this->bullets_amount = 6;
}

// return string of the Cowboy data
string Cowboy:: print(){
    if(!this->isAlive()){
        return ("C: (" + this->getName() + "), " + this->getLocation().print());
    }
    return ("C: " + this->getName() +", " + to_string(this->get_hit_nums()) + ", " + this->getLocation().print());
}


