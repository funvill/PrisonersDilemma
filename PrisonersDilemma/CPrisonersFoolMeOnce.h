#include "CPrisonersBase.h"

// At first will coperate, if the opponent ever does defects, will defect every time after that. 
class CPrisonersFoolMeOnce : public CPrisonersBase 
{
	private:
		bool m_choice ; 
	public: 
		void Reset() { 
			// At the start of the sequence always select 
			this->m_choice = PLAYER_COPERATES ; 
		} ; 
		void Result( bool result ) {
			if( result == PLAYER_DEFECTS ) {
				this->m_choice = PLAYER_DEFECTS ; 
			}
		}  
		bool MakeChoice( ) {
			// Always follows the last result. 
			return this->m_choice ; 
		}
		std::string GetName() {return "FoolMeOnce" ; }
};
