#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include"Mage.h"
#include"Warrior.h"
using namespace std;
int main(){
    srand(time(0));
    Mage hero("Beli (Mage)", 130, 20, 3, 30);
    vector<Warrior> arenaEnemies;
    arenaEnemies.push_back(Warrior("Goblin scavanger", 60, 10, 0, 2));
    arenaEnemies.push_back(Warrior("Orc bruiser", 100, 15, 1, 5));
    arenaEnemies.push_back(Warrior("Troll boss", 150, 25, 2, 10));
    cout << "===================" << endl;
    cout << "-- Battle begins --" << endl;
    cout << "===================" << endl;
    int wave = 1;
    for(Warrior& enemy : arenaEnemies){
        cout << "\n==============================" << endl;
        cout << "Wave " << wave << ": " << enemy.getName() << " approaches!" << endl;
        cout << "==============================" << endl;
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
                }else{
                    enemy.attack(hero);
                }
            }
        }
        if(!hero.isAlive()){
            cout << "\n" << hero.getName() << " was defeated on wave "  << wave << "..." << endl;
            break; 
        }else{
            cout << "\n" << enemy.getName() << " is dead! You take a quick breath." << endl;
            hero.healHP(20);
            hero.restoreMana(15);
            if(enemy.getPotions() > 0){
                cout << "You search the body and find a potion!" << endl;
                hero.addPotion(enemy.getPotions());
            }else{
                hero.addPotion(1);
            }
            wave++;
        }
    }
    if(hero.isAlive()){
        cout << "\n==============================" << endl;
        cout << "Incredible " << hero.getName() << " has cleared the arena!" << endl;
        cout << "==============================" << endl;
    }
    return 0;
}