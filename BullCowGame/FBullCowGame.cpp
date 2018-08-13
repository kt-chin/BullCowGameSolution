#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const {return MyCurrentTry; }

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::WinGame() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

//Recieves a valid guess, increments turn and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;

	//setup return value
	FBullCowCount BullCowCount;

	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		//compare letters against hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
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
	
	return BullCowCount;
}
