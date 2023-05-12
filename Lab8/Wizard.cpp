#include <string>
#include <iostream>
#include "Character.h"
#include "Wizard.h"

using namespace std;

//constructor
Wizard::Wizard(const string& name, double health, double attackStrength, int rank)
    : Character(WIZARD, name, health, attackStrength),
      rank(rank)
{
}

//attack function
void Wizard::attack(Character& charName) {
    double damageDone;
    if (charName.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(charName);
        damageDone = (attackStrength) * (static_cast<double>(rank)/(opp.rank));
        charName.damage(damageDone);
        cout << "Wizard " << name << " attacks " << charName.getName() << " --- POOF!!" << endl;
        cout << charName.getName() << " takes " << damageDone << " damage." << endl;
        return;
    }
    else {
        damageDone = attackStrength;
        charName.damage(damageDone);
    }
    cout << "Wizard " << name << " attacks " << charName.getName() << " --- POOF!!" << endl;
    cout << charName.getName() << " takes " << damageDone << " damage." << endl;
}