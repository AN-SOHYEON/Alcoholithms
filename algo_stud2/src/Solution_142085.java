import java.util.Collections;
import java.util.PriorityQueue;

public class Solution_142085 {
  public static int solution(int n, int k, int[] enemy) {

    PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
    int round = enemy.length;
    int answer = round; // 가진 round를 다 돌았을때 answer이 초기화되지 않기 때문에 처음에 round수로 초기화해야함!
    int pass = k;

    if (enemy[0] > n && pass == 0)
      return -1;

    for (int i = 0; i < round; i++) {
      n = n - enemy[i];
      pq.add(enemy[i]); // 삭제한 적군의 수를 라운드별로 저장 (적군의 순 내림차순->FIFO)
      if (n < 0 && pass > 0 && !pq.isEmpty()) {
        n = n + pq.poll();
        pass--;
      } else if (n < 0) {
        answer = pq.size() - 1 + k ;
        break;
      }
    }
    return answer;
  }


  public static void main(String[] args) {
    int n = 2;
    int k = 4;
    int[] enemy = {3, 3, 3, 3};

    System.out.println(solution(n, k, enemy));


  }
}
