#include "CPrisonersDilemma.h"


bool CPrisonersDilemma::AddPlayer( CPrisonersBase * player ) {
	if( player == NULL ) {
		return false; 
	}
	this->m_players.push_back( player ); 
	this->m_playersScores[ player->GetName() ] = 0 ; 
	return true ; 
}

void CPrisonersDilemma::RunTests( ) {

	size_t playerCount = this->m_players.size() ; 
	printf( "PrisonersDilemma between %d players over %d rounds.\n", playerCount, MAX_TURN_COUNT ); 
	printf( "Lower values are better\n\n");


	printf( "Per round\n"); 
	// Loop though all the different players. 
	for( std::vector<CPrisonersBase *>::iterator playerOneOffset = this->m_players.begin(); playerOneOffset != this->m_players.end(); playerOneOffset++ ) {
		// We don't need to run the same test twice. 
		for( std::vector<CPrisonersBase *>::iterator playerTwoOffset = (playerOneOffset+1); playerTwoOffset != this->m_players.end(); playerTwoOffset++ ) {
			this->RunTest( (*playerOneOffset), (*playerTwoOffset), MAX_TURN_COUNT );
		}
	}

	// Print out overall scores 
	printf( "\nOver all scores\n" ); 
	for( std::map< std::string, unsigned int>::iterator scores = this->m_playersScores.begin(); scores != this->m_playersScores.end(); scores++ ) {
		printf( "%13s = %4d\n", (*scores).first.c_str(), (*scores).second ) ; 
	}
}


/** 
 * *-----------------------------------------------------------------------------------*
 * |	                        | Prisoner B stays silent     | Prisoner B betrays     |
 * |                            | (cooperates)                | (defects)              |
 * *-----------------------------------------------------------------------------------*
 * | Prisoner A stays silent 	| Each serves 1 month         | Prisoner A: 6 months   |
 * | (cooperates)               |                             | Prisoner B: goes free  |
 * *-----------------------------------------------------------------------------------*
 * | Prisoner A betrays         | Prisoner A: goes free       | Each serves 3 months   |
 * | (defects)                  | Prisoner B: 6 months	      |                        |
 * *-----------------------------------------------------------------------------------*
 *
 * 
 */

int CPrisonersDilemma::ScoreTest( bool PrisonerA, bool PrisonerB ) {
	if( PrisonerA == PLAYER_DEFECTS && PrisonerB == PLAYER_DEFECTS ) {
		// Prisoner A betrays (defects)
		// Prisoner B betrays (defects)
		// Each serves 3 months
		return 3; 
	}
	else if( PrisonerA == PLAYER_COPERATES && PrisonerB == PLAYER_COPERATES) {
		// Prisoner A stays silent (cooperates)
		// Prisoner B stays silent (cooperates)
		// Each serves 1 month 
		return 1; 
	} else if ( PrisonerA == PLAYER_DEFECTS && PrisonerB == PLAYER_COPERATES ) {
		// Prisoner A betrays (defects)
		// Prisoner B stays silent (cooperates)
		// Prisoner A: goes free
		return 0 ; 
	} else if ( PrisonerA == PLAYER_COPERATES&& PrisonerB == PLAYER_DEFECTS  ) {
		// Prisoner A stays silent (cooperates)
		// Prisoner B betrays (defects)
		// Prisoner A: 6 months
		return 6 ; 
	}

	// Unreachable code. 
	return 0; 
}

void CPrisonersDilemma::RunTest( CPrisonersBase * playerOne, CPrisonersBase * playerTwo, unsigned int turnCount ) {

	if( playerOne == NULL || playerTwo == NULL ) {
		printf( "Error: Player One or Two never got init. \n");
		return ; 
	}

	// Reset any internal counters. 
	playerOne->Reset(); 
	playerTwo->Reset(); 

	// A counter for each player to test how much time they will serve 
	unsigned int playerOneScore	= 0 ; 
	unsigned int playerTwoScore	= 0 ; 

	// Do the tests. 
	for( int turn = 0 ; turn < turnCount ; turn++ ) {
		
		// Get the choices from each player 
		bool playerOnesChoice = playerOne->MakeChoice( ) ; 
		bool playerTwosChoice = playerTwo->MakeChoice( ) ; 

		// Update the history variables. 
		playerOne->Result( playerTwosChoice ) ; 
		playerTwo->Result( playerOnesChoice ); 

		// Score the results. 		
		playerOneScore += ScoreTest( playerOnesChoice, playerTwosChoice ); 
		playerTwoScore += ScoreTest( playerTwosChoice, playerOnesChoice ); 
	}

	// Print the results 
	printf( "%13s (%4d) Vs %13s (%4d) - Total: %4d - ", playerOne->GetName().c_str(), playerOneScore, playerTwo->GetName().c_str(), playerTwoScore, playerOneScore + playerTwoScore ); 
	if( playerOneScore == playerTwoScore ) {
		printf( "Tied ! "); 
	} else if( playerOneScore < playerTwoScore ) {
		printf( "%s Wins",  playerOne->GetName().c_str() ); 
	} else {
		printf( "%s Wins",  playerTwo->GetName().c_str() ); 
	}		
	printf( "\n"); 

	this->m_playersScores[ playerOne->GetName() ] += playerOneScore ; 
	this->m_playersScores[ playerTwo->GetName() ] += playerTwoScore ; 
}