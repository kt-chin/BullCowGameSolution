#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//all values initialized to 0
struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	int32 GetMaxTries() const; //Getters
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	EGuessStatus CheckGuessValidity(FString) const;
	bool WinGame() const;

	FBullCowGame(); //Constructor

	void Reset(); //TODO Make a more rich return value.
	

	// Counts bulls and cows and increases try number assuming valid guess
	FBullCowCount SubmitValidGuess(FString);

private:
	// See constructor for initialization
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
};