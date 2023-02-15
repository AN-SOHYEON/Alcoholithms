/*
프로그래머스 마법의 엘리베이터

1. 숫자를 더해서 올림수로 만든다음 한번에 빼버리거나
2. 지금 숫자에서 차례로 빼기만 해서 0으로 만들거나.
**근데 자리수 별로 1, 2방법이 섞일 수도 있다.
-> 지금 자리수의 숫자가 4 이하이면 -1 하는 것이 더 적은 횟수이다.
                   6 이상이면 +1 하는 것이 더 적은 횟수이다.
                   5 이면 지금 자릿수에서는 더하도 빼도 똑같지만 앞자리 숫자가 있으면
                   앞자리 숫자에 영향을 줄 수 있으니 앞자리 숫자를 고려하여 뺄지말지 정한다.
 */

public class Solution_148653 {

  public static int solution(int storey) {
    int answer = 0;

    while (storey > 0) {
      int num = storey % 10;
      if (num < 5) {
        answer += num;
        storey -= num;
      } else if (num > 5) {
        answer += (10 - num);
        storey += (10 - num);
      } else {
        int prev_num = storey % (100) / 10;
        if (prev_num < 5) {
          answer += num;
          storey -= num;
        } else {
          answer += (10 - num);
          storey += (10 - num);
        }
      }
      storey /= 10;
      System.out.println("answer is now " + answer);
    }
    return answer;
  }

  public static void main(String[] args) {
    int s1 = 16; //	6
    int s2 = 2554; //	16

//    System.out.println(16 % 10);

    System.out.println("case1");
    System.out.println(solution(555));
    System.out.println("case2");
    System.out.println(solution(75));
  }
}
