// testGame.c
// Tests for Game.c
// Nathan Zhen, Jack Abroon, Holly Ahel and Jessica Chen

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Game.h"

#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, 
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, 
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, 
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, 
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

int disciplines[] = DEFAULT_DISCIPLINES;
int dice[] = DEFAULT_DICE;
Game g = newGame (disciplines, dice);

// Setters
void testNewGame (void);
void testMakeAction (void);

// Getters
void testGetDiscipline (void);
void testGetDiceValue (void);
void testGetMostARCs (void);
void testGetMostPublications (void);
void testGetTurnNumber (void);
void testGetWhoseTurn (void);
void testGetCampus (void);
void testGetARC (void);

// isLegalAction
void testIsLegalAction (void);

// Gets data about a specified player
void testGetKPIpoints (void);
void testGetARCs (void);
void testGetGO8s (void);
void testGetCampuses (void);
void testGetIPs (void);
void testGetPublications (void);
void testGetStudents (void);
void testGetExchangeRate (void);

int main (int argc, char *argv[]) {

    // Setters
    testNewGame();
    testMakeAction();

    // Getters
    testGetDiscipline();
    testGetDiceValue();
    testGetMostARCs();
    testGetMostPublications();
    testGetTurnNumber();
    testGetWhoseTurn();
    testGetCampus();
    testGetARC();

    // isLegal
    testIsLegalAction();

    // Gets data about a specified player
    testGetKPIpoints();
    testGetARCs();
    testGetGO8s();
    testGetCampuses();
    testGetIPs();
    testGetPublications();
    testGetStudents();
    testGetExchangeRate();


    printf ("All tests passed, you are Awesome!\n");

}



// Setters
void testNewGame (void) {
    // make a new game, given the disciplines produced by each
    // region, and the value on the dice discs in each region.
    // note: each array must be NUM_REGIONS long
    // eg if you are using my sample game struct above this function
    // would need to set the field currentTurn to -1.  (because the turn
    // number is -1 at the start of the game)
    // the ordering of the regions is column by column left to right,
    // going from the top of each column to the bottom before moving 
    // to the next column to the right.
    //
    // so to create the default game as shown on the badly drawn map:
    //
    /*
    #define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, 
                    STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, 
                    STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, 
                    STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, 
                    STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS }
    #define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}
    */
    //
    //   int disciplines[] = DEFAULT_DISCIPLINES;
    //   int dice[] = DEFAULT_DICE;
    //   Game g = newGame (disciplines, dice);
    Game newGame (int discipline[], int dice[]);

    //everyone has the same amount of disciplines

    //everyone has no ARCs, campuses or GO8

    //different unis starting in different places


}

void testMakeAction (void) {
    // make the specified action for the current player and update the 
    // game state accordingly.  
    // The function may assume that the action requested is legal.
    // START_SPINOFF is not a legal action here
    void makeAction (Game g, action a);

}


// Getters
void testGetDiscipline (void) {
    // what type of students are produced by the specified region?
    // regionID is the index of the region in the newGame arrays (above) 
    // see discipline codes above
    int getDiscipline (Game g, int regionID);

}

void testGetDiceValue (void) {
    // what dice value produces students in the specified region?
    // 2..12
    printf ("Testing getDiceValue.\n");

    assert (getDiceValue (g, 1) == 9);
    assert (getDiceValue (g, 2) == 10);
    assert (getDiceValue (g, 3) == 8);

    assert (getDiceValue (g, 4) == 12);
    assert (getDiceValue (g, 5) == 6);
    assert (getDiceValue (g, 6) == 5);
    assert (getDiceValue (g, 7) == 3);

    assert (getDiceValue (g, 8) == 11);
    assert (getDiceValue (g, 9) == 3);
    assert (getDiceValue (g, 10) == 11);
    assert (getDiceValue (g, 11) == 4);
    assert (getDiceValue (g, 12) == 6);

    assert (getDiceValue (g, 13) == 4);
    assert (getDiceValue (g, 14) == 7);
    assert (getDiceValue (g, 15) == 9);
    assert (getDiceValue (g, 16) == 2);

    assert (getDiceValue (g, 17) == 8);
    assert (getDiceValue (g, 18) == 10);
    assert (getDiceValue (g, 19) == 5);

    disposeGame (g);
    printf ("getDiceValue passed!\n");
}

