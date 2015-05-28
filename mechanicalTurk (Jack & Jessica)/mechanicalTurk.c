//
//  mechanicalTurk.c
//  
//
//  Created by Jessica Chen on 26/05/2015.
//  Have to compile using CSE comps or 32bit machine using filezilla
//  Compile with given Game.o and runGame.c

#include <stdio.h>
#include <stdlib.h>

#include "Game.h"
#include "mechanicalTurk.h"

action decideAction (Game g) {
    
    action nextAction;
    
    //retrain BPS & BQN to MJ MMONEY MTV for SPINOFFs
    int numOfBPS = getStudents (g, playerID, STUDENT_BPS);
    int numOfBQN = getStudents (g, playerID, STUDENT_BQN);
    
    int retrainBPStoMJ = getExchangeRate (g, playerID, STUDENT_BPS, STUDENT_MJ);
    int retrainBQNtoMJ = getExchangeRate (g, playerID, STUDENT_BQN, STUDENT_MJ);
    
    nextAction.actionCode = START_SPINOFF;
    if (isLegalAction(g, nextAction) == TRUE) {
        nextAction.actionCode = START_SPINOFF;
    } else if (//retrain students so enough students for START_SPINOFF) {
        
    } else {
        nextAction.actionCode = PASS;
    }
    
    return nextAction;
}

static action retrainStudent (int from, int to) {
    
    nextAction.actionCode = RETRAIN_STUDENT;
    
    nextAction.disciplineFrom = from;
    
    nextAction.disciplineTo = to;
    
    return nextAction;
}