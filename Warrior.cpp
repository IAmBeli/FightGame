#include"Warrior.h"
#include<iostream>
#include<string>
using namespace std;
Warrior::Warrior(string n, int h, int d, int p, int a) : Character(n, h, d, p), armor(a) {}
void Warrior::takeDamage(int amount){
    amount -= armor;
    if(amount <= 0){
        cout << "Armor saved " << name << " from damage!" << endl;
    }else{
        Character::takeDamage(amount);
    }
}
void Warrior::triggerResonance(){
    triggerResonance();
    armor += 5;
    cout << "Steel responds to your call. Armor is upgraded: " << armor << endl;
    cout << "Now you feel attacks of enemies like light touches" << endl;
}