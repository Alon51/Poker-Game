public class PlayingCard implements Comparable<PlayingCard>
{
  public int compareTo(PlayingCard card) {
    return this.value.compareTo(card.value);
  }
  public enum Suit {
    HEART, SPADE, DIAMOND, CLUB
  };
  public enum Value {
    TWO, THREE, FOUR, FIVE, SIX,
    SEVEN, EIGHT, NINE, TEN, JACK,
    QUEEN, KING, ACE
  };

  public Suit suit;
  public Value value;

  public PlayingCard(Suit suit, Value value)
  {
      this.suit = suit;
      this.value = value;
  }

  public static void main(String args[])
  {
    PlayingCard C1 = new PlayingCard(
      PlayingCard.Suit.HEART,
      PlayingCard.Value.TWO);
    PlayingCard C2 = new PlayingCard(
      PlayingCard.Suit.SPADE,
      PlayingCard.Value.FIVE);
    System.out.println(C1.compareTo(C2));
    System.out.println(C2.compareTo(C1));
    System.out.println(C1.compareTo(C1));
  }
}