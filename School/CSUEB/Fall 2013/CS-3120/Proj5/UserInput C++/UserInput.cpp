//
//  UserInput.cpp
//  Gamegame
//
//  Created by Nicholas Rebhun on 11/12/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#include "UserInput.h"

string UserInput::GetString(){
	string theStr;
	cout << "> ";
	getline(cin, theStr);
	return theStr;
}

int UserInput::GetInt() {
	int i;
	string theIntStr = GetString();
	stringstream convert(theIntStr);
	convert >> i;
	return i;
}

char UserInput::GetChar() {
	string tempStr = GetString();
	return tempStr[0];
}

double UserInput::GetDouble() {
	string doubStr = GetString();
	return atof(doubStr.c_str()	);
}

bool UserInput::GetConfirmation() {
	cout << " (y/n): ";
	char theChar = GetChar();
	while (theChar != 'y' && theChar != 'n') {
		cout << "Uh-oh! Input must be either 'y' or 'n'.\nTry Again." << endl;
		theChar = GetChar();
	}
	if (theChar == 'y') {
		return 1;
	}
	else if (theChar == 'n') {
		return 0;
	}
}

string UserInput::GetString(int min, int max) {
	string theString = GetString();
	while (theString.length() < min || theString.length() > max) {
		cout << "Uh-oh! You entered: " << theString << ", which is " << theString.length() << "characters in length.\nInput must be between " << min << " and " << max << " characters.\nTry again." << endl;
		theString = GetString();
	}
	return theString;
}

int UserInput::GetInt(int min, int max) {
	int theInt = GetInt();
	while ((theInt <= min) && (theInt >= max)) {
		cout << "Uh-oh! Input must be between " << min << " and " << max << ".\nTry again." << endl;
		theInt = GetInt();
	}
	return theInt;
}

char UserInput::GetChar(char min, char max) {
	char theChar = GetChar();
	while (theChar < min || theChar > max) {
		cout << "Uh-oh! Input must be between " << min << " and " << max << ".\nTry again." << endl;
		theChar = GetChar();
	}
	return theChar;
}