#pragma once

//#ifndef PokerHand_h
//#define PokerHand_h

class PlayingCard {

public:
	
	//Constractor for the general case:
	PlayingCard() {};

	//Overloading the '<' sign to compare two card's values:
	bool operator<(PlayingCard card) {
		return this->value < card.value;
	}
	bool operator>(PlayingCard card) {
		return this->value > card.value;
	}
	

	//Two enum classes to describe a single card:
	enum Suit {
		HEART, SPADE, DIAMOND, CLUB
	};
	enum Value {
		TWO, THREE, FOUR, FIVE, SIX,
		SEVEN, EIGHT, NINE, TEN, JACK,
		QUEEN, KING, ACE
	};

	Suit suit;   //An instance of the enum suit class 
	Value value; //An instance of the enum value class 

	//Constractor for matching the suit and value:
	PlayingCard(Suit suit, Value value){

		this->suit = suit;
		this->value = value;
	}
};
//#endif