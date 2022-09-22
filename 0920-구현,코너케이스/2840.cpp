/*
필수 문제

변한 횟수만큼 시계반대방향으로 돌린 자리가 현재 화살표가 가리키는 알파벳의 돌리기 직전 위치이다. 
따라서 rotate에 용이한 deque를 사용해서 현 위치로부터 시계 반대방향으로 돌려가며 원판을 채운다. 

처음에 deque을 ?으로 채워서 나중에 못채웠을 때 자연스럽게 ?로 출력이 되도록 한다. 
시계반대방향으로 돌아가면서 이미 ?이 아닌 다른 문자가 채워져 있을 때 또 다른 문자의 위치라고 나오면 바로 ! 출력후 종료 
deque를 순회할 때 인덱스의 오름차순이 시계방향이도록 한다. (시계반대방향으로 해도 push, pop을 계속해야해서 이득이 없다.)
*/

#include <iostream>
#include <deque>
#include <stdio.h>

using namespace	std;

void	findLocation(deque <char> &lucky, int s, char ch) {
	while (s--) {
		lucky.push_front(lucky.back());
	}
}

int	main () {

	int n, k;
	cin >> n >> k;
	deque <char> lucky(n, ?);

	int s, 
	char ch;
	while (k--) {
		scanf("%d %c", s, ch);
		findLocation(lucky, s, ch);
	}

	return 0;
}


// 함수를 통해 전달하는 것보다 전역변수를 쓰는게 코드 실행에 있어서 더 좋은 점이 있는지 물어보기 