/*
 *  Mr Pass.  Brain the size of a planet!
 *
 *  Proudly Created by Richard Buckland
 *  Share Freely Creative Commons SA-BY-NC 3.0. 
 *  More proudly edited by Holy Ahel & Nathan Zhen
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Game.h"
#include "mechanicalTurk.h"

 
action decideAction (Game g) {
 
   action nextAction;
    
    if (getStudents(Game g, getWhoseTurn(Game g), STUDENT_MJ) >= 1 && getStudents(game g, getWhoseTurn(Game g), STUDENT_MTV) >= 1 && getStudents(Game g, getWhoseTurn(Game g), STUDENT_MMONEY) >= 1) {
        nextAction = 4; //start spin off
    } else {
        nextAction.actionCode = PASS;
    }
    
   
   return nextAction;
}