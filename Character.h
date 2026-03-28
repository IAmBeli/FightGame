#pragma once
#include<iostream>
#include<string>
using namespace std;
class Character{
protected:
    string name;
    int health;
    int maxHealth;
    int damage;
    int potions;
    int gold = 0;
    bool isDefending;
    int level = 1;
    int currentEchoes = 0;
    int echoesToNextLevel = 100;
    int critChance = 15;
    int dodgeChance = 10;
public:
    Character(string n, int h, int d, int p);  
    virtual void takeDamage(int amount);
    void healHP(int amount);
    void increaseDamage(int amount);
    void printStatus()const;
    virtual void attack(Character& other);
    bool isAlive() const;
    void usePotion();
    void addPotion(int count);
    void defend();
    void resetDefense();
    void gainEchoes(int amount);
    virtual void triggerResonance();
    void addGold(int amount);
    bool spendGold(int amount);
    int getGold()const;
    string getName()const;
    int getHealth()const;
    int getDamage()const;
    int getPotions()const;
    int getLevel()const;
};