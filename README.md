# Quest for the Golden Castle 🏰
An interactive C++ text-based adventure game set in the mystical Fairy Realm. Developed as a capstone project for the **C++ Fundamentals** course by Microsoft (via Coursera).

## 🌟 Project Overview
"Quest for the Golden Castle" is a survival-strategy game where players must manage resources—Stamina, Rations, and Health—to travel a set distance (Leagues) to reach safety. The game features a dynamic difficulty system and random encounters.

## 🛠️ Technical Features
- **Multi-File Architecture:** Organized using header files (`.h`) and implementation files (`.cpp`) for clean, modular code.
- **Input Validation:** Robust error-handling to ensure user inputs remain within expected ranges.
- **Resource Management System:** Logic-driven gameplay where player stats are affected by every decision.
- **File I/O:** Functionality to `Save` and `Load` quest progress, allowing for persistent gameplay.
- **Randomization:** Uses `srand` and `time` to create unpredictable outcomes during foraging and trekking.

## 🎮 How to Play
1. **Choose Your Difficulty:**
   - **Squire (Easy):** 300 leagues, high resources.
   - **Knight (Normal):** 500 leagues, balanced resources.
   - **Legend (Hard):** 800 leagues, survival is unlikely.
2. **Manage Your Actions:**
   - `Trek`: Advance toward the castle (consumes stamina and rations).
   - `Forage`: Search for supplies (risk/reward system).
   - `Fountain`: Use Magic Dust to restore health.
   - `Trade`: Exchange resources to survive.
3. **Win Condition:** Reach **0 Leagues** remaining.
4. **Lose Condition:** If your **Stamina, Rations, or Health** hit 0, the journey ends.

## 📁 File Structure
- `main.cpp`: Entry point containing the game loop and difficulty logic.
- `functions.cpp`: Implementation of game mechanics (trekking, foraging, saving).
- `header.h`: Function prototypes and shared variables.
- `plan.txt`: Original pseudocode and logic design.

## 🚀 Getting Started
To run this game locally:
1. Clone the repository:
   ```bash
   git clone [https://github.com/Baishnavi06/Quest-Game.git](https://github.com/Baishnavi06/Quest-Game.git)
