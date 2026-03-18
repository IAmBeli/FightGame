#include"Warrior.h"
#include<iostream>
#include<string>
using namespace std;
Warrior::Warrior(string n, int h, int d, int a) : Character(n, h, d), armor(a) {}
void Warrior::takeDamage(int amount){
    amount -= armor;
    if(amount <= 0){
        cout << "Armor saved " << name << " from damage!" << endl;
    }else{
        Character::takeDamage(amount);
    }
}