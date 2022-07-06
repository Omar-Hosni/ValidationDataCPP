#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
	string instructions[3] = {
		"Do Not Swim",
		"Do Not Eat",
		"Stay Quiet",
	};

	int n = sizeof(instructions) / sizeof(instructions[0]);

	vector<string> lowerCase;

	for (string s : instructions) {
		transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {return tolower(c);});
		lowerCase.push_back(s);
	}


	vector<map<char, int>> validationData;

	for (int i = 0; i < n; i++) {
		validationData.resize(lowerCase[i].length());
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
			for (string s : lowerCase) {
				while (count < lowerCase[i].size()) {
					validationData[i][s[count]]++;
					count++;
				}
				i++;
				count = 0;
			}
			count = 0;
	}

	for (auto& n : validationData[0]) {
		cout << n.first << " " << n.second << endl;
	}


	string new_input;
	cout << "Input an instruction: ";
	getline(cin, new_input);

	unordered_map<char, int> newInputMap;

	for(char c: new_input){
		newInputMap[c]++;
	}

	for (auto n : newInputMap) {
		cout << n.first << " " << n.second << endl;
	}




}
