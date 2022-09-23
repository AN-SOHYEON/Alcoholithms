#include <iostream>
#include <string>

using namespace	std;

int	main () {

	string a, b;
	a = "4242";
	b = "3333";
	
	b = a.back() + b;

	cout << "a : " << a << "\n";
	cout << "b : " << b << "\n";

	return (0);
}