#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int a[10001];
	int N, K;
	int count = 0;
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		a[i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; i * j <= N; j++) {
			if (a[i * j] == 1) {
				a[i * j] = 0;
				count++;

				if (count == K) {
					cout << i * j << endl;
					return 0;
				}

			}
		}

	}
}