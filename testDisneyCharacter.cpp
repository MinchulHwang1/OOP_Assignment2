#include "DisneyCharacter.h"

/* -- this is a FILEHEADER COMMENT --
	NAME	:	testDisneyCharacter
	PURPOSE :	This program takes the contents entered into the object and initializes it with Constructor.
				The constructor has confirmed that it can be overloaded, and outputs accordingly.
				If the input data member is out of the specified range, an appropriate value is output,
				and the memory allocated by the destructor is deleted when the file loading is finished.
*/
int main(void) {
	

	DisneyCharacter myCharacter((char*)"Mickey", (char*)"1929-01-10", 100, 'M');

	DisneyCharacter myCharacter2((char*)"Minnie", (char*)"1930-01-01");
	

	myCharacter2.PlaceCharacter('E');				//Test - Harness Particulars
	myCharacter2.SameMovies(myCharacter);		//Test - Harness Particulars

	myCharacter.ShowInfo();
	
	myCharacter2.ShowInfo();

	return 0;
}
