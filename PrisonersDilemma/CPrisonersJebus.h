#include "CPrisonersBase.h"

// Always COPERATES
class CPrisonersJebus : public CPrisonersBase 
{
	public: 
		void Reset() { /* Do nothing special */} ; 
		bool MakeChoice() {
			// Never tells the cops. 
			return PLAYER_COPERATES; 
		}
		std::string GetName() {return "Jebus" ; }
};
