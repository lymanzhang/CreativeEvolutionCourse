//////////////////////////////////////////////////
/*         Evolution as a Creative Tool         */
/*           Taught by Patrick Hebron           */
/* Interactive Telecommunications Program (ITP) */
/*             New York University              */
/*                  Fall 2013                   */
//////////////////////////////////////////////////

#pragma once

#include "Constants.h"

/**
 * THE CONTENTS OF THIS FILE SHOULD BE EDITED TO PRODUCE A WINNING SUDOKU SOLVER...
 */

#pragma mark -
#pragma mark - TEAM_PARAMS

static const std::string	kAuthorTeam		= "YOUR_TEAM_NAME_GOES_HERE";
static const float			kMutationRate	= 0.01f;

#pragma mark -
#pragma mark - TEAM_FUNCTIONS

static float fitnessFunc(const int* iBoard, const size_t& iTileCount)
{
	// EXERCISE: Please implement a function that evaluates the fitness of a given sudoku board...
	
	return (float)rand() / (float)RAND_MAX;
}

static void crossoverFunc(const int* iBoardA, const int* iBoardB, int* oBoard, const size_t& iTileCount)
{
	// EXERCISE: Please feel free to replace the contents of this function to improve upon your algorithm's performance...
	
	int tMid = randomInt( 0, (int)iTileCount );
	for(size_t i = 0; i < iTileCount; i++) {
		if(i < tMid) { oBoard[i] = iBoardA[i]; }
		else         { oBoard[i] = iBoardB[i]; }
	}
}

static void mutateFunc(int* ioBoard, const size_t& iTileCount, const float& iMutationRate)
{
	// EXERCISE: Please feel free to replace the contents of this function to improve upon your algorithm's performance...
	
	for(int i = 0; i < iTileCount; i++) {
		if( ( (float)rand() / (float)RAND_MAX ) < iMutationRate ) {
			ioBoard[i] = randomInt( getTileValueMin(), getTileValueMax() + 1 );
		}
	}
}

static void randomBoard(int* ioBoard, const size_t& iTileCount)
{
	// EXERCISE: The contents of this function can be edited for testing, but will be reverted for league play...
	
	for(int i = 0; i < iTileCount; i++) {
		ioBoard[i] = randomInt( getTileValueMin(), getTileValueMax() + 1 );
	}
}

static void printBoard(int* iBoard, const size_t& iTileCount)
{
	// EXERCISE: The contents of this function can be edited for testing, but will be reverted for league play...
	
	int tAxisLen = sqrt( iTileCount );
	printf( "%ix%i BOARD:\n", tAxisLen, tAxisLen );
	for(int i = 0; i < tAxisLen; i++) {
		for(int j = 0; j < tAxisLen; j++) {
			printf( "%i ", iBoard[ i * tAxisLen + j ] );
		}
		printf( "\n" );
	}
	printf( "\n" );
}