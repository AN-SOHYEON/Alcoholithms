#include <iostream>

using namespace std;
// std(클래스)에 있는 함수들을 사용하겠다 라는 선언, (이름 공간에 있는 std에 정의되어있는 함수들을 사용하겠다.)
// std에는 cout, cin, endl등이 정의되어 있음

int     sumsum(int num)
{
    if(num == 1)
        return (1);
    return (num + sumsum(num - 1));
}

int     main()
{
    cout << "sum: " << sumsum(100) << endl;
}
