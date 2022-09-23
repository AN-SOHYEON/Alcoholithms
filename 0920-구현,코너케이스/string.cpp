#include <iostream>
#include <string>

using namespace	std;

int	main () {

	string a, b;
	a = "4242";
	b = "3333";
	string c = "01:12";

	b = a.back() + b;
	
	
	cout << "a : " << a << "\n";
	int i = stoi(c);
	cout << "b : " << b << "\n";
	
	c = c.substr(3, 2);

	cout << "b : " << b << "\n";
	int j = stoi(c);

	cout << "i : " << i << "\n";
	cout << "j : " << j << "\n";

	return (0);
}