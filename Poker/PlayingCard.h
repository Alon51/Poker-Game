class PlayingCard {
public:
  bool operator<(PlayingCard card) {
    return this->value < card.value;
  }
  enum Suit {
    HEART, SPADE, DIAMOND, CLUB
  };
  enum Value {
    TWO, THREE, FOUR, FIVE, SIX,
    SEVEN, EIGHT, NINE, TEN, JACK,
    QUEEN, KING, ACE
  };

  Suit suit;
  Value value;

  PlayingCard(Suit suit, Value value)
  {
      this->suit = suit;
      this->value = value;
  }
};

int main()
{
  PlayingCard *C1 = new PlayingCard(PlayingCard::HEART,
                                    PlayingCard::TWO);
  PlayingCard *C2 = new PlayingCard(PlayingCard::SPADE,
                                    PlayingCard::FIVE);
  cout << ((*C1) < (*C2)) << endl;
  cout << ((*C2) < (*C1)) << endl;
  cout << ((*C1) < (*C1)) << endl;
}