#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
int main()
{
    
    int N,M;

    scanf("%d",&N);

    vector<int> want (N, 0);
    int high=0;

    for(int i=0;i<N;i++)
    {
        scanf("%d", &want[i]);    
        if(want[i] > high)
            high = want[i];
    }
    
    scanf("%d",&M);

    int sum = 0;
    int low = 0;
    int mid = (low + high) / 2;
    while (high >= low)
    {    
        sum = 0;
        for (int i=0; i<N; i++)
            sum += (want[i] > mid) ? mid : want[i];
        
        if (sum == M)
            break;
        
        if (sum > M) 
            high = mid - 1;
        else    
            low = mid + 1;
        
        mid = (low + high) / 2;
    }
    
    //low=n일 때 mid와 high는 n-1


    cout << mid << endl;
    
    return 0;
}
