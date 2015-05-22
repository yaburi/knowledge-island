/*
 *  MECHA TURK
 *  By Holly Ahel and Nathan Zhen
 */



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
 
#include "Game.h"
#include "mechanicalTurk.h"

// DELETE THESE DEFINES LATER, THEY JUST MAKE IT EASIER TO TAB COMPLETE
// FOR NOW.
#define NUM_UNIS 3

// player ID of each university
#define NO_ONE 0
#define UNI_A 1
#define UNI_B 2
#define UNI_C 3

// contents of an ARC
#define VACANT_ARC 0
#define ARC_A 1
#define ARC_B 2
#define ARC_C 3

// contents of a VERTEX
#define VACANT_VERTEX 0  
#define CAMPUS_A 1
#define CAMPUS_B 2
#define CAMPUS_C 3
#define GO8_A 4
#define GO8_B 5
#define GO8_C 6

// action codes
#define PASS 0
#define BUILD_CAMPUS 1
#define BUILD_GO8 2
#define OBTAIN_ARC 3
#define START_SPINOFF 4
#define OBTAIN_PUBLICATION 5
#define OBTAIN_IP_PATENT 6
#define RETRAIN_STUDENTS 7

// disciplines
#define STUDENT_THD 0
#define STUDENT_BPS 1
#define STUDENT_BQN 2
#define STUDENT_MJ  3
#define STUDENT_MTV 4
#define STUDENT_MMONEY 5

#define NUM_REGIONS 19
#define PATH_LIMIT 150

#define TRUE 1
#define FALSE 0

static action convert (int from, int to);

