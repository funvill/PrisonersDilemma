#include "CPrisonersBase.h"

// coperate at first, but if someone DEFECTS will defect until opponent COPERATES twice times in a row. 
class CPrisonersForgives : public CPrisonersBase 
{
	private:
		bool m_choice ; 
		unsigned char m_hateMeter ; 

	public: 
		void Reset() { 
			// At the start of the sequence always select 
			this->m_choice		= PLAYER_COPERATES ; 
			this->m_hateMeter	= 0 ; 
		} ; 
		void Result( bool result ) {

			if( result == PLAYER_DEFECTS ) {
				// The player DEFECTS on us, increase the hate meter.
				this->m_hateMeter++; 

				// Max of 3 hate 
				if( this->m_hateMeter > 3 ) {
					this->m_hateMeter = 0 ; 
				}
			} else { 
				// The player COPERATES with us. decrease the hate meter. 
				if( this->m_hateMeter > 0 ) {
					this->m_hateMeter--; 
				}
			}

			// If the player hates the other player he will DEFECTS otherwise he will COPERATES
			if( this->m_hateMeter > 0 ) {
				this->m_choice = PLAYER_DEFECTS ;
			} else {
				this->m_choice = PLAYER_COPERATES ;
			}
		}  

		bool MakeChoice( ) {
			// Always follows the last result. 
			return this->m_choice ; 
		}
		std::string GetName() {return "Forgives" ; }
};
