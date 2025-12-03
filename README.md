# 🕹 Obstacle Dodging Game — C Programming Project

This repository contains my *Obstacle Dodging Game* written in C for the Windows console.  
The project demonstrates concepts such as *functions, **structures, **keyboard input handling, **randomization, and **game loop logic*.  
It also includes Windows-friendly improvements like *sound effects, **dynamic speed, and **level progression*.

---

## 📂 Folder Structure
---

## 🎯 Project Objective

### 🧩 Objective — Create a Console-Based Obstacle Dodging Game

This project focuses on learning and applying:

- Real-time keyboard input (_kbhit(), getch())
- Randomized obstacle generation
- Game loops & frame-based animation
- Collision detection
- Use of structures (struct Obstacle)
- Sound integration using Beep()
- Dynamic difficulty (levels + speed)
- Clean console rendering using system("cls")

---

## 🕹 Game Features

### ✔ Windows 11 Compatible  
Improved console rendering, no unsupported ASCII issues.

### ✔ Player Movement  
Move left or right across 3 lanes using:
- *Arrow keys*
- *A / D keys*

### ✔ Obstacles  
- Spawns in a random lane  
- Random symbol (# or X)  
- Smooth falling animation  

### ✔ Scoreboard  
Displayed live:
- Lives  
- Level  
- Speed  
- Total dodged obstacles  

### ✔ Sound Effects  
- Move  
- Hit  
- Level Up  
- Game Over  

---

## 📄 File Descriptions

### *main.c*
The *final Windows-compatible version* including:
- Sound effects  
- Levels and speed system  
- Collision handling  
- Scoreboard  
- Improved obstacle logic  

### *ORIGINAL.c*
The *first simple implementation* with:
- Single ASCII obstacle  
- No sound  
- No levels or lives  
- Basic movement  

Included to show progress and improvement.

---

## ⚙ How to Compile and Run

### ✅ Using GCC (MinGW / WinLibs / TDM-GCC)

Open the game folder, then run:

```bash
gcc main.c -o game.exe
./game.exe
LIVES: 3   LEVEL: 1   SPEED: 110ms   DODGED: 0
|--- --- ---|
|     #     |
|           |
|           |
|           |
|           |
|           |
|           |
|           |
|           |
|     @     |
🧾 Author Details

Name: Adarsh Raj
Course: B.Tech in Computer Science and Engineering (CSE)
Semester: 1st Year
State: Bihar
Category: EWS
GitHub: AdarshRaj25
