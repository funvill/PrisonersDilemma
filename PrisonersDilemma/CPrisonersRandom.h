#include "CPrisonersBase.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Randomly selects DEFECTS or COPERATES
class CPrisonersRandom : public CPrisonersBase 
{
	public: 
		void Reset() { 
			/* initialize random seed: */
			srand ( time(NULL) );		
		} 
		bool MakeChoice() {
			// Never tells the cops. 
			return (rand() % 2 == 1) ; 
		}
		std::string GetName() {return "Random" ; }
};
