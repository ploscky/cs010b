#pragma once
#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

class Warrior : public Character {
    public:
        Warrior(const string& name, double health, double attackStrength, const string& allegiance);
        void attack(Character& charName) override;
        
    private:
        string allegiance;
};