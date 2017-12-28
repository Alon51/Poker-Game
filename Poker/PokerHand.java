public class PokerHand implements Comparable<PokerHand>
{
  /* public int compareTo(PokerHand otherHand) {
    // This is for you to implement
  }
  ... */
  public ArrayList<PlayingCard> hand;
  public PokerHand(PlayingCard C1,
                   PlayingCard C2,
                   PlayingCard C3,
                   PlayingCard C4,
                   PlayingCard C5) {
    hand.add(C1);
    hand.add(C2);
    hand.add(C3);
    hand.add(C4);
    hand.add(C5);
    Collections.sort(hand);
  }
}
