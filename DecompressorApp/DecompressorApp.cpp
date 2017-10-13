// DecompressorApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>

//std::map <string, char> grade_list;

using namespace std;

/*
A function which takes a string s and returns a string which contains s n-times
*/
string repeatString(string s, int n) {
	string repeatedString = s;
	for (int i=0; i < n-1; i++) {
		repeatedString = repeatedString + s;
	}
	return repeatedString;
}

/*
A function which begins consuming chars from the end of the stack once no more
alterations are possible (when a ] bracket is obtained
*/
string processNumber(vector<char> &vStack) {
	string number = "";
	string back;
	char c = vStack.back();
	while (c) {
		if ( vStack.empty() || c == ']') {
			break;
		}else {
			number = number + c;
			vStack.pop_back();
		}
	}
	return number;
}
/*
	A function which begins consuming chars from the end of the stack once no more
	alterations are possible (when a ] bracket is obtained
*/
string processSubString(vector<char>* vStack) {
	string subString = "";
	char c = vStack->back();
	vStack->pop_back();
	while (c){
		if (c == '[') {
			return subString;
		}
		else {
			subString.insert(0, c);
		}
	}
}

/*
	A simple parsing function which opens a file and processes each line char-by-char
	Since this is a simple project, I could have used getline, but I wanted to test
	writing a program which could handle a series of queries on a single line without
	copying the entire file contents to a buffer.
*/

void parse(string s) {
	ifstream inputFile(s);						// Default Constructor for read only File Stream
	vector<char> vStack;						// Used to handle left hand associativity of operations
	vector<char>* vStack_ptr = &vStack;
	if (inputFile.is_open()) {					// Make sure file successfully opened
		cout << "Reading from file..." << endl;
		char c;
		while (inputFile.get(c)) {				// Begin processing the input
			vStack.pop_back();
			cout << c;
			//We will define our query delimiter ahead, standard case is a space
			if (c == ',') {
				cout << endl;
				continue;
			}else if (c == '[') {				// Begin parsing a number
				
			}else if (c == ']') {				// Begin parsing a substring
				processSubString(vStack_ptr);
			}else {

			}
		}
		inputFile.close();
	
	}else cout << "Unable to open file";
}

int main()
{
	//parse("../test_input.txt");
	string s = "Test";
	s = repeatString(s,3);
	cout << "Reading from file..." << endl;

	cout << s << endl;
	return 0;
}

