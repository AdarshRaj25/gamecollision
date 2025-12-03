#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void soundGood() { Beep(1500, 80); }
void soundBad()  { Beep(400, 200); }
void soundWin()  { Beep(900, 150); Beep(1100, 200); }
void soundGameOver() { Beep(600, 200); Beep(300, 250); }

void showProcessing() {
    char spin[4] = {'|', '/', '-', '\\'};
    for (int i = 0; i < 12; i++) {
        system("cls");
        printf("Checking Result...\n\n");
        printf("PLEASE WAIT %c\n", spin[i % 4]);
        Sleep(120);
    }
}

int main() {
    srand((unsigned int)time(NULL));

    int lives = 3;
    int level = 1;
    int speed = 150;
    int plays = 0;

    int lottery[3];
    int guess[3];

    for (int i = 0; i < 3; i++) {
        lottery[i] = (rand() % 9) + 1;
    }

    while (1) {

        system("cls");
        printf("LIVES: %d   LEVEL: %d   SPEED: %dms   PLAYS: %d\n", 
                lives, level, speed, plays);

        printf("+-------------------------+\n");
        printf("|   LOTTERY GAME (1-9)    |\n");
        printf("+-------------------------+\n");
        printf("Press ENTER to enter numbers...\n");
        getchar();  // waits for enter

        system("cls");
        printf("Enter 3 numbers (1 to 9):\n");

        for (int i = 0; i < 3; i++) {
            printf("Num %d: ", i + 1);
            scanf("%d", &guess[i]);
        }
        getchar(); // clear buffer

        plays++;

        showProcessing();

        int match = 0;
        for (int i = 0; i < 3; i++)
            if (guess[i] == lottery[i]) match++;

        system("cls");
        printf("LOTTERY: [%d %d %d]\n", lottery[0], lottery[1], lottery[2]);
        printf("YOU GUESSED: [%d %d %d]\n", guess[0], guess[1], guess[2]);

        if (match == 3) {
            printf("\nJACKPOT!!! All numbers matched!\n");
            soundWin();
            Sleep(500);
            return 0;
        }
        else if (match > 0) {
            printf("\nGOOD TRY! %d numbers matched.\n", match);
            soundGood();
        }
        else {
            printf("\nNO MATCH! You lose 1 life.\n");
            lives--;
            soundBad();
        }

        Sleep(400);

        if (lives == 0) {
            system("cls");
            printf("GAME OVER!\n");
            printf("TOTAL PLAYS: %d\n", plays);
            soundGameOver();
            return 0;
        }

        if (plays % 5 == 0) {
            level++;
            if (speed > 50) speed -= 15;
        }

        for (int i = 0; i < 3; i++) {
            lottery[i] = (rand() % 9) + 1;
        }

        Sleep(speed);
    }

    return 0;
}
