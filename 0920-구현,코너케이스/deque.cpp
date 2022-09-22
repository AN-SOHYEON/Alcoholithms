#include <iostream>
#include <deque>

int main () {

	deque<int>hi(10);
	for (int i = 0; i < 10; i++) {
		hi[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) { 
		std::cout << hi[i] << " ";
	}

	
}