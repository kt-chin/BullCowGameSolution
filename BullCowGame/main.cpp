/* This is the console executable that makes use of the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all user
Interactions. For game logic, see the FBullCowGame class.
*/

#include<iostream>
#include<string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void GameBeginAndIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool PlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main()
{
	do
	{
		GameBeginAndIntro();
		PlayGame();
	} while (PlayAgain());

	return 0;  //Exit the application
}

void PlayGame()
{

	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guess while the game is NOT won and tries still remain
	//loops Guess return for no. of turns
	while (!BCGame.WinGame() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << "\n\n";

	}
	PrintGameSummary();

	// TODO summarise game.
	return;
}

void PrintGameSummary()
{
	if (BCGame.WinGame())
	{
		std::cout << "GG WP!\n\n";
	}
	else
	{
		std::cout << "Bad Luck Nerd!\n\n";
	}
}

void GameBeginAndIntro()
{
	// Introduce the game
	//Constexpr executes at compile time
	//Reset applied to begin the 
	BCGame.Reset();
	std::cout << "\nWelcome To Bulls And Cows, A Fun Word Game! \n\n";
	std::cout << "Can You Guess The " << BCGame.GetHiddenWordLength();
	std::cout << " Letter Isogram I'm Thinking Of?\n\n";
	std::cout << "Max Attempts: " << BCGame.GetMaxTries() << "\n\n";
	return;
}

//Loop continually until valid guess input
FText GetValidGuess()
{	
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		//TODO change to get valid guess
		//get Guess from player
		int32 CurrentTry = BCGame.GetCurrentTry();
		// ensure Guess is empty as we want to fill with input

		std::cout << "Try " << CurrentTry << " - Input Guess : " << std::endl;
		std::getline(std::cin, Guess);
		std::cout << std::endl;

		//Check status then give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please Enter A " << BCGame.GetHiddenWordLength() << " Letter Word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please Enter A Valid Word Without Repeating Letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please Enter Guess In Lower Case Letters. \n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //Keep looping until we get a valid input!/No Errors!
	return Guess;
}

bool PlayAgain()
{
	std::cout << "Would you like to play again? (y/n)" << std::endl;
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	std::cout << std::endl;
}


