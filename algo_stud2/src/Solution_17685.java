
import java.util.Arrays;

public class Solution_17685 {

  public static int diffMin(String[] words, int index) {
    int min = 0;
    int list = words.length;
    int comp_word_len = words[index].length();
    boolean equal_list[] = new boolean[list];
    Arrays.fill(equal_list,true);

    for (int i = 0; i < comp_word_len; i++) {
      String str = words[index].substring(0, i);
      boolean not_same_flag = true;
      for (int j = 0; j < list; j++) {
        if (j == index || equal_list[j] == false)
          continue;
        if (words[j].startsWith(str)) { // str로 시작하는 단어가 있다.
          min = i;
          not_same_flag = false;
          break;
        } else {
          equal_list[j] = false;
        }
      }
      if (not_same_flag == true)
        break;
    }
    return min + 1;
  }

  public static int solution(String[] words) {
    int answer = 0;

    Arrays.sort(words);
    for (int i = 0; i < words.length; i++) {
      answer += diffMin(words, i);
    }
    return answer;
  }

  public static void main(String[] args) {
    String[] words = {"word","war","warrior","world"};

    System.out.println(solution(words));
  }
}