action decideAction (Game g) {
 

    //
    //  Mr Pass
    //

    // variable declaration
    int currentTurn = getWhoseTurn(g);
    // we don't need BPS and BQN for spinoffs
    int retrainBPS = getStudents (g, currentTurn, STUDENT_BPS);
    int retrainBQN = getStudents (g, currentTurn, STUDENT_BQN);
    int needMJ = getStudents (g, currentTurn, STUDENT_MJ);
    int needMTV = getStudents (g, currentTurn, STUDENT_MTV);
    int needMMONEY = getStudents (g, currentTurn, STUDENT_MMONEY);
    // checks the exchange rate for each type of student
    int excBPS = getExchangeRate (g, currentTurn, STUDENT_BPS, STUDENT_BPS);
    int excBQN = getExchangeRate (g, currentTurn, STUDENT_BQN, STUDENT_BPS);
    int excMJ = getExchangeRate (g, currentTurn, STUDENT_MJ, STUDENT_BPS);
    int excMTV = getExchangeRate (g, currentTurn, STUDENT_MTV, STUDENT_BPS);
    int excMMONEY = getExchangeRate (g, currentTurn, STUDENT_MMONEY, STUDENT_BPS);

    // the default move is to PASS
    action nextAction;
    nextAction.actionCode = PASS;

    // will also try to START_SPINOFF given that...
    action a;
    a.actionCode = START_SPINOFF;


    // ...we have enough resources to do it right now
    if (isLegalAction (g, a)) {
        nextAction = a;
    } else {    // tries to convert other students to spinoff students
        // if we have less than 1 MJ, will convert to this type first
        if (needMJ < 1){
            // checks to see if we have enough of each type, given their
            // current exchange rate
            if (retrainBPS >= excBPS) {
                a = convert (STUDENT_BPS, STUDENT_MJ);
            } else if (retrainBQN >= excBQN) {
                a = convert (STUDENT_BQN, STUDENT_MJ);
            // also checks for types that are used in making spinoffs,
            // given that we will have one remaining of these types to
            // also use to make the spinoffs
            } else if (needMMONEY >= excMMONEY + 1) {
                a = convert (STUDENT_MMONEY, STUDENT_MJ);
            } else if (needMTV >= excMTV + 1) {
                a = convert (STUDENT_MTV, STUDENT_MJ);
            }
        // same deal as before
        } else if (needMTV < 1) {
            if (retrainBPS >= excBPS) {
                a = convert (STUDENT_BPS, STUDENT_MTV);
            } else if (retrainBQN >= excBQN) {
                a = convert (STUDENT_BQN, STUDENT_MTV);
            } else if (needMMONEY >= excMMONEY + 1) {
                a = convert (STUDENT_MMONEY, STUDENT_MTV);
            } else if (needMJ >= excMJ + 1) {
                a = convert (STUDENT_MJ, STUDENT_MTV);
            }
        // same       
        } else if (needMMONEY < 1) {
            if (retrainBPS >= excBPS) {
                a = convert (STUDENT_BPS, STUDENT_MMONEY);
            } else if (retrainBQN >= excBQN) {
                a = convert (STUDENT_BQN, STUDENT_MMONEY);
            } else if (needMTV >= excMTV + 1) {
                a = convert (STUDENT_MTV, STUDENT_MMONEY);
            } else if (needMJ >= excMJ + 1) {
                a = convert (STUDENT_MJ, STUDENT_MMONEY);
            }
        }
        // tries to make a spinoff after converting all the students
        // that we can
        if (isLegalAction (g, a)) {
            nextAction = a;
        }
    }

    /*
    //
    // Mr Build ARCs
    //

    // Hardcoded stupid Mr ARC (only works for UNI A)
    // 1. start at L
    if(getARC (g, "L") == VACANT_ARC) {
        // Checks if enough resources
        if(getStudents(g, getWhoseTurn(g), STUDENT_BPS) >= 1 &&
        getStudents(g, getWhoseTurn(g), STUDENT_BQN) >= 1) {
            // Creates ARC at this location
            nextAction.actionCode = OBTAIN_ARC;
            strcpy(nextAction.destination, "L");
        } else {
            // Passes
            nextAction.actionCode = PASS;
        }
    // If taken, pass and ignore this point
    } else if (getARC (g, "L") != getWhoseTurn(g)) {
        nextAction.actionCode = PASS;
    }
    
    // 2. go to LR
    if(getARC (g, "LR") == VACANT_ARC) {
        // Checks if enough resources
        if(getStudents(g, getWhoseTurn(g), STUDENT_BPS) >= 1 &&
        getStudents(g, getWhoseTurn(g), STUDENT_BQN) >= 1) {
            // Creates ARC at this location
            nextAction.destination = "LR";
            nextAction.actionCode = OBTAIN_ARC;
        } else {
            // Passes
            nextAction.actionCode = PASS;
        }
    // If taken, pass and ignore this point
    } else if (getARC (g, "LR") != getWhoseTurn(g)) {
        nextAction.actionCode = PASS;
    }*/
    
    //
    // Mr Pass
    //

   
    return nextAction;
}

static action convert (int from, int to) {
   
    action newAction;

    // tells the action struct to retrain students
    newAction.actionCode = RETRAIN_STUDENTS;
    // from type...
    newAction.disciplineFrom = from;
    // to type...
    newAction.disciplineTo = to;
    return newAction;
}

