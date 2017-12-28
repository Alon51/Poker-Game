#pragma once
#include "PlayingCard.h"
#include <vector>
#include <array>
using namespace std;

#ifndef PokerHand_h
#define PokerHand_h

class PokerHand {

public:

	//The constractor for the class:
	PokerHand(PlayingCard []);

	//To compare the two hands:
	bool operator<(PokerHand);
	bool operator>(PokerHand);
	bool operator==(PokerHand);

	//Display the hand:
	void displayHand();

	//Ranking the five cards:
	void ranking(); // Returnning an array

private:

	//Creating an array to hold the hands in ascending  order:
	array <string, 10> rankingMenue = { "KICKER", "PAIR", "TWO PAIR",
										"THREE", "STRAIGHT", "FLUSH",
										"FULLHOUSE", "FOUR", "STRAIGHTFLUSH",
										"ROYALFLUSH" };
	
	//An array to hold the new hand:
	int newHand[4] = {0,0,0,0}; 
	//First spot for the hand name (the enum class).
	//Second spot for the highest value/s of the hand.
	//Last spot for the Kicker.

	//Creating a vector (array) to hold 5 cards:
	vector<PlayingCard> hand;
};
#endif