#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace	std;

typedef	pair<int, int> _time;

int calcClassRoom(int n, vector<_time> &lesson_time) {
	
	vector<int> class_end_time;
	int classroom = 0;
	class_end_time.push_back(lesson_time[0].first);
	classroom++;

	bool is_new_class = true;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < classroom; j++) {
			if (lesson_time[i].second >= class_end_time[j]) {
				class_end_time[j] = lesson_time[i].first;
				is_new_class = false;
				break;
			}
		}
		if (is_new_class == true) {
			classroom++;
			class_end_time.push_back(lesson_time[i].first);
			
		} else 
			is_new_class = true;
		sort(class_end_time.begin(), class_end_time.end());
	}
	return classroom;
}

int main () {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n;
	cin >> n;

	vector<_time> lesson_time(n);
	for (int i = 0; i < n; i++) {
		cin >> lesson_time[i].second >> lesson_time[i].first;
	}

	sort(lesson_time.begin(), lesson_time.end());
	cout << calcClassRoom(n, lesson_time) << "\n";

	return 0;
}


/* https://kuck-su-labor.tistory.com/59 참고

*/