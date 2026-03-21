#pragma once
#include<iostream>
#include<string>
using namespace std;
class Character{
protected:
    string name;
    int health;
    int damage;
    int potions;
    bool isDefending;
public:
    Character(string n, int h, int d, int p);  
    virtual void takeDamage(int amount);
    void healHP(int amount);
    void printStatus()const;
    virtual void attack(Character& other);
    bool isAlive() const;
    void usePotion();
    void defend();
    void resetDefense();
    string getName()const;
    int getHealth()const;
    int getDamage()const;
    int getPotions()const;
};