/*
필수 문제

들어가 있는 원소를 다양한 위치에서 삽입, 삭제하는 문제이므로 list를 쓰면 성능이 좋을 것 같다. 
-> 메모리 초과난다. 

힌트에서 커서의 왼쪽/오른쪽을 나눠서 생각하라고 했으므로 커서의 왼쪽과 오른쪽을 따로 저장하는 방식으로 생각한다. 
이때 왼쪽은 push_front가 필요하고 오른쪽은 push_front가 필요하므로 deque를 쓸까 string 변수를 쓸까 고민했는데 
deque를 쓰면 마지막에 출력할때 반복문을 통해 한글자씩 출력해야할것 같아서 string으로 선택했다.
-> 시간초과난다. 

deque을 쓰자ㅏ...하하하하하ㅏㅎ
*/


#include <iostream>
#include <string>

using namespace	std;

void	leftKey(string &cur_left, string &cur_right) {
	
	if (cur_left.back()) {
		cur_right = cur_left.back() + cur_right;
		cur_left.pop_back();
	}
}

void	rightKey(string &cur_left, string &cur_right) {
	if (cur_right.front()) {
		cur_left += cur_right.front();
		cur_right.erase(0, 1);
	}
}

void	backSpace(string &cur_left, string &cur_right) {
	if (cur_left.back()) {
		cur_left.pop_back();
	}
}

void	charactor(string &cur_left, char c) {
	
	cur_left += c;
}

string	keyLogger(string input) {

	string	cur_left, cur_right;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '<')
			leftKey(cur_left, cur_right);
		else if (input[i] == '>')
			rightKey(cur_left, cur_right);
		else if (input[i] == '-')
			backSpace(cur_left, cur_right);
		else
			charactor(cur_left, input[i]);
	}
	return (cur_left + cur_right);
}

int	main () {

	int test;
	cin >> test;

	string	input;
	while (test--) {
		cin >> input;
		cout << keyLogger(input) << "\n";
	}

	return 0;
}