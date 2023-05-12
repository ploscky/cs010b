#include <string>
#include "Character.h"

using namespace std;

//constructor
Character::Character(HeroType type, const string &name, double health, double attackStrength) 
  : type(type),
    name(name),
    health(health),
    attackStrength(attackStrength)
{ 
}

//getType
HeroType Character::getType() const {
  return type;
}

//getName
const string & Character::getName() const {
  return name;
}

//getHealth-- Returns the whole number of the health value (static_cast to int)
int Character::getHealth() const {
  return static_cast<int>(health);
}

//damage-- Reduces health value by amount passed in
void Character::damage(double d) {
  health = health - d;
}

//isAlive-- Returns true if getHealth() returns an integer greater than 0, otherwise false
bool Character::isAlive() const {
  return (getHealth() > 0);
}