#include"Mage.h"
#include<iostream>
#include<string>
using namespace std;
Mage::Mage(string n, int h, int d, int p, int m) : Character(n, h, d, p), mana(m) {}
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
    if(mana > 40) mana = 40;
    cout << name << " meditated and restored " << amount << " mana! Current mana: " << mana << endl;
}