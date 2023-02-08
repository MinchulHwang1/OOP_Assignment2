#include "DisneyCharacter.h"

/*  -- Method Header Comment
	Name	:   DisnetCharacter -- CONSTRUCTOR
	Purpose :   To instantiate a new DisneyCharacter object - given a set of attribute values
				It can be overloaded
	Inputs	:	name			String		name of the character
				creationDate	String		created date of the character
				numMovies		int			how many movies the character stars
				whichPark		int			M, S, A, E, C, N
	Outputs	:	NONE
	Returns	:	Nothing
*/
DisneyCharacter::DisneyCharacter(char* name, char* creationDate, int numMovies, char whichPark) {
	strcpy(nameCopy, " ");				// initialize nameCopy to " "(blank)
	strcpy(creationDateCopy, " ");		// initialize creationDateCopy to " "(blank)
	
	// Initialize name value
	strcpy(this->name, name);
	// Check condition of value of name
	// If name string is lager than 46, a letter from 46th changes into '.'
	int i = 0;
	if (strlen(this->name) > kLetter) {
		for (i = 0; i < kLetter; i++) {
			this->name[i] = this->name[i];
		}
		for (i; i < kNameString - 1; i++) {
			this->name[i] = '.';
		}
	}

	// Initialize creationDate Value
	strcpy(this->creationDate, creationDate);
	// Check format of value of creationDate
	// If creationDate Value is not on format, changes into " "(blank)
	char blank[kDateString] = { };
	if (strlen(this->creationDate) == 10) {
		if (this->creationDate[4] != '-' || this->creationDate[7] != '-') {
			strcpy(this->creationDate, blank);
		}
		else {
			for (i = 0; i < 4; i++) {
				if (isdigit(this->creationDate[i]) == 0) {
					strcpy(this->creationDate, blank);
				}
			}
			for (i = 5; i < 7; i++) {
				if (isdigit(this->creationDate[i]) == 0) {
					strcpy(this->creationDate, blank);
				}
			}
			for (i = 8; i < 10; i++) {
				if (isdigit(this->creationDate[i]) == 0) {
					strcpy(this->creationDate, blank);
				}
			}
			strcpy(this->creationDate, creationDate);
		}
	}
	else {
		strcpy(this->creationDate, blank);
	}

	// Initialize numMovies Value
	// Check value of numMovies
	// If numMovies is less than 0, it changes into 0
	if (numMovies >= 0) {
		this->numMovies = numMovies;
	}
	else {
		this->numMovies = 0;
	}

	// Initialize whichPark Value
	// Check value of whichPark
	// If whichPark is not in format(M, S, A, E, C, and N), it changes into N
	if (whichPark == 'M' || whichPark == 'S' || whichPark == 'A' || whichPark == 'E' || whichPark == 'C' || whichPark == 'N') {
		this->whichPark = whichPark;
	}
	else {
		this->whichPark = 'N';
	}
}

/*  -- Method Header Comment
	Name	:   DisnetCharacter -- CONSTRUCTOR
	Purpose :   To instantiate a new DisneyCharacter object - given a set of attribute values
				It can be overloaded
	Inputs	:	name			String		name of the character
				creationDate	String		created date of the character
	Outputs	:	NONE
	Returns	:	Nothing
*/
DisneyCharacter::DisneyCharacter(char* name, char* creationDate) {
	strcpy(nameCopy, " ");				// initialize nameCopy to " "(blank)
	strcpy(creationDateCopy, " ");		// initialize creationDateCopy to " "(blank)
	numMovies = 0;										// initialize numMovies to 0
	whichPark = 'N';									// initialize whichPark to N

	// Initialize name value
	strcpy(this->name, name);
	// Check condition of value of name
	// If name string is lager than 46, a letter from 46th changes into '.'
	int i = 0;
	if (strlen(this->name) > kLetter) {
		for (i = 0; i < kLetter; i++) {
			this->name[i] = this->name[i];
		}
		for (i; i < kNameString - 1; i++) {
			this->name[i] = '.';
		}
	}

	// Initialize creationDate Value
	strcpy(this->creationDate, creationDate);
	// Check format of value of creationDate
	// If creationDate Value is not on format, changes into " "(blank)
	char blank[kDateString] = { };
	if (strlen(this->creationDate) == 10) {
		if (this->creationDate[4] != '-' || this->creationDate[7] != '-') {
			strcpy(this->creationDate, blank);
		}
		else {
			for (i = 0; i < 4; i++) {
				if (isdigit(this->creationDate[i]) == 0) {
					strcpy(this->creationDate, blank);
				}
			}
			for (i = 5; i < 7; i++) {
				if (isdigit(this->creationDate[i]) == 0) {
					strcpy(this->creationDate, blank);
				}
			}
			for (i = 8; i < 10; i++) {
				if (isdigit(this->creationDate[i]) == 0) {
					strcpy(this->creationDate, blank);
				}
			}
			strcpy(this->creationDate, creationDate);
		}
	}
	else {
		strcpy(this->creationDate, blank);
	}
}

