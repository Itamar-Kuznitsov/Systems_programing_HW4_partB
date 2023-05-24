#pragma once
#include <iostream>
using namespace std;
#include "point.hpp"

/**
 * @about: This is the Character header file. part from cowboy vs ninja game. Task 4 | Part A
 *          course: Systems proggraming N.2
 * @author Itamar Kuznitsov
 * @since May. 2023  
*/


namespace ariel{

class Character{
    private:
        Point location;
        int hits_num;
        string name;
        bool chartype;
        bool in_team = false;

    public:
        Character(string, Point);
        Character();
        // Copy constructor
        Character(const Character& other);
        // Copy assignment operator
        Character& operator=(const Character& other);
        // Move constructor
        Character(Character&& other) noexcept;
        // Move assignment operator
        Character& operator=(Character&& other) noexcept;

        bool isAlive();
        double distance(Character*);
        void hit(int hits);
        string getName();
        Point getLocation();
        void setLocation(Point);
        virtual string print(){return "";}
        void set_character_hit_points(int);
        int get_hit_nums();
        
        virtual void set_char_type(bool);
        virtual bool get_char_type();
        
        void set_in_team(bool);
        bool get_in_team();

}; 
}