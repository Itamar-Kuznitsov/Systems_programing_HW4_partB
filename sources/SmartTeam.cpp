#include "SmartTeam.hpp"
#include "Team2.hpp"
using namespace ariel;

// constructor
SmartTeam:: SmartTeam(Character* team_leader_)
    : Team2(team_leader_){}


// print all team members 
void SmartTeam:: print_SmartTeam(){
    cout << "This is SmartTeam" << endl;
}
