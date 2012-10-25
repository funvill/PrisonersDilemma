
/**
 * http://www.cplusplus.com/forum/lounge/47914/
 */

#ifndef __CPrisonersBase_H__
#define __CPrisonersBase_H__

#include <string> 

#define PLAYER_COPERATES	true 
#define PLAYER_DEFECTS		false 

#ifndef NULL 
#define NULL 0 
#endif // NULL 

class CPrisonersBase
{
	public:
		/**
		 * Called at the start of a new session with a different opponent. 
		 */
		virtual void Reset() = 0; 
		
		/** 
		 * Called each loop to get a choice from this bot. 
		 * 
		 * Return 
		 * 		True - Testify againts opponent 
		 * 		False - Keep silent. 
		 */ 
		virtual bool MakeChoice( ) = 0; 
		
		// This is called imidialty after MakeChoice() with the result from the opponents choice. 
		virtual void Result( bool result ) {} ; 


		virtual std::string GetName() = 0 ;
};

#endif // __CPrisonersBase_H__