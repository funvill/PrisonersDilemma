#include "CPrisonersBase.h"

/**
 * Starts with Coperate, then copies what ever the opponent does. 
 */  
class CPrisonersCopyCat : public CPrisonersBase 
{
	private:
		bool m_lastChoice ; 
	public: 
		void Reset() { 
			// At the start of the sequence always select 
			this->m_lastChoice = PLAYER_COPERATES ; 
		} ; 
		void Result( bool result ) {
			this->m_lastChoice = result ; 
		}  
		bool MakeChoice( ) {
			// Always follows the last result. 
			return this->m_lastChoice ; 
		}
		std::string GetName() {return "CopyCat" ; }
};
