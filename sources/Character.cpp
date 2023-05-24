#include "Character.hpp"

using namespace ariel;

// constructor
Character:: Character(string name_, Point location_)
    : location(location_), name(name_){}

Character:: Character(){}


Character::Character(const Character& character)
    : name(character.name), location(character.location), hits_num(character.hits_num), in_team(character.in_team)
{}

Character::Character(Character&& character) noexcept
    : name(std::move(character.name)), location(std::move(character.location)),
      hits_num(character.hits_num), in_team(character.in_team){
    character.hits_num = 0;
    character.in_team = false;
}

Character& Character::operator=(Character&& other) noexcept{
    if (this == &other) {
        return *this;
    }

    name = std::move(other.name);
    location = std::move(other.location);
    hits_num = other.hits_num;
    in_team = other.in_team;

    other.hits_num = 0;
    other.in_team = false;

    return *this;
}

Character& Character::operator=(const Character& other){
    if (this == &other) {
        return *this;
    }

    name = other.name;
    location = other.location;
    hits_num = other.hits_num;
    in_team = other.in_team;

    return *this;
}


// return 1 if the character alive otherwise 0
bool Character:: isAlive(){
    return (this->hits_num > 0);
}

// calculate the sidtance between two characters 
double Character:: distance(Character* other_character){
    double distance = this->location.distance(other_character->location);
    return distance;
}

// substruct num of given hits form the character hits_num
void Character:: hit(int hits){ 
    if (hits < 0) {
        throw std::invalid_argument("Error: negative damage value");
    }
    this->hits_num-= hits;
}

// return the character name
string Character:: getName(){
    return this->name;
}

// return the character location
Point Character:: getLocation(){
    return this->location;
}

// set new character location
void Character:: setLocation(Point new_location){
    this->location = new_location;
}

void Character:: set_character_hit_points(int hit_points){
    this->hits_num = hit_points;
}

// set the character type - cowboy= 0, ninja= 1
void Character:: set_char_type(bool type){
    this->chartype = type;
}

// return the character type
bool Character:: get_char_type(){
    return this->chartype;
}

// retun number of hits
int Character:: get_hit_nums(){
    return this->hits_num;
}

// set the character type - cowboy= 0, ninja= 1
void Character:: set_in_team(bool stat){
    this->in_team = stat;
}

// return the character type
bool Character:: get_in_team(){
    return this->in_team;
}


