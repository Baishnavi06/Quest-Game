#include <iostream>
#include <string>
#include <ctime>
#include "Quest.h" // Crucial: Link to your header

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random encounters

    // Base Variables
    int stamina, rations, health, leaguesToCastle, magicDust;
    int choice = 0; 

    cout << "========================================" << endl;
    cout << "   QUEST FOR THE GOLDEN CASTLE   " << endl;
    cout << "========================================" << endl;
    cout << "A mystical journey across the Fairy Realm." << endl;


    // --- DIFFICULTY SELECTION LOGIC ---
    cout << "Choose your path, Traveler:" << endl;
    cout << "1. Squire (Easy - Plenty of supplies)" << endl;
    cout << "2. Knight (Normal - Balanced challenge)" << endl;
    cout << "3. Legend (Hard - Survival is unlikely)" << endl;
    cout << "> ";
    
    int difficulty = getValidInput(1, 3); // using validation function

    if (difficulty == 1) {
        // Easy Mode
        stamina = 150;
        rations = 100;
        health = 100;
        leaguesToCastle = 300;
        magicDust = 30;
        cout << "\nYou begin with an overflowing pack. The road is short." << endl;
    } 
    else if (difficulty == 2) {
        // Normal Mode
        stamina = 100;
        rations = 50;
        health = 100;
        leaguesToCastle = 500;
        magicDust = 10;
        cout << "\nYou begin your quest with standard gear." << endl;
    } 
    else if (difficulty == 3){
        // Hard Mode
        stamina = 60;
        rations = 20;
        health = 80;
        leaguesToCastle = 800;
        magicDust = 0;
        cout << "\nYou are a weary traveler. The castle is a lifetime away." << endl;
    } else {
        cout << "\nERROR: choose 1-3 difficulty option or restart the game." << endl;
    }

    // ... The rest of the game loop starts here ...
    // Main Game Loop
    do {
        displayMenu();
        choice = getValidInput(1, 8); // reusing validation function

        switch (choice) {
            case 1: trek(stamina, rations, leaguesToCastle); break;
            case 2: forage(stamina, rations, health, magicDust); break;
            case 3: visitFountain(health, magicDust, stamina); break;
            case 4: trade(rations, magicDust); break;
            case 5: showStatus(stamina, rations, health, leaguesToCastle, magicDust); break;
            case 6: saveQuest(stamina, rations, health, leaguesToCastle, magicDust); break;
            case 7: loadQuest(stamina, rations, health, leaguesToCastle, magicDust); break;
            case 8: cout << "The journey ends here. Farewell, traveler." << endl; return 0;
            default: cout << "ERROR: wrong inputs, please try again." << endl; break;
        }

        // Win/Loss Logic
        if (leaguesToCastle <= 0) {
            cout << "\n*** VICTORY! You have reached the Golden Castle! ***" << endl;
            break;
        } else if (stamina <= 0 || rations <= 0 || health <= 0) {
            cout << "\n--- DEFEAT: You collapsed in the Whispering Woods... ---" << endl;
            break;
        } else {
            continue;
        }

    } while (choice != 8);

    return 0;
}

