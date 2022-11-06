#include <iostream>
#include <vector>

using namespace	std;

int main () {
	
	int n, k;
	cin >> n >> k;

	int count = 0;
	count += (n % k);
	n -= (count);
	while (n != 1) {
		n /= k;
		count++;
	}

	cout << count << "\n";
	return 0;
}