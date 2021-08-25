//https://www.acmicpc.net/problem/12865

//XXX

#include <iostream>
using namespace std;
int dp[103][100010];	//dp[A][B] A번째 물건을 탐색, B칸에 가방속 물건의 무게, 인덱스 B-가능한 최대 무게
int w[103];
int v[103];
int main(){
	int n, k, ans=0;
	cin >> n >> k;
	for(int i=0; i<n; i++){
		scanf("%d %d", &w[i], &v[i]);   // 무게와 가치 저장
	}
	for(int i=0; i<n; i++){   // 순서대로 물건을 탐색 (i번째 물건을 통해서 가방 무게 j만들기)
		for(int j=1; j<=k; j++){   // 2-1번. 가능한 최대 무게 K까지 루프
			if(i==0){
				if(j-w[0] >= 0)	dp[0][j] = v[0];  // 가능한 최대 무게보다 현재 탐색 중인 물건 무게가 작을 때 집어넣는다.
				continue;
			} 
			if(j-w[i] >= 0){   // 지금 탐색 중인 물건의 무게가 가방의 무게보다는 크거나 같아야 넣던지 말던지 할 수 있다.
				dp[i][j] = max(dp[i-1][j-w[i]]+v[i], dp[i-1][j]);
				// 전자는 기존에 탐색했던 물건들로만 j - Weight[i]를 만들고 탐색중인 물건을 가방에 넣기
				// 후자는 기존에 탐색했던 물건들로만 무게 j를 만드는 경우
			}
			else	dp[i][j] = dp[i-1][j];	// 아니면 A번째 물건을 담지 못하는  경우
		}
		ans = max(ans, dp[i][k]);   // 2-2번 최대무게 갱신
	}
	cout << ans << "\n";    // 3번
	return 0;
}