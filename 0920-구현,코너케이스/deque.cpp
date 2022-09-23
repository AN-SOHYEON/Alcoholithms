#include <iostream>
#include <deque>


int main () {

	std::deque<char>hi;
	std::cout << "back : " << hi.back() << "\n";

	for (int i = 0; i < 10; i++) {
		hi[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) { 
		std::cout << hi[i] << " ";
	}
	std::cout << "\n";

	hi[7] = 10;

	// for (int i = 0; i < 11; i++) { 
	// 	std::cout << hi[i] << " ";
	// }

}