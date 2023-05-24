#include <stdexcept>
#include <vector>
#include "Team2.hpp"
using namespace ariel;

// constructor
Team2:: Team2(Character* team_leader_)
    : Team(team_leader_){}


// attack given team
void Team2:: attack(Team* target){
    if (target == nullptr) {
        throw std::invalid_argument("Error: null team");
    }
    
    if(target->stillAlive() == 0 || this->stillAlive() == 0){
        throw std::runtime_error("team problem");
    }
    
    // if the team leader isnt alive
    if(!this->get_team_leader()->isAlive()){
        // set new team leader
        Character* newl = find_new_leader();
        this->set_team_leader(newl);
    }

    // while there are members in team target
    if(target->stillAlive()>0){
        // if the team leader alive
        Character* enemy = find_enemy(this->get_team_leader(), target);
        
        // attack with cowboys  
        for(Character* character : this->get_characters()){
            if(character->isAlive()){

                if(dynamic_cast<Cowboy*>(character)){
                    cowboys_attack(character, enemy);
                }
                if(dynamic_cast<Ninja*>(character)){
                    ninjas_attack(character, enemy);
                }
                if(!enemy->isAlive()){
                    // there are no alive enemy
                    if(target->stillAlive()== 0){
                        return;
                    }
                    enemy = find_enemy(this->get_team_leader(), target);
                }
            }
        }
    }
}

// print all team members 
void Team2:: print(){
    // run through all elements 
    for(Character* character :  this->get_characters()){
        cout << character->print() << endl;
    }
}
