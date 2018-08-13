/* This is the console executable that makes use of the BullCow Class
This acts as the view in a MVC pattern, and is responsible for all user
Interactions. For game logic, see the FBullCowGame class.
*/

#include<iostream>
#include<string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void GameIntro();
void PlayGame();
FText GetGuess();
bool PlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main()
{
	do
	{
		GameIntro();
		PlayGame();
	} 
	while (PlayAgain());

	return 0;  //Exit the application
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	//loops Guess return for no. of turns
	//constexpr int NUMBER_OF_TURNS = 10;
	//TODO change from FOR to WHILE loop once we validate tries.
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows << std::endl;
		// Submit valid guess to the game
		std::cout << std::endl;
		//print number of Bulls and Cows
	}
	// TODO summarise game.
}

void GameIntro()
{
	// Introduce the game
	//Constexpr executes at compile time
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome To Bulls And Cows, A Fun Word Game!" << std::endl;
	std::cout << "Can You Guess The " << WORD_LENGTH;
	std::cout << " Letter Isogram I'm Thinking Of?" << std::endl;
	std::cout << BCGame.GetMaxTries() << std::endl;
	return;
}


FText GetGuess()
{	
	//get Guess from player
	int32 CurrentTry = BCGame.GetCurrentTry();

	// ensure Guess is empty as we want to fill with input
	FText Guess = "";
	std::cout << "Try " << CurrentTry << " - Input Guess : " << std::endl;
	std::getline(std::cin, Guess);
	std::cout << std::endl;
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


