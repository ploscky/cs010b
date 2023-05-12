#include <string>
#include <iostream>
#include "Character.h"
#include "Warrior.h"

using namespace std;

//constructor
Warrior::Warrior(const string& name, double health, double attackStrength, const string& allegiance)
    : Character(WARRIOR, name, health, attackStrength),
      allegiance(allegiance)
{
}

//attack function
void Warrior::attack(Character& charName) {
    if (charName.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(charName);
        if (opp.allegiance == allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << charName.getName() << '.' << endl;
            cout << "They share an allegiance with " << opp.allegiance << '.' << endl;
            return;
        }
    }
    double damageDone = (health / MAX_HEALTH) * attackStrength;
    charName.damage(damageDone);
    cout << "Warrior " << name << " attacks " << charName.getName() << " --- SLASH!!" << endl;
    cout << charName.getName() << " takes " << damageDone << " damage." << endl;
}
