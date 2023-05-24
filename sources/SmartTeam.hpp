#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "Team2.hpp"


/**
 * @about: This is the SmartTeam header file. part from cowboy vs ninja game. Task 4 | Part A
 *          course: Systems proggraming N.2
 * @author Itamar Kuznitsov
 * @since May. 2023  
*/

namespace ariel{

class SmartTeam : public Team2{
    private: 
        int this_is_SmartTeam = 0;

    public:
        SmartTeam(Character*);
        void print_SmartTeam();
};
}