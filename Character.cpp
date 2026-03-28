#include"Character.h"
#include<ctime>
#include<cstdlib>
#include<cmath>
Character::Character(string n, int h, int d, int p) : name(n), health(h), maxHealth(h), damage(d), potions(p), isDefending(false) {}
void Character::takeDamage(int amount){
        if((rand % 100) < dodgeChance){
            cout << "[ Miss! ] " << name << " gracefully dodged the attack!" << endl; 
        }
        if(isDefending){
            amount /= 2;
            cout << "Shield blocked half of the damage!" << endl;
        }
        health -= amount;
        if(health < 0) health = 0;
        cout << name << " took " << amount << " damage. HP left: " << health << endl;
    }
void Character::healHP(int amount){
        health += amount;
        if(health > maxHealth) health = maxHealth;
        cout << name << " has healed " << amount << " HP. HP left: " << health << endl;
    }
void Character::increaseDamage(int amount){
    damage += amount;
}
void Character::printStatus()const{
        cout << "***** "<< name << " current status is: *****" << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << health << endl;
        cout << "DMG: " << damage << endl;
    }
void Character::attack(Character& other){
        int randomDamage = (damage - 5) + (rand() % 11);
        if((rand() % 100) < critChance){
            randomDamage *= 2;
            cout << "CRITICAL HIT!" << endl;
        }
        cout << name << " attacks " << other.getName() << " for " << randomDamage << "!" << endl;
        other.takeDamage(randomDamage);
    }
bool Character::isAlive() const{
        return health > 0;        
    }
void Character::usePotion(){
        if(potions > 0){
            cout << name << " drinks a healing potion..." << endl;
            healHP(50);
            potions--;
            cout << "Potions left: " << potions << endl;
        }else{
            cout << name << " reaches for the potion, but the bag empty" << endl;
        }
}
void Character::addPotion(int count){
    potions += count;
    cout << name << " found " << count << " potion(s)! Total potions: " << potions << endl;
}
void Character::defend(){
    isDefending = true;
    cout << name << " takes a defensive stance! Incoming damage will be halved" << endl;
}
void Character::resetDefense(){
    isDefending = false;
}
void Character::gainEchoes(int amount){
    currentEchoes += amount;
    cout << "\n[ + " << amount << " shards of essence ]" << endl;
    while(currentEchoes >= echoesToNextLevel){
        triggerResonance();
    }
}
void Character::triggerResonance(){
    currentEchoes -= echoesToNextLevel;
    level++;
    maxHealth += 20;
    health = maxHealth;
    damage += 5;
    echoesToNextLevel = static_cast<int>(100 * pow(level, 1.5));
    cout << "\n>>> Resonance: level " << level << " <<<" << endl;
    cout << "Your essence is stregthening. Your HP and damage increased!" << endl;
}
void Character::addGold(int amount){
    gold += amount;
}
bool Character::spendGold(int amount){
    if(gold > amount){
        gold -= amount;
        return true;
    }
    return false;
}
int Character::getGold()const{return gold;}
string Character::getName()const{return name;}
int Character::getHealth()const{return health;}
int Character::getDamage()const{return damage;}
int Character::getPotions()const{return potions;}
int Character::getLevel()const{return level;}