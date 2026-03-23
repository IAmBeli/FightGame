#pragma once
#include"Character.h"
#include<iostream>
#include<string>
using namespace std;
class Mage : public Character{
private:
    int mana;
public:
    Mage(string n, int h, int d, int p, int m);
    void attack(Character& other)override;
    void restoreMana(int amount);
};