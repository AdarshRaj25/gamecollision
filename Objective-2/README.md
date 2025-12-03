 🎰 Lottery Game — C Programming Project (Windows Console)

This project is a *Windows-console based Lottery Game* written in C.  
It demonstrates real-time effects, sound integration, animations, input handling, arrays, and game loop logic.  
The player enters 3 numbers, and the game compares them to randomly generated lottery numbers.  
Includes *lives, levels, speed changes, animations, and sound effects*.

---

## 📂 Folder Structure
 ---

## 🎯 Objective

Create an *interactive lottery game* that includes:

- User input of 3 lottery numbers
- Random number generation
- Lives system (3 lives)
- Level progression every 5 plays
- Speed increases based on levels
- Sound effects for win / good match / loss
- Animated “Processing...” loading spinner
- Real-time console updates using system("cls") and Sleep()

---

## 🧩 Game Features

### ✔ Enter 3 numbers (1–9)
The game compares your numbers to the computer’s lottery numbers.

### ✔ Sound Effects  
- *Good Match* → short beep  
- *No Match* → low beep  
- *Jackpot* → winning sound  
- *Game Over* → descending tone  

### ✔ Lives System  
You start with *3 lives*.  
Every “no match” reduces one life.

### ✔ Jackpot Condition  
If *all 3 numbers match*, the game ends with a JACKPOT win.

### ✔ Level System  
- Every *5 plays* increases your *level*  
- Speed increases (faster rounds)  

### ✔ Visual Animation  
A spinning “Processing…” animation gives the game a dynamic feel.

---

## ⚙ How to Compile and Run (Windows)

Use *MinGW, **WinLibs, or **TDM-GCC*.

Compile:

```bash
gcc Lottery.c -o lottery.exe
 ./lottery.exe
LIVES: 3   LEVEL: 1   SPEED: 150ms   PLAYS: 0
+-------------------------+
|   LOTTERY GAME (1-9)    |
+-------------------------+

Enter 3 numbers:
Num 1: 4
Num 2: 9
Num 3: 2
[12/3/2025 3:32 PM] Adarsh: LOTTERY: [4 3 2]
YOU GUESSED: [4 9 2]

GOOD TRY! 2 numbers matched.
