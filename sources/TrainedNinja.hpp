#pragma once 
#include "ninja.hpp"
#include <iostream>
using namespace std;


/**
 * @about: This is the TrainedNinja header file. part from cowboy vs ninja game. Task 4 | Part A
 *          course: Systems proggraming N.2
 * @author Itamar Kuznitsov
 * @since May. 2023  
*/

namespace ariel{

class TrainedNinja : public Ninja {
    public:
        TrainedNinja(string name, Point location);

};
}