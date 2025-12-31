/*
 * Project: Quest for the Golden Castle Game
 * Author: Baishnavi Kumari
 * Course: Coursera C++ Fundamentals
 * Description: A resource-management RPG demonstrating loops, functions, file I/O, and input validation.
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <limits>
#include "Quest.h" // Crucial: Link to header files

using namespace std;

// --- Display Menu ---
void displayMenu() {
    cout << "\n1. Trek Toward Castle (-Stamina, -Rations)" << endl;
    cout << "2. Forage for Supplies (Random Encounter)" << endl;
    cout << "3. Visit Healing Fountain (Costs 15 Magic Dust)" << endl;
    cout << "4. Trade Magic Dust for Rations" << endl;
    cout << "5. Check Adventurer Stats" << endl;
    cout << "6. Save Quest" << endl;
    cout << "7. Load Quest" << endl;
    cout << "8. Give Up" << endl;
    cout << "Enter Choice: ";
}

// --- Input Validation (Best Practice) ---
int getValidInput(int min, int max) {
    int input;
    while (!(cin >> input) || input < min || input > max) {
        cout << "Please enter a valid number (" << min << "-" << max << "): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

// --- Trek Logic (Arithmetic) ---
void trek(int &stamina, int &rations, int &dist) {
    cout << "\nYou march forward bravely..." << endl;
    stamina -= 15;
    rations -= 10;
    dist -= 50;
    cout << "You are 50 leagues closer to the castle." << endl;
}

// --- Forage Logic (Randomness & Switch-Case) ---
void forage(int &stamina, int &rations, int &health, int &dust) {
    cout << "\nYou search the enchanted thicket..." << endl;
    int event = (rand() % 4); // 0 to 3

    switch(event) {
        case 0:
            cout << "You found a pouch of Magic Dust! (+10 Dust)" << endl;
            dust += 10;
            break;
        case 1:
            cout << "A swarm of pixies stole your lunch! (-15 Rations)" << endl;
            rations -= 15;
            break;
        case 2:
            cout << "A thorny briar scratched you! (-10 Health)" << endl;
            health -= 10;
            break;
        case 3:
            cout << "You found some wild berries. (+10 Rations)" << endl;
            rations += 10;
            break;
    }
    stamina -= 5;
}

// --- Healing Logic ---
void visitFountain(int &health, int &dust, int &stamina) {
    if (dust >= 15) {
        if (health < MAX_HEALTH){
            dust -= 15;
            health = 100;
            cout << "\nThe shimmering waters restore your life force!" << endl;
        } else {
            cout << "\n You are already full of life force!" << endl;
        }
        if (stamina < MAX_STAMINA) {
            stamina = 100;
            cout << "\nThe shimmering waters restore your stamina to trek!" << endl;
        } else {
            cout << "\n You are already full of energy to trek!" << endl;
        }
    } else {
        cout << "\nThe fountain is dry. You need more Magic Dust." << endl;
    }
}

// --- Trade Logic ---
void trade(int &rations, int &dust) {
    if (dust >= 5) {
        if (rations < MAX_RATIONS) {
            dust -= 5;
            rations += 15;
            cout << "\nYou traded 5 Dust for 15 Rations with a wandering gnome." << endl;
        } else {
            cout << "\n You have maximum rations, thus no trade allowed." << endl;
        }
    } else {
        cout << "\nThe gnome laughs at your empty pockets." << endl;
    }
}

// --- Status Report (Output Formatting) ---
void showStatus(int stamina, int rations, int health, int dist, int dust) {
    cout << "\n--- ADVENTURER LOG ---" << endl;
    cout << "Status: Walking the path to glory..." << endl;
    cout << "Health:  [" << health << "%]" << endl;
    cout << "Stamina: [" << stamina << "%]" << endl;
    cout << "Rations: [" << rations << " units]" << endl;
    cout << "Dust:    [" << dust << " oz]" << endl;
    cout << "Distance to Castle: " << dist << " leagues" << endl;
    cout << "----------------------" << endl;
}

// --- Save Logic (File I/O) ---
void saveQuest(int stamina, int rations, int health, int dist, int dust) {
    ofstream saveFile("quest_save.txt");
    if (saveFile.is_open()) {
        saveFile << stamina << " " << rations << " " << health << " " << dist << " " << dust;
        saveFile.close();
        cout << "\nProgress etched into the crystal stone (Saved)." << endl;
    }
}

// --- Load Logic (File I/O) ---
void loadQuest(int &stamina, int &rations, int &health, int &dist, int &dust) {
    ifstream loadFile("quest_save.txt");
    if (loadFile.is_open()) {
        loadFile >> stamina >> rations >> health >> dist >> dust;
        loadFile.close();
        cout << "\nVision from the past restored (Loaded)." << endl;
    } else {
        cout << "\nNo previous journey found." << endl;
    }
}

// --- Help and Instructions ---
void helpAndInstructions() {
    cout << "\n ==== HELP AND INSTRUCTIONS ====" << endl;
    cout << "1. Trek needs 15 Stamina, 10 Rations to travel 50 leagues towards castle." << endl;
    cout << "2. Forage is a Random Encounter (takes 5 stamina) where you can get either get dust or ration, or loss ration or health." << endl;
    cout << "3. Healing Fountain Costs 15 Magic Dust to give 100 health and 100 stamina." << endl;
    cout << "4. Trade need 5 Magic Dust for 15 Rations" << endl;
    cout << "5. Check Adventurer Stats shows report of supplies and distance left to castle." << endl;
    cout << "6. Save Quest save your current stats." << endl;
    cout << "7. Load Quest loads your saved stats." << endl;
    cout << "difficulty level decides the player stats." << endl;
    cout << "You win when you reach the castle." << endl;
    cout << "You lose when you run out of supplies or stamina." << endl;
    cout << "Happy Gaming!! " << endl;
}
