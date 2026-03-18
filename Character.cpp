#include"Character.h"
#include<ctime>
#include<cstdlib>
Character::Character(string n, int h, int d) : name(n), health(h), damage(d) {}
void Character::takeDamage(int amount){
        health -= amount;
        if(health < 0) health = 0;
        cout << name << " took " << amount << " damage. HP left: " << health << endl;
    }
void Character::healHP(int amount){
        health += amount;
        if(health > 100) health = 100;
        cout << name << " has healed " << amount << " HP. HP left: " << health << endl;
    }
void Character::printStatus()const{
        cout << "***** "<< name << " current status is: *****" << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << health << endl;
        cout << "DMG: " << damage << endl;
    }
void Character::attack(Character& other){
        int randomDamage = (damage - 5) + (rand() % 11);
        if((rand() % 10) < 2){
            randomDamage *= 2;
            cout << "CRITICAL HIT!" << endl;
        }
        cout << name << " attacks " << other.getName() << " for " << randomDamage << "!" << endl;
        other.takeDamage(randomDamage);
    }
bool Character::isAlive() const{
        return health > 0;        
    }
string Character::getName()const{return name;}
int Character::getHealth()const{return health;}
int Character::getDamage()const{return damage;}