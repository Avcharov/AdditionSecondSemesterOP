#pragma once
#include <vector>
#include <string>

using namespace std;

vector<double> get_vars(string line, char sep) {
	vector<double> words;
	string temp_number = "";
	line += sep;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == sep) {
			if (temp_number.length() > 0) {
				words.push_back(stod(temp_number));
			}
			temp_number = "";
		}
		else {
			temp_number += line[i];
		}
	}
	return words;
}