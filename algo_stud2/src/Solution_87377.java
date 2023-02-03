import java.util.ArrayList;
import java.util.Collections;

public class Solution_87377 {

  public static double[] findIntersection(int[] line1, int[] line2, double under) {
    double[] intersection = new double[2];

    intersection[0] = (line1[1]*line2[2] - line1[2]*line2[1]) / under;
    intersection[1] = (line1[2]*line2[0] - line1[0]*line2[2]) / under;

    return intersection;
  }

  public static boolean isInteger(double[] intersection, ArrayList<Integer> x, ArrayList<Integer> y) {

    if (intersection[0] != (int) intersection[0] || intersection[1] != (int) intersection[1])
      return false;

    x.add((int) intersection[0]);
    y.add((int) intersection[1]);
    return true;
  }

  public static void findMinMax(int[] minmax, ArrayList<Integer> x, ArrayList<Integer> y) {
    minmax[0] = Collections.min(x);
    minmax[1] = Collections.max(x);
    minmax[2] = Collections.min(y);
    minmax[3] = Collections.max(y);
  }

  public static void drawPaper(ArrayList<Integer> x, ArrayList<Integer> y, ArrayList<String> ans, int[] minmax) {
    int width = minmax[1] - minmax[0] + 1;
    int height = minmax[3] - minmax[2] + 1;

    StringBuilder s = new StringBuilder();
    for(int i = 0; i < width; i++){
      s.append(".");
    }

    for (int i = 0; i < height; i++) {
      ans.add(String.valueOf(s));
    }
  }

  public static String[] solution(int[][] line) {
    ArrayList<String> ans = new ArrayList<>();
    ArrayList<Integer> x = new ArrayList<>();
    ArrayList<Integer> y = new ArrayList<>();
//    ArrayList<int[]> intersections = new ArrayList<>();

    for (int i = 0; i < line.length; i++) {
      for (int j = i + 1; j < line.length; j++) {
        double under = (line[i][0]*line[j][1] - line[i][1]*line[j][0]);
        if (under != 0) // (같은 직선 혹은 평행)이 아닐 때
          isInteger(findIntersection(line[i], line[j], under), x, y);
      }
    }

    // [0] -> min-x, [1]-> max-x, [2]-> min-y, [3]-> max-y
    int[] minmax = new int[4];
    findMinMax(minmax, x, y);
    drawPaper(x, y, ans, minmax);

    String[] answer = ans.toArray(new String[ans.size()]);
    int xp, yp;
    for (int i = 0; i < x.size(); i++) {
      xp = x.get(i) - minmax[0];
      yp = minmax[3] - y.get(i);

      answer[yp]= answer[yp].substring(0, xp) + "*" + answer[yp].substring(xp + 1);
    }


//    debug
    for (int i = 0; i < ans.size(); i++) {
      System.out.println(answer[i]);
    }

    return answer;
  }

  public static void main(String[] args) {

    int[][] line ={{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}};
    solution(line);
//    System.out.println("solution : " + solution(line));
  }
}
