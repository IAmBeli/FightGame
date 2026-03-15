#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
class Player{
private:
    string name;
    int health;
    int damage;
public:
    Player(string n, int h, int d) : name(n), health(h), damage(d) {}
    void takeDamage(int amount){
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
    void attack(Player& other){
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
int main(){
    srand(time(0));
    Player hero("Beli", 100, 20);
    Player enemy("Goblin", 50, 10);
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
}