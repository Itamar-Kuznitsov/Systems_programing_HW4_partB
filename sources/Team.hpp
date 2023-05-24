#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

/**
 * @about: This is the Team header file. part from cowboy vs ninja game. Task 4 | Part A
 *          course: Systems proggraming N.2
 * @author Itamar Kuznitsov
 * @since May. 2023
 */

namespace ariel
{

    class Team
    {
    private:
        // two DS reprecent ocboys and ninjas
        vector<Character*> warriors;
        Character *team_leader;
        int character_counter = 0;

    public:
        Team(Character *);
        virtual ~Team();
        // Copy constructor
        Team(Team* team);
        // Move constructor
        Team(Team&& other) noexcept;
        // Assignment operator
        Team& operator=(const Team&);
        // Move assignment operator
        Team& operator=(Team&&) noexcept;
        Team(const Team&);


        
        void add(Character *);
        virtual void attack(Team *);
        int stillAlive();
        virtual void print();
        Character* find_enemy(Character*, Team*);

        void cowboys_attack(Character*, Character*);
        void ninjas_attack(Character*, Character*);
        vector<Character*> get_characters();
        void set_character(Character*);
        Character* find_new_leader();
        void set_team_leader(Character*);
        Character* get_team_leader();
        int get_character_counter();
        void set_character_counter(int);
    };
}