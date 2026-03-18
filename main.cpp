#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include"Mage.h"
#include"Warrior.h"
using namespace std;
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