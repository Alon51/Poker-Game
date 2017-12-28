#include "PokerHand.h"
#include <algorithm>
#include <string>
#include <algorithm>
#include <iostream>//output stream
using namespace std;

//The constractor for the class:
PokerHand::PokerHand(PlayingCard pokerHand[]){

	hand.push_back(pokerHand[0]);
	hand.push_back(pokerHand[1]);
	hand.push_back(pokerHand[2]);
	hand.push_back(pokerHand[3]);
	hand.push_back(pokerHand[4]);
	sort(hand.begin(), hand.end());
}

void PokerHand::displayHand() {

	for (int i = 0; i < 5; i++) {

		if (hand[i].value + 2 <= 10)
			cout << (hand[i].value + 2);
		else if (hand[i].value + 1 == 10)
			cout << 'J';
		else if (hand[i].value + 1 == 11)
			cout << 'Q';
		else if (hand[i].value + 1 == 12)
			cout << 'K';
		else if (hand[i].value + 1 == 13)
			cout << 'A';
		if (hand[i].suit == 0)
			cout << 'H' << "\t";
		else if (hand[i].suit == 1)
			cout << 'S' << "\t";
		else if (hand[i].suit == 2)
			cout << 'D' << "\t";
		else
			cout << 'C' << "\t";
	}
	cout << "\n\n";
}

