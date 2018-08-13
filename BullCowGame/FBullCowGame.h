#pragma once
#include <string>

class FBullCowGame {
public:
	int GetMaxTries() const; //Getters
	int GetCurrentTry() const;
	bool WinGame() const;

	FBullCowGame(); //Constructor

	void Reset(); //TODO Make a more rich return value.
	bool CheckGuessValidity(std::string); //TODO Make a more rich return value.
	// Provide method for counting bulls and cows and incrementing try number.

private:
	// See construcor for initialization
	int MyMaxTries;
	int MyCurrentTry;
};