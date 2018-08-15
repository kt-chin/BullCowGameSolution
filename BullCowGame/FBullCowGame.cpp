#include "FBullCowGame.h"
#include <cctype>
#include <algorithm>

using int32 = int;

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length(); }
bool FBullCowGame::WinGame() const {return bGameIsWon; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 10;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD[6] = { "plunder", "crusade", "ace", "nags", "overhauling", "playdough"};
	for (int i = 0; i < 6; i++)
	{
		MyHiddenWord = HIDDEN_WORD[rand() % 6];
	}
	bGameIsWon = false;
	MyCurrentTry = 1;
	return;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
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
	else
	{
		return EGuessStatus::OK;
	}
	//If Guess is not isogram
		//return error
	//If Guess is not all lowercase
		//return error
	//If Guess length is wrong
		//return error
	// otherwise
		//return ok
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
