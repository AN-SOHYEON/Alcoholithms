import java.util.ArrayList;
import java.util.List;

public class Solution_134239 {

  public static double sumOfIntegral(double[] integral, int begin, int end) {
    double sum = 0;

    if (begin <= end) {
      for (int i = begin; i < end; i++) {
        if (i >= integral.length)
            break;
        sum += integral[i];
      }
    } else {
      sum = -1.0;
    }

    return sum;
  }

  public static double[] calcIntegralOfRange(int[][] ranges, double[] integral) {
    double[] answer = new double[ranges.length];

    for (int i = 0; i < answer.length; i++) {
      int end = integral.length + ranges[i][1];
      System.out.println("begin : " + ranges[i][0] + " end : " + end);
      answer[i] = sumOfIntegral(integral, ranges[i][0], end);
    }

    return answer;
  }

  public static double[] calcIntegral(List<Integer> sequence) {
    double[] integral = new double[sequence.size() - 1];

    for (int i = 0; i < sequence.size() - 1; i++) {
      integral[i] = (sequence.get(i) + sequence.get(i + 1)) / 2.0;
    }

    return integral;
  }

  public static List<Integer> calcCollatz(int k) {
    List<Integer> sequence = new ArrayList<>();
    sequence.add(k);
    while (k > 1) {
      if ((k % 2) == 0) {
        k /= 2;
      } else {
        k = k * 3 + 1;
      }
      sequence.add(k);
    }
    return sequence;
  }

  public static double[] solution(int k, int[][] ranges) {
    // 1.
    List<Integer> sequence = calcCollatz(k);

    // 2.
    double[] integral = calcIntegral(sequence);

    // 3.
    double[] answer = calcIntegralOfRange(ranges, integral);

    return answer;
  }

  public static void main(String[] args) {
    int k = 5;
    int [][] ranges = {{0,0},{0,-1},{2,-3},{3,-3}};

    double[] answer = solution(k, ranges);
    for (int i = 0; i < answer.length; i++) {
      System.out.println("answer : " + answer[i]);
    }
  }
}

/*
* 1. 우박수열을 구하여 저장한다.
* 2. 구간을 1단위로 끊어 정적분 한다.
* 3. 입력된 구간만큼 정적분한 값을 더하여 최종값을 구한다.
* */