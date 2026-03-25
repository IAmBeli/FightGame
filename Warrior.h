#pragma once
#include"Character.h"
#include<iostream>
#include<string>
using namespace std;
class Warrior : public Character{
private:
    int armor;
public:
    Warrior(string n, int h, int d, int p, int a);
    void takeDamage(int amount)override;
    void triggerResonance()override;
};