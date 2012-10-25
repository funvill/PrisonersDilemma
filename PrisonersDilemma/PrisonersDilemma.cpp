//

#include "stdafx.h"
#include "CPrisonersDilemma.h"
#include "CPrisonersJebus.h"
#include "CPrisonersSnitch.h"
#include "CPrisonersRandom.h"
#include "CPrisonersCopyCat.h"
#include "CPrisonersFoolMeOnce.h"
#include "CPrisonersForgives.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// Create the structure to run the tests 
	CPrisonersDilemma prisonersDilemma; 

	// Add the players 
	prisonersDilemma.AddPlayer( new CPrisonersJebus() ); 
	prisonersDilemma.AddPlayer( new CPrisonersSnitch() ); 
	prisonersDilemma.AddPlayer( new CPrisonersRandom() ); 
	prisonersDilemma.AddPlayer( new CPrisonersCopyCat() ); 
	prisonersDilemma.AddPlayer( new CPrisonersFoolMeOnce() ); 
	prisonersDilemma.AddPlayer( new CPrisonersForgives() ); 

	// Run the tests. 
	prisonersDilemma.RunTests(  ); 

	return 0;
}

