#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include"Mage.h"
#include"Warrior.h"
using namespace std;
int main(){
    srand(time(0));
    Mage hero("Beli (Mage)", 100, 20, 3, 30);
    Warrior enemy("Goblin (Warrior)", 120, 15, 1, 5);
    cout << "===================" << endl;
    cout << "-- Battle begins --" << endl;
    cout << "===================" << endl;
    while(hero.isAlive() && enemy.isAlive()){
        hero.resetDefense();
        cout << "\n=== Your turn! ===" << endl;
        hero.printStatus();
        cout << "1: Attack / Cast spell" << endl;
        cout << "2: Use potion" << endl;
        cout << "3: Defend" << endl;
        cout << "Choose action(1, 2 or 3): ";
        int choice;
        cin >> choice;
        cout << endl;
        if(choice == 1){
            hero.attack(enemy);
        }else if(choice == 2){
            hero.usePotion();
        }else if(choice == 3){
            hero.defend();
        }else{
            cout << "You stumbled and lost your turn!" << endl;
        }
        if(enemy.isAlive()){
            cout << "\n=== Enemy's turn! ===" << endl;
            enemy.resetDefense();
            if(enemy.getHealth() < 30 && enemy.getPotions() > 0){
                enemy.usePotion();
            }else{enemy.attack(hero);}
        }
    }
    cout << "\n======================================" << endl;
    if(!enemy.isAlive()){
        cout << "   " << hero.getName() << " won this fight!" << endl;
    }else if(!hero.isAlive()){
        cout << "   " << enemy.getName() << " won this fight!" << endl;
    }
    cout << "======================================" << endl;
    return 0;
}