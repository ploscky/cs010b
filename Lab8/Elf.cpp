#include <string>
#include <iostream>
#include "Character.h"
#include "Elf.h"

using namespace std;

//constructor
Elf::Elf(const string& name, double health, double attackStrength, const string& familyName)
    : Character(ELF, name, health, attackStrength),
      familyName(familyName)
{
}

//attack function
void Elf::attack(Character& charName) {
    if (charName.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(charName);
        if (opp.familyName == familyName) {
            cout << "Elf " << name << " does not attack Elf " << charName.getName() << '.' << endl;
            cout << "They are both members of the " << opp.familyName << " family." << endl;
            return;
        }
    }
    double damageDone = (health / MAX_HEALTH) * attackStrength;
    charName.damage(damageDone);
    cout << "Elf " << name << " shoots an arrow at " << charName.getName() << " --- TWANG!!" << endl;
    cout << charName.getName() << " takes " << damageDone << " damage." << endl;
}
