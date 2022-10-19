#include <iostream>
#include <vector>
#include <algorithm>

using namespace	std;

typedef	pair<int, int> _time;

int calcClassRoom(int n, vector<_time> &lesson_time) {
	cout << "wfd\n";
	vector<int> class_end_time;
	int classroom = 0;
	class_end_time.push_back(lesson_time[0].first);
	classroom++;
	for (int i = 1; i < n; i++) {
		cout <<"i : " << i << " \n";
		for (int j = 0; j < classroom; j++) {
			cout <<"classr" << " \n";
			if (lesson_time[i].second >= class_end_time[j]) {
				class_end_time[j] = lesson_time[i].first;
				break;
			}
			if (j == classroom - 1) {
				classroom++;
				class_end_time.push_back(lesson_time[i].first);
			}
		}
		sort(class_end_time.begin(), class_end_time.end());
	}
	return classroom;
}

int main () {

	int n;
	cin >> n;

	vector<_time> lesson_time(n);
	for (int i = 0; i < n; i++) {
		cin >> lesson_time[i].second >> lesson_time[i].first;
	}
	sort(lesson_time.begin(), lesson_time.end());
	cout << calcClassRoom(n, lesson_time);

	return 0;
}