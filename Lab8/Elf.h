#pragma once
#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

class Elf : public Character {
    public:
        Elf(const string& name, double health, double attackStrength, const string& familyName);
        void attack(Character& charName) override;
        
    private:
        string familyName;
};