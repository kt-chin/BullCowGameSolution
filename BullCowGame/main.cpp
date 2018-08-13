#include<iostream>
#include<string>
#include "FBullCowGame.h"

void GameIntro();
void PlayGame();
std::string GetGuess();
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
	int MaxTries = BCGame.GetMaxTries();
	BCGame.Reset();
	//loops Guess return for no. of turns
	//constexpr int NUMBER_OF_TURNS = 10;
	//TODO change from FOR to WHILE loop once we validate tries.
	for (int i = 0; i < MaxTries; i++)
	{
		std::cout << "Your Guess Was : " << GetGuess() << std::endl; //TODO make get guess valid
		std::cout << std::endl;
		// Submit valid guess to the game
		//print number of Bulls and Cows
	}
	// TODO summarise game.
}

void GameIntro()
{
	// Introduce the game
	//Constexpr executes at compile time
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome To Bulls And Cows, A Fun Word Game!" << std::endl;
	std::cout << "Can You Guess The " << WORD_LENGTH;
	std::cout << " Letter Isogram I'm Thinking Of?" << std::endl;
	std::cout << BCGame.GetMaxTries() << std::endl;
	return;
}


std::string GetGuess()
{	
	//get Guess from player
	int CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << " : Input Guess : " << std::endl;
	std::getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

bool PlayAgain()
{
	std::cout << "Would you like to play again? (y/n)" << std::endl;
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	std::cout << std::endl;
}


