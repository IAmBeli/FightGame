#include"Mage.h"
#include<iostream>
#include<string>
using namespace std;
Mage::Mage(string n, int h, int d, int p, int m) : Character(n, h, d, p), mana(m), maxMana(m) {}
void Mage::attack(Character& other){
        if(mana >= 10){
            cout << name << " casts a FIREBALL at " << other.getName() << "!" << endl;
            int magicDamage = damage * 2;
            other.takeDamage(magicDamage);
            mana -= 10;
            cout << "Mana left: " << mana << endl; 
        }else{
            cout << "Not enough mana! " << name << " hits weakly with a staff" << endl;
            Character::attack(other);
        }
}
void Mage::restoreMana(int amount){
    mana += amount;
    if(mana > maxMana) mana = maxMana;
    cout << name << " meditated and restored " << amount << " mana! Current mana: " << mana << endl;
}
void Mage::triggerResonance(){
    Character::triggerResonance();
    maxMana += 15;
    mana = maxMana;
    cout << "Your magic abilities are increasing. Max mana: " << maxMana << endl;
}