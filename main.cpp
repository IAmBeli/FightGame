#include<fstream>
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include"Mage.h"
#include"Warrior.h"
using namespace std;
void visitMerchant(Character& hero){
    int choice;
    while(true){
        cout << "\n===== Merchant shop =====" << endl;
        cout << "Your gold " << hero.getGold() << endl;
        cout << "1. Healing potion(50 gold)" << endl;
        cout << "2. Magic sharpening(+5 to DMG)(100 gold)" << endl;
        cout << "3. Leave merchant shop" << endl;
        cout << "Your choice: ";
        cin >> choice;
        if(choice == 1){
            if(hero.spendGold(50)){
                hero.addPotion(1);
            }else{
                cout << "Not enough gold" << endl;
            }
        }else if(choice == 2){
            if(hero.spendGold(100)){
                cout << "Your weapon sharpened!" << endl;
                hero.increaseDamage(5);
            }else{
                cout << "Not enough gold" << endl;
            }
        }else if(choice == 3){
            break;
        }
    }
}
int main(){
    srand(time(0));
    Mage hero("Beli (Mage)", 130, 20, 3, 30);
    cout << "1. New game" << endl;
    cout << "2. Load game" << endl;
    int startChoice;
    cin >> startChoice;
    if(startChoice == 2){
        hero.loadProgress("savegame.txt");
    }
    cout << "===================" << endl;
    cout << "-- Battle begins --" << endl;
    cout << "===================" << endl;
    int wave = 1;
    while(hero.isAlive()){
        string enemyName = "Dark shadow lvl " + to_string(wave);
        int enemyHP = 50 + (wave * 15);
        int enemyDMG = 8 + (wave * 3);
        Warrior enemy(enemyName, enemyHP, enemyDMG, 1, 2 + wave);
        cout << "\n--- Wave " << wave << " ---" << endl;
        cout << enemyName << " Stands in front of you!" << endl;
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
    if(hero.isAlive()){
        cout << "\nYou won " << enemyName << "! You earned some gold and gained experience" << endl;
        int xpReward = 50 + (wave * 20);
        int goldReward = 10 + (wave * 5);
        hero.gainEchoes(xpReward);
        hero.addGold(goldReward);
        cout << "Gold received: " << goldReward << " (Total: " << hero.getGold() << ")" << endl;
        visitMerchant(hero);
        wave++;
        cout << "Do you want to save your progress?(1 - yes, 0 - no): ";
        int saveChoice;
        cin >> saveChoice;
        if(saveChoice == 1){
            hero.saveProgress("savegame.txt");
        }
    }
}
if(!hero.isAlive()){
    cout << "\n==================" << endl;
    cout << "      GAME OVER     " << endl;
    cout << "==================" << endl;
    cout << "Final wave: " << wave << endl;
    cout << "Final level: " << hero.getLevel() << endl;
    cout << "Thanks for playing" << endl;
}
return 0;
}