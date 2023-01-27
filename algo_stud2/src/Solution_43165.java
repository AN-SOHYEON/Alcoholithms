public class Solution_43165 {

    int count = 0;
    public int solution(int[] numbers, int target) {
      int answer = 0;
      dfs(numbers, 0, target, 0);
      answer = this.count;

      return answer;
    }

    public void dfs(int[] numbers, int depth, int target, int result){
      if (depth == numbers.length){  // 마지막 노드까지 탐색한 경우
        if (target == result){
          this.count++;
        }
        return;
      }

      int add = result + numbers[depth];
      int sub = result - numbers[depth];

      // 해당 노드의 값을 더하고 다음 깊이 탐색
      dfs(numbers, depth+1, target, add);
      // 해당 노드의 값을 뺴고 다음 깊이 탐색
      dfs(numbers, depth+1, target, sub);

    }
}
