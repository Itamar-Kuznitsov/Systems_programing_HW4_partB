#include "OldNinja.hpp"

using namespace ariel;


OldNinja:: OldNinja(string name, Point location)
    : Ninja(name, location) {
        this-> set_ninja_speed(8);
        this-> set_character_hit_points(150);
}
