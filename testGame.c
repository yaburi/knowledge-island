// 
// 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game-1.07.h"

#define TESTING_DICE_VALUE 4
#define TERRA_NULLIS -1

int main (int argc, char *argv[]) {

    /***************NATHAN'S TESTS******************/

    // what dice value produces students in the specified region?
    // 2..12
    //int getDiceValue (Game g, intregionID);
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

    // which university currently has the prestige award for the most ARCs?
    // this is NO_ONE until the first arc is purchased after the game 
    // has started.  
    //int getMostARCs (Game g);
    
    assert (getMostARCs (g) == NO_ONE);
    
    assert (getMostARCs (g) == UNI_A);

    assert (getMostARCs (g) == UNI_B);
    
    assert (getMostARCs (g) == UNI_C);

    // which university currently has the prestige award for the most pubs?
    // this is NO_ONE until the first publication is made.
    //int getMostPublications (Game g);
    assert (getMostPublications (g) == NO_ONE);

    assert (getMostPublications (g) == UNI_A);

    assert (getMostPublications (g) == UNI_B);
    
    assert (getMostPublications (g) == UNI_C);

    // return the current turn number of the game -1,0,1, ..
    //int getTurnNumber (Game g);
    assert (getTurnNumber (g) == TERRA_NULLIS);

    assert (getTurnNumber (g) == 0);

    assert (getTurnNumber (g) == 1);

    // return the player id of the player whose turn it is 
    // the result of this function is NO_ONE during Terra Nullis
    //int getWhoseTurn (Game g);
    assert (getWhoseTurn (g) == NO_ONE);

    assert (getWhoseTurn (g) == UNI_A);

    assert (getWhoseTurn (g) == UNI_B);

    assert (getWhoseTurn (g) == UNI_C);

    /***************NATHAN'S TESTS******************/

    printf ("All tests passed, you are Awesome!\n");

}