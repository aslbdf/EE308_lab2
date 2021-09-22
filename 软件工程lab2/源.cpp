#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
/*
author      why
MU  number  19104723
FZU number  831901330
environment vitual studio 2019
*/


int main() {
	string keyword_set[32] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
							  "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
								"return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union",
								"unsigned", "void", "volatile", "while" };
	string name;
	ifstream cpp_file;
	vector<string>keywords;
	int keywords_length = 0;
	string code_line = "";
	cout << "please enter your file position and name: ";
	getline(cin, name);
	cpp_file.open(name);

	int keywords_num = 0;
	while (!cpp_file.eof()) {
		getline(cpp_file, code_line);
		int keychar_i = 0;
		while (keychar_i < code_line.length()) {
			if (!((code_line[keychar_i] >= 'a' && code_line[keychar_i] <= 'z') ||
				(code_line[keychar_i] >= 'A' && code_line[keychar_i] <= 'Z') ||
				code_line[keychar_i] == '.' || code_line[keychar_i] == '_' ||
				code_line[keychar_i] == '{' || code_line[keychar_i] == '}' || code_line[keychar_i] == '\"')) {
				code_line[keychar_i] = ' ';
			}
			else if (code_line[keychar_i] == '{') {
				code_line.insert(long long int(keychar_i) + 1, " ");
				code_line.insert(long long int(keychar_i) - 1, " ");
				keychar_i++;
			}
			keychar_i++;
		}


		code_line.append(" ; ");
		istringstream keyword_input(code_line);
		string word;
		string word2;
		while (keyword_input >> word) {
			for (int i = 0; i < 32; i++) {
				if (keyword_set[i] == word) {
					keywords_num++;
				}
			}
			word2 = "";
			if (word == "else") {
				keyword_input >> word2;
				for (int i = 0; i < 32; i++) {
					if (keyword_set[i] == word2) {
						keywords_num++;
					}
				}
				if (word2 == "if") {
					word = word + word2;
					keywords.push_back(word);
					keywords_length++;
				}
				else {
					keywords.push_back(word);
					keywords.push_back(word2);
					keywords_length++;
					keywords_length++;
				}
			}
			else {
				keywords.push_back(word);
				keywords_length++;
			}
		}
	}


	int keyword_i = 0;
	while (keyword_i < keywords_length) {
		if (keywords[keyword_i] == "int" || keywords[keyword_i] == "double" ||
			keywords[keyword_i] == "long" || keywords[keyword_i] == "float" ||
			keywords[keyword_i] == "short" || keywords[keyword_i] == "unsigned" ||
			keywords[keyword_i] == "char") {
			keyword_i++;
			while (keywords[keyword_i] != ";") {
				string del_word = keywords[keyword_i];
				if (del_word == "main" || del_word == "{") {
					keyword_i++;
					continue;
				}
				int del_i = 0;
				while (del_i < keywords_length) {
					if (keywords[del_i] == del_word) {
						keywords.erase(begin(keywords) + del_i);
						keywords_length--;
					}
					else {
						del_i++;
					}
				}
			}
		}
		keyword_i++;
	}



	int del_i = 0;
	while (del_i < keywords_length) {
		if (keywords[del_i] == ";") {
			keywords.erase(begin(keywords) + del_i);
			keywords_length--;
		}
		else {
			del_i++;
		}
	}


	int num_floor = -1;
	vector<int>switch_floor;
	int case_length = 0;
	int switch_num = 0;
	int if_else_num = 0;
	vector<int>if_floor;
	int if_elseif_num = 0;
	vector<int>case_num_vector;
	keyword_i = 0;
	while (keyword_i < keywords_length) {
		if (keywords[keyword_i] == "{") {
			num_floor++;
			switch_floor.push_back(0);
			if_floor.push_back(0);
		}
		else if (keywords[keyword_i] == "}") {
			if (switch_floor[num_floor] != 0) {
				case_num_vector.push_back(switch_floor[num_floor]);
				case_length++;
			}

			if (if_floor[num_floor] == -1) {
				if_elseif_num++;
			}

			if (if_floor[num_floor] == 1) {
				if_else_num++;
			}
			switch_floor.erase(begin(switch_floor) + num_floor);
			if_floor.erase(begin(if_floor) + num_floor);
			num_floor--;
		}
		else if (keywords[keyword_i] == "switch") {
			switch_num++;
		}
		else if (keywords[keyword_i] == "case") {
			switch_floor[num_floor]++;
		}
		else if (keywords[keyword_i] == "elseif") {
			if_floor[num_floor] = -1;
		}
		else if (keywords[keyword_i] == "else") {
			if (if_floor[num_floor] == 0) {
				if_floor[num_floor] = 1;
			}
		}

		keyword_i++;
	}


	cout << "keywords_num is " << keywords_num;
	cout << "\nswitch num: " << switch_num << "\ncase num: ";
	for (int n = 0; n < case_length; n++) {
		cout << case_num_vector[n] << " ";
	}
	cout << "\nif else num:" << if_else_num;
	cout << "\nif elseif num: " << if_elseif_num;
	cpp_file.close();
	return 0;
}
