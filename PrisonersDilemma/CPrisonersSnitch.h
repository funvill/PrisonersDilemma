#include "CPrisonersBase.h"

// Always DEFECTS
class CPrisonersSnitch : public CPrisonersBase 
{
	public: 
		void Reset() { /* Do nothing special */} ; 
		bool MakeChoice() {
			// Tell the cops. 
			return PLAYER_DEFECTS; 
		}
		std::string GetName() {return "Snitch" ; }
};
