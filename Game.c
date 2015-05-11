// Game.c
// ADT for Knowledge Island
// Nathan Zhen, Jack Abroon, Holly Ahel and Jessica Chen

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"

typedef struct _game { 
    
    // Map
    vertex  // what is on this vertex
    edge    // what is on this edge
    region  // what this region produces

    // Players
    player player[NUM_UNIS];    // players in the game

    // Trackers
    int currentTurn;
    int whoseTurn;
    int mostARCs;
    int mostPublications;

} game;

typedef struct _player {
   
   // What each player has
   int KPIs;
   int ARCs;
   int regularCampuses;
   int GO8Campuses;
   int patents;
   int publications;

   // Disciplines each player has
   int THDs;
   int BPSs;
   int BQNs;
   int MJs;
   int MTVs;
   int MMONEYs;
} player;

typedef struct _vertex {

} vertex;

typedef struct _edge {

} edge;

typedef struct _region {

} region;