/*static action mrPass (Game g) {
    printf("let's declare some variables!\n");
    action nextAction;
    nextAction.actionCode = PASS;

    printf("let's declare some more variables!\n");
    action a;
    a.actionCode = START_SPINOFF;

    action result;
    result.actionCode = PASS;

    action a;
    a.actionCode = START_SPINOFF;

    printf("let's test islegal!\n");
    if (isLegalAction (g, a)) {
        result = a;
    } else {

    printf("let's declare more variables!\n");
    int currentTurn = getWhoseTurn(g);

    int retrainBPS = getStudents (g, currentTurn, STUDENT_BPS);
    int retrainBQN = getStudents (g, currentTurn, STUDENT_BQN);
    int needMJ = getStudents (g, currentTurn, STUDENT_MJ);
    int needMTV = getStudents (g, currentTurn, STUDENT_MTV);
    int needMMONEY = getStudents (g, currentTurn, STUDENT_MMONEY);

    int excBPS = getExchangeRate (g, currentTurn, STUDENT_BPS, STUDENT_BPS);
    int excBQN = getExchangeRate (g, currentTurn, STUDENT_BQN, STUDENT_BPS);
    int excMJ = getExchangeRate (g, currentTurn, STUDENT_MJ, STUDENT_BPS);
    int excMTV = getExchangeRate (g, currentTurn, STUDENT_MTV, STUDENT_BPS);
    int excMMONEY = getExchangeRate (g, currentTurn, STUDENT_MMONEY, STUDENT_BPS);

    
        printf("let's test our first if!\n");
        if (needMJ < 1){
            if (retrainBPS >= excBPS) {
                a = convert (STUDENT_BPS, STUDENT_MJ);
            } else if (retrainBQN >= excBQN) {
                a = convert (STUDENT_BQN, STUDENT_MJ);
            } else if (needMMONEY >= excMMONEY + 1) {
                a = convert (STUDENT_MMONEY, STUDENT_MJ);
            } else if (needMTV >= excMTV + 1) {
                a = convert (STUDENT_MTV, STUDENT_MJ);
            }
        printf("let's test our second if!\n");
        } else if (needMTV < 1) {
            if (retrainBPS >= excBPS) {
                a = convert (STUDENT_BPS, STUDENT_MTV);
            } else if (retrainBQN >= excBQN) {
                a = convert (STUDENT_BQN, STUDENT_MTV);
            } else if (needMMONEY >= excMMONEY + 1) {
                a = convert (STUDENT_MMONEY, STUDENT_MTV);
            } else if (needMJ >= excMJ + 1) {
                a = convert (STUDENT_MJ, STUDENT_MTV);
            }
        printf("let's test our third if!\n");       
        } else if (needMMONEY < 1) {
            if (retrainBPS >= excBPS) {
                a = convert (STUDENT_BPS, STUDENT_MMONEY);
            } else if (retrainBQN >= excBQN) {
                a = convert (STUDENT_BQN, STUDENT_MMONEY);
            } else if (needMTV >= excMTV + 1) {
                a = convert (STUDENT_MTV, STUDENT_MMONEY);
            } else if (needMJ >= excMJ + 1) {
                a = convert (STUDENT_MJ, STUDENT_MMONEY);
            }
        }
        printf("let's test another isLegalAction!\n");
        if (isLegalAction (g, a)) {
            result = a;
        }
    }
    printf("let's return everything!\n");
    return result;
}*/



//..........ignore below............//


/*
//
//  Mr Build ARCs
//
int mrARCs (Game g) {

    action a;
    
    // Different instructions depending on which uni we are
    if (player == UNI_A) {
        // Build ARCs

    } else if (player == UNI_B) {

    } else if (player == UNI_C) {

    }
    

    // Hardcoded stupid Mr ARC (only works for UNI A)
    // 1. start at L
    if(getARC (g, "L") == VACANT_ARC) {
        // Checks if enough resources
        if(getStudents(g, getWhoseTurn(g), STUDENT_BPS) >= 1 &&
        getStudents(g, getWhoseTurn(g), STUDENT_BQN) >= 1) {
            // Creates ARC at this location
            a.destination = "L";
            a.actionCode = OBTAIN_ARC;
        } else {
            // Passes
            mrPass (g);
        }
    // If taken, pass and ignore this point
    } else if (getARC (g, "L") != getWhoseTurn(g)) {
        mrPass(g);
    }

    // 2. go to LR
    if(getARC (g, "LR") == VACANT_ARC) {
        // Checks if enough resources
        if(getStudents(g, getWhoseTurn(g), STUDENT_BPS) >= 1 &&
        getStudents(g, getWhoseTurn(g), STUDENT_BQN) >= 1) {
            // Creates ARC at this location
            a.destination = "LR";
            a.actionCode = OBTAIN_ARC;
        } else {
            // Passes
            mrPass (g);
        }
    // If taken, pass and ignore this point
    } else if (getARC (g, "LR") != getWhoseTurn(g)) {
        mrPass(g);
    }

    return a.actionCode;
}

//
//  Mr Pass
//
int mrPass (Game g) {

    
}
*/
