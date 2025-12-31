#ifndef QUEST_H    // If "QUEST_H" has not been defined yet...
#define QUEST_H    // ...define it now.
#include <string>

// Global constants
const int MAX_HEALTH = 100;
const int MAX_STAMINA = 150;
const int MAX_RATIONS = 100;

// --- Utility Function Prototypes ---
void displayMenu();
int getValidInput(int min, int max);
void trek(int &stamina, int &rations, int &dist);
void forage(int &stamina, int &rations, int &health, int &dust);
void visitFountain(int &health, int &dust, int &stamina);
void trade(int &rations, int &dust);
void showStatus(int stamina, int rations, int health, int dist, int dust);
void saveQuest(int stamina, int rations, int health, int dist, int dust);
void loadQuest(int &stamina, int &rations, int &health, int &dist, int &dust);
void helpAndInstructions();

#endif