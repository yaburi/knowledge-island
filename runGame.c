// runGame.c
// 
// Nathan Zhen, Jack Abroon, Holly Ahel and Jessica Chen

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Game.h"

#define WINNING_KPI 150

#define SPINOFF_LOWER 0
#define SPINOFF_UPPER 2
#define SPINOFF_IP 0

action decideAction (Game g);
int rollDice (void);
int spinoffDice (int lower, int higher);

int main (int argc, char *argv[]) {
    int disciplines[] = DEFAULT_DISCIPLINES;
    int dice[] = DEFAULT_DICE;
    Game g = newGame (disciplines[], dice[]);
    int currentPlayer = UNI_A;

    while (getKPI(g, currentPlayer) < WINNING_KPI) {
        diceValue = rollDice(); //simulate throw of two dice
        throwDice (g, diceValue);
        action move = decideAction (g);    // implemented in mechanicalTurk.c
       
        //loop until player action is PASS
        while (move.actionCode != PASS) {
            assert(isLegalAction (g,move) == TRUE);
            if (move.actionCode == START_SPINOFF) {
                diceValue = spinoffDice (SPINOFF_LOWER, SPINOFF_UPPER);
                if (diceValue == SPINOFF_IP) {
                    move.actionCode = OBTAIN_IP_PATENT;
                } else {
                    move.actionCode = OBTAIN_PUBLICATION;
                }
            }
            makeAction (g, move);
            move = decideAction (g);
        }
        currentPlayer = advancePlayer (currentPlayer); // cycle through A, B, C
    }
    return EXIT_SUCCESS;
}

action decideAction (Game g) {
    action a;

    scanf ("Please enter an action code: %d", &a.actionCode);

    if (a.actionCode == PASS) {
        printf ("%d has passed.\n" currentPlayer);
    } else if (a.actionCode == BUILD_CAMPUS) {
        printf ("Enter the destination path for campus (eg. LRL): ");
        scanf ("%s\n", a.destination);
    } else if (a.actionCode == BUILD_GO8) {
        printf ("Enter the destination path for GO8 (eg. LRL): ");
        scanf ("%s\n", a.destination);
    } else if (a.actionCode == OBTAIN_ARC) {
        printf ("Enter the destination path for ARC (eg. LRL): ");
        scanf ("%s\n", a.destination);
    } else if (a.actionCode == RETRAIN_STUDENTS) {
        printf ("Enter the student type to retrain from: ");
        scanf ("%d\n", &a.disciplineFrom);
        printf ("Enter the student type to retrain to: ");
        scanf ("%d\n", &a.disciplineTo);
    }

    return a;
}

int rollDice (void) {
    int val;
    printf ("Enter a value between 2 and 12: ");
    scanf ("%d", &val);

    return val;

}

int spinoffDice (int lower, int upper) {
    int val;
    printf ("Enter a value between %d and %d: ", lower, upper);
    scanf ("%d", &val);

    return val;
}