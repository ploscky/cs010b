#pragma once
#include <string>
#include <iostream>
#include "Character.h"

using namespace std;

class Wizard : public Character {
    public:
        Wizard(const string& name, double health, double attackStrength, int rank);
        void attack(Character& charName) override;
        
    private:
        int rank;
};