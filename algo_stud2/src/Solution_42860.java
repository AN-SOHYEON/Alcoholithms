public class Solution_42860 {
  public static int solution(String name) {
    int answer = 0;
    int size = name.length();

    int diff = 0;
    int move = size - 1;
    for (int i = 0; i < size; i++) {
      diff = name.charAt(i) - 'A';
      if ((diff / 13) > 0) { // over 14
        diff = '[' - name.charAt(i);
      }
      answer += diff;

      // move
      int index = i + 1;
      while(index < size && name.charAt(index) == 'A'){
        index++;
      }
      move = Math.min(move, i * 2 + size - index);
      move = Math.min(move, (size - index) * 2 + i);
    }
    return answer + move;
  }

  public static void main(String[] args) {
    System.out.println(solution("JEROEN"));
    System.out.println(solution("JAN"));
  }
}