void testGetMostARCs (void) {
    // which university currently has the prestige award for the most ARCs?
    // this is NO_ONE until the first arc is purchased after the game 
    // has started.  
    int getMostARCs (Game g);
    
    assert (getMostARCs (g) == NO_ONE);
    
    assert (getMostARCs (g) == UNI_A);

    assert (getMostARCs (g) == UNI_B);
    
    assert (getMostARCs (g) == UNI_C);
}

void testGetMostPublications (void) {
    // which university currently has the prestige award for the most pubs?
    // this is NO_ONE until the first publication is made.
    int getMostPublications (Game g);
    assert (getMostPublications (g) == NO_ONE);

    assert (getMostPublications (g) == UNI_A);

    assert (getMostPublications (g) == UNI_B);
    
    assert (getMostPublications (g) == UNI_C);
}

void testGetTurnNumber (void) {
    // return the current turn number of the game -1,0,1, ..
    int getTurnNumber (Game g);
    assert (getTurnNumber (g) == TERRA_NULLIS);

    assert (getTurnNumber (g) == 0);

    assert (getTurnNumber (g) == 1);
}

void testGetWhoseTurn (void) {
    // return the player id of the player whose turn it is 
    // the result of this function is NO_ONE during Terra Nullis
    int getWhoseTurn (Game g);
    assert (getWhoseTurn (g) == NO_ONE);

    assert (getWhoseTurn (g) == UNI_A);

    assert (getWhoseTurn (g) == UNI_B);

    assert (getWhoseTurn (g) == UNI_C);
}

void testGetCampus (void) {
    // return the contents of the given vertex (ie campus code or 
    // VACANT_VERTEX)
    int getCampus(Game g, path pathToVertex);

}

void testGetARC (void) {
    // the contents of the given edge (ie ARC code or vacent ARC)
    int getARC(Game g, path pathToEdge);

}

// isLegalAction
void testIsLegalAction (void) {
    // returns TRUE if it is legal for the current
    // player to make the specified action, FALSE otherwise.
    //
    // "legal" means everything is legal: 
    //   * that the action code is a valid action code which is legal to 
    //     be made at this time
    //   * that any path is well formed and legal ie consisting only of 
    //     the legal direction characters and of a legal length, 
    //     and which does not leave the island into the sea at any stage.
    //   * that disciplines mentioned in any retraining actions are valid 
    //     discipline numbers, and that the university has sufficient
    //     students of the correct type to perform the retraining
    //
    // eg when placing a campus consider such things as: 
    //   * is the path a well formed legal path 
    //   * does it lead to a vacent vertex?
    //   * under the rules of the game are they allowed to place a 
    //     campus at that vertex?  (eg is it adjacent to one of their ARCs?)
    //   * does the player have the 4 specific students required to pay for 
    //     that campus?
    // It is not legal to make any action during Terra Nullis ie 
    // before the game has started.
    // It is not legal for a player to make the moves OBTAIN_PUBLICATION 
    // or OBTAIN_IP_PATENT (they can make the move START_SPINOFF)
    // you can assume that any pths passed in are NULL terminated strings.
    int isLegalAction (Game g, action a);
}

// Gets data about a specified player
void testGetKPIpoints (void) {
    // return the number of KPI points the specified player currently has
    int getKPIpoints (Game g, int player);

}

void testGetARCs (void) {
    // return the number of ARC grants the specified player currently has
    int getARCs (Game g, int player);

}

void testGetGO8s (void) {
    // return the number of GO8 campuses the specified player currently has
    int getGO8s (Game g, int player);

}

void testGetCampuses (void) {
    // return the number of normal Campuses the specified player currently has
    int getCampuses (Game g, int player);

}

void testGetIPs (void) {
    // return the number of IP Patents the specified player currently has
    int getIPs (Game g, int player);

}

void testGetPublications (void) {
    // return the number of Publications the specified player currently has
    int getPublications (Game g, int player);

}

void testGetStudents (void) {
    // return the number of students of the specified discipline type 
    // the specified player currently has
    int getStudents (Game g, int player, int discipline);

}

void testGetExchangeRate (void) {
    // return how many students of discipline type disciplineFrom
    // the specified player would need to retrain in order to get one 
    // student of discipline type disciplineTo.  This will depend 
    // on what retraining centers, if any, they have a campus at.
    int getExchangeRate (Game g, int player, 
                         int disciplineFrom, int disciplineTo);

}