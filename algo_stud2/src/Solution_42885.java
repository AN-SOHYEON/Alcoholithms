import java.util.Arrays;

public class Solution_42885 {
  public static int solution(int[] people, int limit) {
    int answer = 0;
    int end = people.length - 1;

    Arrays.sort(people); // 무게 순으로 정렬한다.
    int i = 0;
    while (i <= end) {
      if (people[i] + people[end] <= limit)
        i++;  // 가장 작은 무게부터 짝이 맞으면 다음 작은 무게 인덱스로 이동
      end--;  // 짝이 맞으면 2이 타고 안맞아도 혼자 타야 하므로 end는 계속 줄고
      answer++; // answer, boat의 수는 계속 늘어난다.
    }
    return answer;
  }

  public static void main(String[] args) {
    int [] people = {70, 50, 80, 50};
    int limit = 100;

    System.out.println("result is " + solution(people, limit));
  }
}
