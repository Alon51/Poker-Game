class PokerHand {
public:
 /* bool operator<(PokerHand otherHand) {
    // This is for you to implement;
  }
  ... */
  vector<PlayingCard> hand;
  PokerHand(PlayingCard C1, PlayingCard C2,
            PlayingCard C3, PlayingCard C4,
            PlayingCard C5) {
    hand.push_back(C1);
    hand.push_back(C2);
    hand.push_back(C3);
    hand.push_back(C4);
    hand.push_back(C5);
    sort(hand.begin(),hand.end());
  }
};