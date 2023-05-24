#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "Team.hpp"

/**
 * @about: This is the Team2 header file. part from cowboy vs ninja game. Task 4 | Part A
 *          course: Systems proggraming N.2
 * @author Itamar Kuznitsov
 * @since May. 2023  
*/


namespace ariel{

class Team2 : public Team{
    public:
        Team2(Character*);
        void attack(Team* target) override;
        void print() override;
};
}
