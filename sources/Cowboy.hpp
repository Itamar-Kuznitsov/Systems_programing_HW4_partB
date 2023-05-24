#pragma once 
#include "Character.hpp"
#include <iostream>
using namespace std;

/**
 * @about: This is the Cowboy header file. part from cowboy vs ninja game. Task 4 | Part A
 *          course: Systems proggraming N.2
 * @author Itamar Kuznitsov
 * @since May. 2023  
*/

namespace ariel{

class Cowboy : public Character{
    private:
        int bullets_amount;
    public:
        Cowboy(string, Point);
        Cowboy(Character*);
        void shoot(Character*);
        bool hasboolets();
        void reload();
        string print() override; 
};
}