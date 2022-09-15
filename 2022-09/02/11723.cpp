// 0906-필수문제1 - 추가제출 >> 시간초과
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace	std;

void	myAdd(set<int> &s, int num) {
	s.insert(num);
}

void	myRemove(set<int> &s, int num) {
	s.erase(num);
}

void	myCheck(set<int> &s, int num) {
	if (s.find(num) == s.end()) 
		cout << 0 << "\n";
	else
		cout << 1 << "\n";
}

void	myToggle(set<int> &s, int num) {
	if (s.find(num) == s.end()) 
		s.insert(num);
	else
		s.erase(num);
}

void	myAll(set<int> &s) {
	for (int i = 0; i < 20; i++) {
		if (s.find(i + 1) == s.end()) {
			s.insert(i + 1);
		}
	}
}

void	myEmpty(set<int> &s) {
	s.clear();
}

void	menu(set<int> &s, string cmd) {

	int num;
	if (cmd == "add") {
		cin >> num;
		myAdd(s, num);
	} else if (cmd == "remove") {
		cin >> num;
		myRemove(s, num);
	} else if (cmd == "check") {
		cin >> num;
		myCheck(s, num);
	} else if (cmd == "toggle") {
		cin >> num;
		myToggle(s, num);
	} else if (cmd == "all") {
		myAll(s);
	} else if (cmd == "empty") {
		myEmpty(s);
	}

}

int	main () {
	
	int n;
	cin >> n;

	set <int> s;
	string	cmd;
	while (--n > -1) {
		cin >> cmd;
		menu(s, cmd);
	}
	return 0;
}
