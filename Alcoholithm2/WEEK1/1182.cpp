#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, sum;
vector<int> number;
int cnt = 0;

void comb(vector <int> number, vector <int> combin, int size, int index, int depth)
{
	int number_sum = 0;
	 if (size == 0)
    {
        for(int i = 0; i < combin.size(); i++)
            number_sum += combin[i];
    }
    else if (depth == number.size())
        return;
    else
    {
        combin[index] = number[depth];
        comb(number, combin, size - 1, index + 1, depth + 1); 
        comb(number, combin, size, index, depth + 1);
    }
}

int main() 
{
	
	cin >> N >> sum;

	for (int i = 0; i < N; i++) 
	{
		int num;
		cin >> num;
		number.push_back(num);
	}

	vector <int> combin;
	for (int i = 1; i < N + 1; i++)
	{
		comb(number, combin, i , 0 , 0);
		for (int k = 0; k < combin.size(); k++)
		{
			if (combin[k] == sum)
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}