/**
The ranking function will categorize the hand the user have.
ranking function will compare the cards AFTER the cards got sorted.
*/
void PokerHand::ranking() {

	int count = 0, pair = 0, twoPair = 0, three = 0, four = 0, fullHouse = 0,
		straight = 0, flush = 0, straightFlush = 0, royalFlush = 0;

	for (int i = 1; i < 5; i++) {

		//Check for pair, two pair, three of a kind, four of a kind, full house:

		if (hand[i].value == hand[i - 1].value)
			count++;
		else {

			switch (count) {

			case 1: // One pair:
				
				if (pair == 0) {
					pair++;
					newHand[0] = 1;
					newHand[1] = hand[i - 1].value;
					//Find the kicker:
					//if (i == 4)
						//newHand[2] = hand[i - 2].value;
					//else
						newHand[2] = hand[4].value;
				}
				else {// A situation with two pair (only one situation out of the 3)
					newHand[0] = 2;
					//newHand[1] = hand[i - 1].value; <-- No need, that's happened in the first part
					newHand[2] = hand[i - 1].value; // put the value of the second pair in a new spot 
					newHand[3] = hand[4].value; // That's the kicker spot
				}
				break;

			case 2:// Three cards:
				three++; // <<<<<------------ ?????? need it?
				newHand[0] = 3;
				newHand[1] = hand[2].value;
				//No need for the kicker, players can't get the same 3 cards for each hand.
				//newHand[2] = hand[4].value;
				break;

			case 3: // Four cards:
				//four++;
				newHand[0] = 7;
				newHand[1] = hand[2].value;
				//No need for the kicker, players can't get the same 4 cards for each hand.
				//newHand[2] = hand[4].value;
				break;
			}
			count = 0;
		}
	} // End of for loop (int i = 1; i < 5; i++)

	// If the loop ended with counter positive:
	if (count == 1) {

		if (pair == 0) {// Situation if I have one pair in the end:
			pair++;
			newHand[0] = 1;
			newHand[1] = hand[4].value;
			newHand[2] = hand[2].value;
		}
		else {//One pair already in the hand and now accumulate the second pair:
			//twoPair++;
			newHand[0] = 2;
			newHand[1] = hand[1].value;
			newHand[2] = hand[3].value;

			//Find the kicker:
			if (hand[2].value == hand[1].value)
				newHand[3] = hand[0].value;
			else
				newHand[3] = hand[2].value;

			//pairValueTwo = hand[3].value;
		}
	}
	else if (count == 2) {
		three++;
		newHand[0] = 3;
		newHand[1] = hand[2].value;
		//No need for the kicker, players can't get the same 3 cards for each hand.
		//newHand[2] = hand[1].value;
	}
	else if (count == 3) {
		//four++;
		newHand[0] = 7;
		//newHand[1] = hand[2].value;
		//No need for the kicker, players can't get the same 4 cards for each hand.
		//newHand[2] = hand[0].value;
	}

	//FULL HOUSE:
	if (three == 1 && pair == 1) {
		//fullHouse++;
		//three--;
		//pair--;
		newHand[0] = 6;
		newHand[1] = hand[2].value;
		
		//Not possible to have two identical three in both hands.
		//highest three will win.

		//newHand[1] = hand[0].value;
		//newHand[2] = hand[4].value;
		//No kicker
	}

	if (newHand[0] == 0) {

		//=============================================================

		//STRAIGHT:

		for (int i = 0; i < 4; i++) {

			if (hand[i + 1].value - hand[i].value == 1)
				straight++;
			else {
				straight = 0;
				break;
			}
		}

		if (straight > 0) {
			straight = 1;
			newHand[0] = 4;
			newHand[1] = hand[4].value;
		}
		//=============================================================

		int club = 0, diamond = 0, heart = 0, spade = 0;

		for (int i = 0; i < 5; i++) {

			if (hand[i].suit == PlayingCard::CLUB)
				club++;
			else if (hand[i].suit == PlayingCard::DIAMOND)
				diamond++;
			else if (hand[i].suit == PlayingCard::HEART)
				heart++;
			else
				spade++;
		}

		if (club == 5 || diamond == 5 || heart == 5 || spade == 5) {
			flush++;
			newHand[0] = 5;
			newHand[1] = hand[4].value;
		}

		if (flush == 1 && straight == 1) {

			if (hand[0].value == PlayingCard::TEN && hand[4].value == PlayingCard::ACE) {
				royalFlush++;
				newHand[0] = 9;
			}
			else {
				straightFlush++;
				newHand[0] = 9;
				newHand[1] = hand[4].value;
			}

			straight--;
			flush--;
		}
		//=============================================================

		//If the player has nothing then the highest value of the cards will be returned:
		if (pair == three == four == fullHouse == straight == flush == straightFlush == royalFlush) {
			newHand[0] = 0;

			//No need to enter to the array the value of the kicker since that in case of equal the 
			//cards will be checked one by one.

			//newHand[1] = hand[4].value;
		}
		
	}//End of if (newHand[0] != 0)

	cout << "The new hand is: " << rankingMenue.at(newHand[0]) << " " << newHand[1] + 2 << " ";
	if (newHand[2] != 0) // possible that I need anouther statment for 'J Q K A' 
		if (newHand[2] <= 8)
			cout << newHand[2] + 2 << endl;
		else
			cout << newHand[2] + 1 << endl;
	else
		cout << newHand[2]  << endl;

	//return newHand;
}

bool PokerHand::operator<(PokerHand handTwo) {

	//this->ranking(); // The object that called the overloading
	//otherHand.ranking(); // The object that were passed as an arrgument

	//cout << distance(rankingMenue.begin(), find(begin(rankingMenue), end(rankingMenue), this->ranking()[0])) << endl;

	cout << this->newHand[0] << endl;
	cout << handTwo.newHand[0] << endl;

	if (this->newHand[0] < handTwo.newHand[0])
		return true;

	return false;
}

bool PokerHand::operator>(PokerHand handTwo) {

	if (this->newHand[0] > handTwo.newHand[0])
		return true;

	return false;
}

