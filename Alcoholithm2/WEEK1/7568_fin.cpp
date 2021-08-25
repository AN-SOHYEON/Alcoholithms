#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
    int num;
    std::cin >> num;
    int info[51][2];
    int rank[51];
    
    for (int i = 0; i < num; i++)
    {
        std::cin >> info[i][0] >> info[i][1];
        rank[i] = 1;
    }
    
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (info[i][0] > info[j][0] && info[i][1] > info[j][1])
                rank[j]++;
            else if (info[i][0] < info[j][0] && info[i][1] < info[j][1])
                rank[i]++;
        }
    }
    
    for (int i = 0; i < num; i++)
        std::cout << rank[i] << " ";
    std::cout << '\n';
    
    return 0;
}
