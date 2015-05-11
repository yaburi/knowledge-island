// runGame.c
// 
// Nathan Zhen, Jack Abroon, Holly Ahel and Jessica Chen

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "Game.h"

#define WINNING_KPI 150

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
                //decide if outcome is patent or publication
                
            }
            makeAction (g, move);
            move = decideAction (g);
        }
        currentPlayer = advancePlayer (currentPlayer); // cycle through A, B, C
    }
    return EXIT_SUCCESS;
}

//  print statistics
//  free memory