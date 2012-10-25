
#include "CPrisonersBase.h"
# include <stdio.h>

#include <vector>
#include <string>
#include <map>

#define MAX_TURN_COUNT 		100

class CHistory
{
	public :

		void Recored( std::string playerOneName, bool playerOneChoice, std::string playerTwoName, bool playerTwoChoice ); 
};


class CPrisonersDilemma 
{
	private:

		// The testing pool of all the players 
		std::vector<CPrisonersBase *> m_players; 
		
		// Players overall scores 
		std::map< std::string, unsigned int> m_playersScores; 
		
		// A helper funtion to score the results of the tests. 
		int ScoreTest( bool self, bool opponent ) ;
		
		// Run a test between two players 
		void RunTest( CPrisonersBase * playerOne, CPrisonersBase * playerTwo, unsigned int turnCount  ); 

	public:

		// Adds a player to the testing pool. 
		bool AddPlayer( CPrisonersBase * player ); 

		// Runs the test between all the players in the testing pool 
		void RunTests( ); 
};