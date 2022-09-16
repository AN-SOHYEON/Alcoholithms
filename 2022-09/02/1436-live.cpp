#include <iostream>

using namespace	std;

int	findEndNumber(int n) {

	int end_num = 666 - 1;
	int index = 0;

	while (true) {
		string str_end_num = to_string(++end_num);
		if (str_end_num.find("666") != str_end_num.npos) {
			index++;
		}
		if (index == n)
			break ;
	}
	return (end_num);
}

int	main () {

	int n;
	cin >> n;

	cout << findEndNumber(n);

	return 0;
}