bool PokerHand::operator==(PokerHand handTwo) {	

		switch (this->newHand[0]) {

		case 0://KICKER

			for (int i = 4; i >= 0; i--) {

				if (this->hand[i] > handTwo.hand[i]) {
					cout << "First hand high card is greater" << endl;
					return false;
				}
				else if (this->hand[i] < handTwo.hand[i]) {
					cout << "Second hand high card is greater" << endl;
					return false;
				}
				//The third case is that thery're equal which in this case do nothing.
			}

			return true; // Both players have the same cards (IN VALUE)

		case 1://PAIR
			if (this->newHand[1] > handTwo.newHand[1])
				cout << "first-hand is greater (higher pair)" << endl;
			else if (this->newHand[1] < handTwo.newHand[1])
				cout << "second-hand is greater (higher pair)" << endl;
			else { // H1 P is equal H2 P 
				//Checking the kicker first:
				if (this->newHand[2] > handTwo.newHand[2])
					cout << "First-hand's kicker is greater, first-hand is greater" << endl;
				else if (this->newHand[2] < handTwo.newHand[2])
					cout << "Second-hand's kicker is greater, second-hand is greater" << endl;
				else // Both the pair and the kickers are the same:
					return true;
				//Might be more situations in which there are more cards to check after the highest kicker
			}
			break;
		case 2://TWO PAIR
			
			if (this->newHand[2] > handTwo.newHand[2]) // H1 P2 is greater than H2 P2 
				cout << "first hand pairs are greater" << endl;
			else if(this->newHand[2] < handTwo.newHand[2]) // H2 P2 is greater than H1 P2
				cout << "second hand pairs are greater" << endl;
			else { //H1 P2 is equal H2 P2 then:
				if(this->newHand[1] > handTwo.newHand[1]) // H1 P1 is greater than H2 P1
					cout << "first hand pairs are greater" << endl;
				else if (this->newHand[1] < handTwo.newHand[1]) // H1 P1 is greater than H2 P1
					cout << "second hand pairs are greater" << endl;
				else { // H1 P1 is equal H2 P1 then:
					if (this->newHand[3] > handTwo.newHand[3])
						cout << "first hand pairs are greater" << endl;
					else if (this->newHand[3] < handTwo.newHand[3]) // H1 P1 is greater than H2 P1
						cout << "second hand pairs are greater" << endl;
					else // Kickers are the same:
						return true;
				}
			}
		case 3: // THREE
			if (this->newHand[1] > handTwo.newHand[1])
				cout << "Hand one three cards are greater" << endl;
			else
				cout << "Second hand three cards are greater" << endl;
			break;
		case 4: // STRAIGHT
			if (this->newHand[1] > handTwo.newHand[1])
				cout << "Hand one is greater" << endl;
			else if (this->newHand[1] < handTwo.newHand[1])
				cout << "Hand two is greater" << endl;
			else
				return true;
		case 5: // FLUSH
	
			for (int i = 4; i >= 0; i--) {
				
				if (this->hand[i] > handTwo.hand[i]){
					cout << "First hand flush is greater" << endl;
					return false; }
				else if (this->hand[i] < handTwo.hand[i]){
					cout << "Second hand flush is greater" << endl;
					return false; }
				//The third case is that thery're equal which in this case do nothing.
			}
			return true;
			
		case 6: // FULL HOUSE

			/*If two or more players have a full house then the player with the best three of a kind wins.
			If those are the same (can't be the same unless playing with two decks of cards) then the player 
			with the best pair wins.*/

			// In any hand the middle card must be one of the three cards.
			// No need to check for the pair since that the game is with only one deck of cards.

			if (this->newHand[1] > handTwo.newHand[1])
				cout << "Hand one full house is greater" << endl;
			else
				cout << "Hand two full house is greater" << endl;
			break;
		case 7: //FOUR:
			if (this->newHand[1] > handTwo.newHand[1])
				cout << "Hand one four of a kind is greater" << endl;
			else
				cout << "Hand two four of a kind is greater" << endl;
		case 8://STRAIGHT FLUSH
			if (this->newHand[1] > handTwo.newHand[1])
				cout << "Hand one straight flush is greater" << endl;
			else
				cout << "Hand two straight flush is greater" << endl;
		case 9://ROYAL FLUSH
			return true; // only one case for royal flush

		}// End of switch

	return false;
}