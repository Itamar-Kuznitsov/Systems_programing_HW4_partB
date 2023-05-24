#include "Team.hpp"
using namespace ariel;

// constructor
Team:: Team(Character* team_leader_)
    : team_leader(team_leader_), character_counter(1){
        add(team_leader_);
    }


// free all team members
Team::~Team(){
    for(Character* character : this->warriors){
        delete character;
    }
}


// Copy constructor
Team::Team(Team* team) {
    if (team == nullptr) {
        throw std::invalid_argument("Given null pointer");
    }
    team_leader = team->team_leader;
    for (Character* character : warriors) {
        delete character;
    }
    for (Character* character : team->warriors) {
        warriors.push_back(character);
    }
}

// Copy assignment operator
Team& Team::operator=(const Team& other) {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Delete existing warriors
    for (Character* character : warriors) {
        delete character;
    }
    warriors.clear();

    // Copy leader
    team_leader = other.team_leader;

    // Copy warriors
    for (Character* character : other.warriors) {
        warriors.push_back(new Character(*character)); 
    }
    return *this;
}

// Move assignment operator
Team& Team::operator=(Team&& other) noexcept {
    if (this == &other) {
        return *this; // Handle self-assignment
    }

    // Delete existing warriors
    for (Character* character : warriors) {
        delete character;
    }
    warriors.clear();

    // Move the leader
    delete team_leader;
    team_leader = other.team_leader;
    other.team_leader = nullptr;

    // Move the warriors
    warriors = std::move(other.warriors);
    other.warriors.clear();

    return *this;
}

// Copy constructor
Team:: Team(const Team& other) {
    // Perform a deep copy of the team_leader
    if (other.team_leader) {
        team_leader = new Character(*other.team_leader);
    } else {
        team_leader = nullptr;
    }

    // Perform a deep copy of the warriors
    for (Character* character : other.warriors) {
        warriors.push_back(new Character(*character));
    }
}


// add team member
void Team:: add(Character* character){
    // if team is full - exeption
    if(this->warriors.size() >= 10){
        throw runtime_error("No place in the queue");
    }
    if(character->get_in_team()){
        throw runtime_error("Error: character in the team");
    }
    else{
        this->warriors.push_back(character);
        character->set_in_team(true);
    }
}


// attack given team
void Team:: attack(Team* target){
    if (target == nullptr) {
        throw std::invalid_argument("Error: null team");
    }
    
    if(target->stillAlive() == 0 || this->stillAlive() == 0){
        throw std::runtime_error("team problem");
    }

    // if the team leader isnt alive
    if(!this->team_leader->isAlive()){
        // set new team leader
        Character* newl = find_new_leader();
        this->set_team_leader(newl);
    }

    // while there are members in team target
    if(target->stillAlive()>0){
        // if the team leader alive
        Character* enemy = find_enemy(this->team_leader, target);
        
        // attack with cowboys  
        for(Character* character : this->warriors){
            if(character->isAlive()){
                if(dynamic_cast<Cowboy*>(character)){
                    cowboys_attack(character, enemy);
                }
                
                if(!enemy->isAlive()){
                    // there are no alive enemys
                    if(target->stillAlive() > 0){
                        enemy = find_enemy(this->team_leader, target);
                    }
                }
            }
        }

        for(Character* character : this->warriors){
            if(character->isAlive()){
                if(dynamic_cast<Ninja*>(character)){
                    ninjas_attack(character, enemy);
                }
                
                if(!enemy->isAlive()){
                    // there are no alive enemys
                    if(target->stillAlive() > 0){
                        enemy = find_enemy(this->team_leader, target);
                    }
                }
            }
        }
    }
    else{
        throw std::runtime_error("Error: no enemys");
    }
}


// return amount of alive character
int Team:: stillAlive(){
    int counter = 0;
    
    for( Character* character : this->warriors){
        if(character->isAlive()){
            counter+= 1;
        }
    }
    return counter;
}


// print all teams members
void Team:: print(){            
    // run through all cowboys elements
    for(Character* character : this->warriors){
        if(dynamic_cast<Cowboy*>(character)){
            cout << character->print() << endl;
        }
    }

    // run through all ninja elements
    for(Character* character : this->warriors){
        if(dynamic_cast<Ninja*>(character)){
            cout << character->print() << endl;
        }
    }
}


// assitance function - return closest character to the team leader
Character* Team:: find_enemy(Character* team_leader, Team* target){
    Character* closest_enemy = nullptr;
    double minimum = numeric_limits<double>:: max();
    
    // Run through all cowboy elements
    for(Character* character :  target->get_characters()){
        if(dynamic_cast<Cowboy*>(character)){
            if (team_leader->distance(character) < minimum && character->isAlive()) {
                minimum = team_leader->distance(character);
                closest_enemy = character;
            }
        }
    }

    // Run through all ninja elements 
    for(Character* character :  target->get_characters()){
        if(dynamic_cast<Ninja*>(character)){
            if (team_leader->distance(character) < minimum && character->isAlive()) {
                minimum = team_leader->distance(character);
                closest_enemy = character;
            }
        }
    }

    // Check if closest_enemy is still nullptr
    if (closest_enemy == nullptr) {
        throw std::runtime_error("No enemy found");
    }
    return closest_enemy;
}


// assitance function - attack by cowboys
void Team:: cowboys_attack(Character* character, Character* enemy){
    if(character->isAlive()){
        // casting
        Cowboy* cowboy = ((Cowboy*)character);
        
        if(enemy->isAlive()){
            // if the cowboy alive
            if(cowboy->hasboolets()){
                cowboy->shoot(enemy);
            }
            else{
                cowboy->reload();
            }
        }
    }
    else{
        throw std::runtime_error("dead enemy");
    }
}

// assitance function - attack by ninjas
void Team:: ninjas_attack(Character* character, Character* enemy){
    if(character->isAlive()){
        // casting
        Ninja* ninja = ((Ninja*)character);

        if(enemy->isAlive()){
            if(ninja->distance(enemy)<1){
                ninja->slash(enemy);
            }
            else{
                ninja->move(enemy);
            }
        }
   
    }
    else{
        throw std::runtime_error("dead enemy");
    }
}


// return vector
vector<Character*> Team:: get_characters(){
    return this->warriors;
}

// set character in vector
void Team:: set_character(Character* character){
    if (character == nullptr) {
        throw std::runtime_error("Invalid character pointer");
    }
    this->warriors.push_back(character);
    character->set_in_team(true);
}

// find new team leader
Character* Team:: find_new_leader(){
    double minimum = numeric_limits<double>:: max();
    Character* newlead;

    // attack with cowboys  
    for(Character* character : this->warriors){
        if(character->isAlive()){
            double current_dis = character->distance(this->team_leader);
            // update min distance    
            if(current_dis < minimum){
                minimum = current_dis;
                newlead = character;
            }
        }
    }
    return newlead;    
}


// set team leader
void Team:: set_team_leader(Character* new_leader){
    this->team_leader = new_leader;
}


// return currnt team leader
Character* Team:: get_team_leader(){
    return this->team_leader;
}


// set team leader
void Team:: set_character_counter(int num){
    this->character_counter += num;
}


// return currnt team leader
int Team:: get_character_counter(){
    return this->character_counter;
}
