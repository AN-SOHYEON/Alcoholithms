package level1;

class Solution {

  public int solution(int[][] sizes) {
    for (int i = 0; i < sizes.length; i++) {
      if (sizes[i][0] < sizes[i][1]) {
        int tmp = sizes[i][0];
        sizes[i][0] = sizes[i][1];
        sizes[i][1] = tmp;
      }
    }

    int weight = sizes[0][0];
    int height = sizes[0][1];
    for (int i = 1; i < sizes.length; i++) {
      if (weight < sizes[i][0]) {
        weight = sizes[i][0];
      }
      if (height < sizes[i][1]) {
        height = sizes[i][1];
      }
    }
    System.out.println(weight * height);
    return weight * height;
  }
}