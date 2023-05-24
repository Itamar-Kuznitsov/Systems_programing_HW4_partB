#include "YoungNinja.hpp"


using namespace ariel;

YoungNinja:: YoungNinja(string name, Point location)
    : Ninja(name, location) {
        this-> set_ninja_speed(14);
        this-> set_character_hit_points(100);
    }
