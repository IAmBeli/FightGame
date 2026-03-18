#pragma once
#include<iostream>
#include<string>
using namespace std;
class Character{
protected:
    string name;
    int health;
    int damage;
public:
    Character(string n, int h, int d);  
    virtual void takeDamage(int amount);
    void healHP(int amount);
    void printStatus()const;
    virtual void attack(Character& other);
    bool isAlive() const;
    string getName()const;
    int getHealth()const;
    int getDamage()const;
};