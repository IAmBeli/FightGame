#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
class Character{
protected:
    string name;
    int health;
    int damage;
public:
    Character(string n, int h, int d) : name(n), health(h), damage(d) {}
    virtual void takeDamage(int amount){
        health -= amount;
        if(health < 0) health = 0;
        cout << name << " took " << amount << " damage. HP left: " << health << endl;
    }
    void healHP(int amount){
        health += amount;
        if(health > 100) health = 100;
        cout << name << " has healed " << amount << " HP. HP left: " << health << endl;
    }
    void printStatus()const{
        cout << "***** "<< name << " current status is: *****" << endl;
        cout << "Name: " << name << endl;
        cout << "HP: " << health << endl;
        cout << "DMG: " << damage << endl;
    }
    virtual void attack(Character& other){
        int randomDamage = (damage - 5) + (rand() % 11);
        if((rand() % 10) < 2){
            randomDamage *= 2;
            cout << "CRITICAL HIT!" << endl;
        }
        cout << name << " attacks " << other.getName() << " for " << randomDamage << "!" << endl;
        other.takeDamage(randomDamage);
    }
    bool isAlive() const{
        return health > 0;        
    }
    string getName()const{return name;}
    int getHealth()const{return health;}
    int getDamage()const{return damage;}
};
class Mage : public Character{
private:
    int mana;
public:
    Mage(string n, int h, int d, int m) : Character(n, h, d), mana(m) {}
    void attack(Character& other)override{
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
};
class Warrior : public Character{
private:
    int armor;
public:
    Warrior(string n, int h, int d, int a) : Character(n, h, d), armor(a){}
    void takeDamage(int amount)override{
        amount -= armor;
        if(amount < 0){
            cout << "Armor saved " << name << " from damage!" << endl;
        }else{
            Character::takeDamage(amount);
        }
    }
};
int main(){
    srand(time(0));
    Mage hero("Beli", 100, 20, 30);
    Warrior enemy("Goblin", 120, 15, 5);
    cout << "-- Battle begins --" << endl;
    while(hero.isAlive() && enemy.isAlive()){
        hero.attack(enemy);
        if(enemy.isAlive()){
            enemy.attack(hero);
        }
    }
    if(enemy.isAlive() == 0){
        cout << "Hero won this fight!" << endl;
    }else if(hero.isAlive() == 0){
        cout << "Enemy won this fight!" << endl;
    }
    return 0;
}