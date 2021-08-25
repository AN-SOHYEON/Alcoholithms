#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	int	N, C;
	int	num;

	cin >> N >> C;
	vector<int> house (N,0);

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		house.push_back(num);
	}
	sort(house.begin(), house.end());

    int left = house.front();
    int right = house.back();
    int answer_num = 0;

    while (left <= right) 
    {
        int mid = (left + right) / 2;
        int before_wifi = 0;
        int set_wifi = 1;
        
        for (int i = 1; i < N; i++) 
        {
            // 현재 위치와 직전 설치한 공유기의 위치의 간격이 mid 보다 크다면
            if (house.at(i) - house.at(before_wifi) >= mid) 
            {
                before_wifi = i;
                set_wifi++;
            }
        }

        if (set_wifi > C) 
        {
            left = mid + 1;
        }
        else if (set_wifi == C)
        {
            answer_num = mid;
            break;
        }
        else 
            right = mid - 1;
    }

    cout << answer_num;

    return 0;
}

