#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

// ---- SOUND EFFECTS ----
void soundMove() { Beep(1800, 25); }
void soundHit()  { Beep(300, 160); Beep(200, 200); }
void soundLevelUp() { Beep(900, 120); Beep(1100, 150); }
void soundGameOver() {
    Beep(600, 200);
    Beep(300, 250);
}

// ---- SINGLE OBSTACLE STRUCT ----
typedef struct {
    int lane;   // 0=left,1=middle,2=right
    int y;      // vertical position (0..10)
    char sym;   // character used to draw it
    int active; // 1 = active (in play), 0 = not used (not needed here but kept for clarity)
} Obstacle;

int main() {
    srand((unsigned int)time(NULL));  // seed RNG

    int x = 1;           // player lane (0..2). start center
    int lives = 3;
    int speed = 110;     // milliseconds per frame (lower = faster)
    int level = 1;
    int dodged = 0;

    Obstacle obs;

    // initialize single obstacle
    obs.active = 1;
    obs.lane = rand() % 3;
    obs.y = 0;
    obs.sym = (rand() % 2) ? '#' : 'X';

    while (1) {

        // ---- INPUT (robust arrow handling) ----
        if (_kbhit()) {
            int ch = getch();
            if (ch == 0 || ch == 224) {    // handle extended keys (arrows)
                ch = getch();              // read actual code
                if (ch == 75 && x > 0) { x--; soundMove(); }   // LEFT
                if (ch == 77 && x < 2) { x++; soundMove(); }   // RIGHT
            }
            // optional: allow 'a'/'d' keys too
            else {
                if ((ch == 'a' || ch == 'A') && x > 0) { x--; soundMove(); }
                if ((ch == 'd' || ch == 'D') && x < 2) { x++; soundMove(); }
            }
        }

        // ---- DRAW ----
        system("cls");
        printf("LIVES: %d   LEVEL: %d   SPEED: %dms   DODGED: %d\n", lives, level, speed, dodged);
        printf("|--- --- ---|\n");

        for (int row = 0; row < 10; row++) {
            if (obs.active && obs.y == row) {
                if (obs.lane == 0)      printf("| %c        |\n", obs.sym);
                else if (obs.lane == 1) printf("|     %c    |\n", obs.sym);
                else                    printf("|        %c |\n", obs.sym);
            } else {
                printf("|           |\n");
            }
        }

        // player (always at bottom)
        if (x == 0)      printf("| @        |\n");
        else if (x == 1) printf("|     @    |\n");
        else             printf("|        @ |\n");

        // ---- COLLISION CHECK ----
        if (obs.active && obs.y == 10 && obs.lane == x) {
            lives--;
            soundHit();
            printf("\nHIT! Lives left: %d\n", lives);
            Sleep(250);

            if (lives == 0) {
                system("cls");
                printf("GAME OVER!\n");
                printf("TOTAL DODGED: %d\n", dodged);
                soundGameOver();
                return 0;
            }

            // reset obstacle immediately after hit
            obs.lane = rand() % 3;
            obs.y = 0;
            obs.sym = (rand() % 2) ? '#' : 'X';
            continue; // skip the normal move so the obstacle doesn't shift twice this frame
        }

        // ---- MOVE ----
        Sleep(speed);
        obs.y++;

        // ---- WHEN OBSTACLE PASSES BOTTOM (player dodged it) ----
        if (obs.y > 10) {
            dodged++;

            // level up every 10 dodges
            if (dodged % 10 == 0) {
                level++;
                soundLevelUp();
                if (speed > 40) speed -= 10; // make it faster
            }

            // respawn obstacle at top in a random lane
            obs.lane = rand() % 3;
            obs.y = 0;
            obs.sym = (rand() % 2) ? '#' : 'X';
        }
    }

    return 0;
}
