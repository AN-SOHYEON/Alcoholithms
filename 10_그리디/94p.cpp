#include <iostream>
#include <vector>

using namespace	std;

int timeToPlus(int n, int m, int k, vector<int> &number) {

	int sum = 0;
	int time = 0;
	for (int i = 0; i < m; i++) {
		if (time < k) {
			sum += number[n - 1];
			time++;
		} else if (time == k) {
			sum += number[n - 2];
			time = 0;
		}
		cout << sum << " <- sum | " << time << " <- time\n";
	}

	return sum;
}

int	main () {

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> number(n);
	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	sort(number.begin(), number.end());
	cout << timeToPlus(n , m , k, number) << "\n";

	return 0;
}