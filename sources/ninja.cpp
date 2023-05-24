#include "ninja.hpp"
#include <iostream>
using namespace std;

using namespace ariel;

// constructor
Ninja:: Ninja(string name_, Point location_)
    : Character(name_, location_) {
        set_char_type(1);
    }

void Ninja:: set_ninja_speed(int speed_){
    this->speed = speed_;
}


void Ninja:: move(Character* target) {
    Point new_pos =  Point:: moveTowards(this->getLocation(), target->getLocation(), this->speed);
    this->setLocation(new_pos);
}


void Ninja:: slash(Character* target) {
    if (target == nullptr) {
        throw std::runtime_error("Error: null enemy");
    }

    if (!target->isAlive() || !this->isAlive()) {
        throw std::runtime_error("Error: attack dead character");
    }

    if (target == this) {
        throw std::runtime_error("Error: cowboys cannot shoot themselves");
    }

    if (this->isAlive() && this->distance(target) < 1) {
        target->hit(40);
    }

}

// return string of the Ninja data
string Ninja:: print(){
    if(!this->isAlive()){
        return ("N: (" + this->getName() + "), " + this->getLocation().print());
    }
    return ("N: " + this->getName() +", " + to_string(this->get_hit_nums()) + ", " + this->getLocation().print());
}