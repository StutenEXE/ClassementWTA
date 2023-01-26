#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int trouver_index_tournoi(const TournoiWTA* tournoiWTA, const int* nbTournoisEnregistres, const char* nomTournoi, 
	                      const unsigned int* dateTournoi, int* indexTournoi);
