#pragma once
#include "FBullCowGame.h"
#include <cctype>
#include <algorithm>
#include <vector>
#include <time.h>

#include <map>
//to make syntax unreal friendly
#define TMap std::map 
using int32 = int;


int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length(); }
bool FBullCowGame::WinGame() const {return bGameIsWon; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32> WordLengthToMaxTries{ {3,4},{4,7},{5,10},{6,16},{7,20},{8,22},{9,25},{10,25} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 10;
	MyMaxTries = MAX_TRIES;
	srand(time(NULL)); //To randomize every time a different sequence, we need to SEED the rand function.
	int32 Randomizer = rand() % 8;
	std::vector<FString> HIDDEN_WORD = { "plunder", "crusade", "ace", "nags", "overhauling", "playdough", "forecast", "machine"}; //Word MUST be isogram
	for (int i = 0; i < 8; i++)
	{
		MyHiddenWord = HIDDEN_WORD[Randomizer];
	}
	bGameIsWon = false;
	MyCurrentTry = 1;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (std::any_of(Guess.begin(), Guess.end(), isupper)) // Checks beginning of string to end of string if any characters are upper case
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsAlphabet(Guess))
	{
		return EGuessStatus::Not_Letters;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

//Recieves a valid guess, increments turn and returns count.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	//Setup Return Value
	FBullCowCount BullCowCount;


	//loop through all letters in the Hidden Word
	int32 WordLength = MyHiddenWord.length(); //assuming same length as guess

	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		//compare letters against Guess word
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			//if they match, then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				//If they're in the same place
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++; //increment Bulls

				}
				else
				{
					BullCowCount.Cows++; //else increment cows
				}

			}
			
		}
	}
	if (BullCowCount.Bulls == WordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 + 1 letter words as isograms
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) // Loop For all LETTERS of the WORD (Range Loop)
	{
		Letter = tolower(Letter);//handle mixed case
		if (LetterSeen[Letter])
		{
			return false; // We do NOT have an isogram at this stage
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsAlphabet(FString Word) const
{
	for (int32 i = 0; i < Word.length(); i++)
	{
		if (isalpha(Word[i])) //checks to see if the iterated string has only alphabet
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
