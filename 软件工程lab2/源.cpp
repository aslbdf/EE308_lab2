#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
	string name;
	ifstream cpp_file;
	vector<string>keywords;
	int keywords_length = 0;
	string code_line = "";
	cout << "please enter your file position: ";
	//getline(cin, name);
	cpp_file.open("file.cpp");
	
	
	while (!cpp_file.eof()) {
		getline(cpp_file, code_line);
		int keychar_i = 0;
		while (keychar_i < code_line.length()) {
			if (!((code_line[keychar_i] >= 'a' && code_line[keychar_i] <= 'z') ||
				(code_line[keychar_i] >= 'A' && code_line[keychar_i] <= 'Z') ||
				code_line[keychar_i] == '.' || code_line[keychar_i] == '_'||
				code_line[keychar_i] == '{' || code_line[keychar_i] == '}')) {
				code_line[keychar_i] = ' ';
			}
			else if (code_line[keychar_i] == '{') {
				code_line.insert(keychar_i + 1, " ");
				code_line.insert(keychar_i - 1, " ");
				keychar_i++;
			}
			keychar_i++;
		}


		code_line.append(" ;");
		istringstream keyword_input(code_line);
		string word;
		string word2;
		while (keyword_input >> word) {
			word2 == "";
			if (word == "else") {
				keyword_input >> word2;
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
			keywords[keyword_i] == "long") {
			keyword_i++;
			while (keywords[keyword_i] != ";") {
				string del_word = keywords[keyword_i];
				if (del_word == "mai" || del_word == "{") {
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
		
	for (int n = 0; n < keywords_length; n++) {
		cout << keywords[n] << '\n';
	}


	int keywords_num = 0;
	keyword_i = 0;
	while (keyword_i < keywords_length) {
		if (keywords[keyword_i] != "{" && keywords[keyword_i] != "}") {
			keywords_num++;
		}
		keyword_i++;
	}
	cout << "keywords_num is " << keywords_num;
	return 0;
	
	int num_floor = 0;
	int switch_num = 0;
	int if_else_num = 0;
	int if_elseif_num = 0;
	int case_num = 0;
	vector<int>case_num_vector;
	keyword_i = 0;
	while (keyword_i < keywords_length) {
		if (keywords[keyword_i] == "{") {
			num_floor++;
		}
		else if (keywords[keyword_i] == "}") {
			num_floor--;
			case_num_vector.push_back(case_num);
			if(switch_num)
		}
		if (keywords[keyword_i] == "switch") {
			switch_num++;
		}
		if(keywords[keyword_i] =="case")
	}

}