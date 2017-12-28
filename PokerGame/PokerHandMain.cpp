#include "PokerHand.h"
#include <iostream>
//#include "PokerHandMain.h"
using namespace std;

/**
sameCards function is a recursive function to compare cards in a given hand

return - true if found 2 cards matched, false otherwise
*/
bool sameCards(PlayingCard checkHand[], int start) {

	//Base case:
	if (start == 4)
		return false;
	else
		for (int j = start; j <= 4; j++){

			if (j != 4 && (checkHand[start].value == checkHand[j + 1].value && checkHand[start].suit == checkHand[j + 1].suit))
				return true; //If two cards in the same hand are the same
			else if (j == 4) 
				return sameCards(checkHand, start + 1); // Call the sameCards function again to check the rest of the cards
		}
}

//To make sure that the hands are not the same:
int sameHand(PlayingCard firstHand[], PlayingCard secondHand[]) {

	if (sameCards(firstHand, 0)) {//check if cards are the same in the same hand:

		cout << "Some of the cards in your first-hand are the same, please check them again" << endl;
		return 2;
	}
	else { // No same crads in hand one, now check hand two:

		// Checking hand two:
		if (sameCards(secondHand, 0)) {

			cout << "Some of the cards in your second-hand are the same, please check them again" << endl;
			return 3;
		}
		else { // Here is when both hands are qualified for the comparison between the two hands:
			
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (firstHand[i].suit == secondHand[j].suit) {
						if (firstHand[i].value == secondHand[j].value) {
							
							//cout << firstHand[i].value << " " << firstHand[i].suit <<
							//" VS " << secondHand[j].value << " " << secondHand[j].suit << endl;
							
							return 1;// Some cards are the same
						}
					}
				}
			}
		}
	}

	return 0; // No duplicates
}

int main() {
	
	//Creating two hands in the form of arrays before using vectors:
	PlayingCard handOne[5], handTwo[5];
	
	//Making the cards:
	handOne[0] = PlayingCard(PlayingCard::DIAMOND, PlayingCard::ACE);
	handOne[1] = PlayingCard(PlayingCard::HEART, PlayingCard::ACE);
	handOne[2] = PlayingCard(PlayingCard::SPADE, PlayingCard::ACE);
	handOne[3] = PlayingCard(PlayingCard::CLUB, PlayingCard::FIVE);
	handOne[4] = PlayingCard(PlayingCard::DIAMOND, PlayingCard::FIVE);

	handTwo[0] = PlayingCard(PlayingCard::DIAMOND, PlayingCard::THREE);
	handTwo[1] = PlayingCard(PlayingCard::HEART, PlayingCard::THREE);
	handTwo[2] = PlayingCard(PlayingCard::SPADE, PlayingCard::THREE);
	handTwo[3] = PlayingCard(PlayingCard::CLUB, PlayingCard::THREE);
	handTwo[4] = PlayingCard(PlayingCard::SPADE, PlayingCard::EIGHT);

	//Making sure that the cards are good:
	switch (sameHand(handOne, handTwo)) {
	
		case 0:{ //Case in which all the cards are good to make comparisons with (no duplicates)

			//Creating the hands:
			PokerHand firstHand(handOne), secondHand(handTwo);

			//Display the hand:
			cout << "First hand:  "; firstHand.displayHand();
			cout << "Second hand: "; secondHand.displayHand();

			firstHand.ranking();
			secondHand.ranking();

			if (firstHand < secondHand)
				cout << "First hand is smaller" << "\n\n";
			else if (firstHand > secondHand)
				cout << "First hand is greater" << "\n\n";
			else {
				if (firstHand == secondHand)
					cout << "It's a tie - split the cash!" << "\n";
			}
			break;
		}
		case 1: {cout << "You inserted cards that exsist in both hands, please check them again." << endl; break; }
		case 2: {cout << endl;}
	}

}