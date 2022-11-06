/*
10. 그리디 알고리즘 - 필수
*/

#include <iostream>
#include <string>

using namespace	std;

char	isType(string word) {
	char	type = 'C';
	for (auto it = word.begin(); it != word.end(); it++) {
		if (*it == '_') {
			break ;
		} else if (*it >= 'A' && *it <= 'Z') {
			type = 'J';
			break ;
		} else if (*it >= 'a' && *it <= 'z') {
			continue;
		} else {
			type = 'N';
			break;
		}
	}
	return type;
}

string javaToCpp(string word) {

	string word_res;
	int size = word.size();
	for (int i = 0; i < size; i++) {
		cout << word[i] << "\n";
		if (word[i] >= 'A' && word[i] <= 'Z') {
			word_res.push_back('_');
			word_res.push_back(word[i] + 32);
		} else {
			word_res.push_back(word[i]);
		}
	}
	return word_res;
}

string cppToJava(string word) {
	
	string word_res;
	int size = word.size();
	for (int i = 0; i < size; i++) {
		if (word[i] == '_') {
			i++;
			word_res.push_back(word[i] - 32);
		} else {
			word_res.push_back(word[i]);
		}
	}
	return word_res;	
}

string	translate(string word) {

	if (isType(word) == 'J') {
		return javaToCpp(word);
	} else if (isType(word) == 'C') {
		return cppToJava(word);
	} else {
		return "Error!";
	}
}

int main () {
	
	string word;
	cin >> word;
	cout << translate(word);
	return 0;
}