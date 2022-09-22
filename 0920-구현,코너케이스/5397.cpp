/*
필수 문제

들어가 있는 원소를 다양한 위치에서 삽입, 삭제하는 문제이므로 list를 쓰면 성능이 좋을 것 같다. 
*/

#include <iostream>
#include <string>
#include <list>

using namespace	std;

void	leftKey(list<char> &input, list<char>::iterator &cur) {
	if (cur != input.begin()) {
		cur--;
	}
}

void	rightKey(list<char> &input, list<char>::iterator &cur) {
	if (cur != input.end()) {
		cur++;
	}
}

void	backSpace(list<char> &input, list<char>::iterator &cur) {
	if (cur != input.begin()) {
		input.erase(--cur);
	}
}

void	charactor(list<char> &input, list<char>::iterator &cur, char c) {
	
	list<char>::iterator tmp(cur);
	if (*(++tmp)) {
		cur = input.insert(cur, c);
		cur++;
		// cout << "hi\n";
	}
	else {
		input.push_back(c);
		// cout << c << "\n";
	}
}

string	keyLogger(string input) {

	list <char> key;
	auto cursor = key.begin();
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '<')
			leftKey(key, cursor);
		else if (input[i] == '>')
			rightKey(key, cursor);
		else if (input[i] == '-')
			backSpace(key, cursor);
		else
			charactor(key, cursor, input[i]);
	}

	string	key_str;
	for (cursor = key.begin(); cursor != key.end(); cursor++) {
		key_str += *cursor;
	}
	return (key_str);
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