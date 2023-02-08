#pragma once
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define kNameString         50
#define kDateString         11
#define kLetter             46
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

/*
	-* CLASS COMMENT *-
	NAME    :	DisneyCharacter
	PURPOSE :	The purpose of this class is to print character's discription.
				The discription has character's name, creation date, counts of movies, and stars which park
*/
class DisneyCharacter {
	/* ====================================== */
	/*              PUBLIC                    */
	/* ====================================== */
public:
	/* -------------- ATTRIBUTES ------------ */
	/* ---------- METHOD PROTOTYPES --------- */
	DisneyCharacter(char* name, char* creationDate, int numMovies, char whichPark);		// Initialization of data members(take 4 members)
	DisneyCharacter(char* name, char* creationDate);									// Initialization of data members(take 2 members, left - numMovies = 0, whichPark = N
	~DisneyCharacter(void);																// Destructor

	void ShowInfo(void);									// Method used to format the output of the object's data members	
	bool PlaceCharacter(char whichPark);					// A method that puts a character's position in line with another character's position
	void SameMovies(DisneyCharacter& anotherCharacter);		// A method that makes the character's appearance the same

	char* GetName(void);					// Accessor - name
	char* GetCreationDate(void);			// Accessor - creationDate
	int GetNumMovies(void);					// Accessor - numMovies
	char GetWhichPark(void);				// Accessor - whichPark

	bool SetNumMovies(int numMovies);		// Mutator - numMovies
	bool SetWhichPark(char whichPark);		// Mutator - whichPark

	/* ====================================== */
	/*              PRIVATE                   */
	/* ====================================== */
private:
	/* -------------- CONSTANTS ------------- */
	/* -------------- ATTRIBUTES ------------ */
	char name[kNameString];					// a name string from user or constructor
	char nameCopy[kNameString];				// Variables for safe copying of name strings
	char creationDate[kDateString];			// a date string from user or constructor
	char creationDateCopy[kDateString];		// Variables for safe copying of date strings
	int numMovies;							// Integer variable to store the number of movie appearances
	char whichPark;							// A character variable indicating which park the person appeared in.
};