/*  -- Method Header Comment
	Name	:   DisneyCharacter -- DESTRUCTOR
	Purpose :   To destroy the DisneyCharacter object - free up the memory associated with the object
	Inputs	:	NONE
	Outputs	:	Outputs a final message from the object before being destroyed
	Returns	:	Nothing
*/
DisneyCharacter::~DisneyCharacter(void) {
	printf("Object %s is destroyed.\n", GetName());
}

/*  -- Method Header Comment
	Name	:   ShowInfo
	Purpose :   This method is to be called in order to take a snapshot of the current attribute values
	Inputs	:	NONE
	Outputs	:	Attribute values are printed to the screen
	Returns	:	Nothing
*/
void DisneyCharacter::ShowInfo(void) {
	printf("Object Name : %s\n", GetName());
	printf("Object Created Date : %s\n", GetCreationDate());
	printf("The number of movies in which object stars : %d\n", GetNumMovies());
	printf("The number of parks where the object appearen : %c\n", GetWhichPark());
	printf("\n");
}

/*  -- Method Header Comment
	Name	:   PlaceCharacter
	Purpose :   This mutator method is used to update/change the object's whichPark value
	Inputs	:	whichPark	char	Park which is tring to change values.
	Outputs	:	NONE
	Returns	:	true/false	bool	Indicates whether the whichPark is in correct value
*/
bool DisneyCharacter::PlaceCharacter(char whichPark) {
	// Check the value of whichPark is in range of condition(M, S, A, E, C, N)
	if (whichPark == 'M') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'S') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'A') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'E') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'C') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'N') {
		this->whichPark = whichPark;
		return true;
	}
	else
		return false;
}

/*  -- Method Header Comment
	Name	:   SameMovies
	Purpose :   This mutator method is used to update/change the object's numMovies value
	Inputs	:	&anotherCharater	DisneyCharacter		The address of the object to be replaced
	Outputs	:	NONE
	Returns	:	Nothing
*/
void DisneyCharacter::SameMovies(DisneyCharacter& anotherCharacter) {
	numMovies = anotherCharacter.numMovies;
}

/*  -- Method Header Comment
	Name	:   SetNumMovies
	Purpose :   This mutator method is used to update/change the numMovies in the object
	Inputs	:	numMovies	int 	the numMovies value that is trying to be set
	Outputs	:	NONE
	Returns	:	retCode		bool	indicates whether the numMovies was in range of condition
*/
bool DisneyCharacter::SetNumMovies(int numMovies) {
	bool retCode = false;
	if (numMovies >= 0) {
		this->numMovies = numMovies;
		retCode = true;
		return retCode;
	}
	else {
		return retCode;
	}
}

/*  -- Method Header Comment
	Name	:   SetWhichPark
	Purpose :   This mutator method is used to update/change the object's whichPark value
	Inputs	:	whichPark	char	Park which is tring to change values.
	Outputs	:	NONE
	Returns	:	true/false	bool	Indicates whether the whichPark is in correct value
*/
bool DisneyCharacter::SetWhichPark(char whichPark) {
	// Check the value of whichPark is in range of condition(M, S, A, E, C, N)
	if (whichPark == 'M') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'S') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'A') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'E') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'C') {
		this->whichPark = whichPark;
		return true;
	}
	else if (whichPark == 'N') {
		this->whichPark = whichPark;
		return true;
	}
	else
		return false;
}

/*  -- Method Header Comment
	Name	:	GetName
	Purpose :	Called to return the received name string.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	The character's name
*/
char* DisneyCharacter::GetName(void) {
	memcpy(nameCopy, name, sizeof(name));
	return nameCopy;
}

/*  -- Method Header Comment
	Name	:	GetCreationDate
	Purpose :	Called to return the received date string.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	The character's creation date
*/
char* DisneyCharacter::GetCreationDate(void) {
	memcpy(creationDateCopy, creationDate, sizeof(creationDate));
	return creationDateCopy;
}

/*  -- Method Header Comment
	Name	:	GetNumMovies
	Purpose :	Called to return the received numMovies value.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	The character's numMovies
*/
int DisneyCharacter::GetNumMovies(void) {
	return numMovies;
}

/*  -- Method Header Comment
	Name	:	GetWhichPark
	Purpose :	Called to return the received whichPark character.
	Inputs	:	NONE
	Outputs	:	NONE
	Returns	:	The character's whichPark
*/
char DisneyCharacter::GetWhichPark(void) {
	return whichPark;
}