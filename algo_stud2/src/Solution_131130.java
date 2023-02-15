import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class Solution_131130 {

  public static int findGroup(int[] cards, boolean[] card_in_group, int index) {
    int num = 0;

    while (!card_in_group[index]) {
      num++;
      card_in_group[index] = true;

      index = cards[index] - 1;
    }
    return num;
  }

  public static int solution(int[] cards) {
    boolean[] card_in_group = new boolean[cards.length];
    Arrays.fill(card_in_group, false);
    PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    for (int i = 0; i < cards.length; i++) {
      if (!card_in_group[i]) {
        pq.add(findGroup(cards, card_in_group, i));
      }
    }

    if (pq.size() == 1)
      return 0;
    return pq.poll() * pq.poll();
  }

  public static void main(String[] args) {
    int[] cards = {8, 6, 3, 7, 2, 5, 1, 4};

    System.out.println(solution(cards));
  }
}
