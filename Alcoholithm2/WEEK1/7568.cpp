#include <iostream>
#include <cmath>
#include <cstdlib>

int main()
{
    int num;
    std::cin >> num;
    int **info;
    info = new int*[2];
    for (int i = 0; i < num; i++)
        info[i] = new int[2];
    int *rank = new int[num];
    
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
    
    for (int i = 0; i < num; i++)
        delete[] info[i];
    delete[] info;
    delete[] rank;
    return 0;
}
