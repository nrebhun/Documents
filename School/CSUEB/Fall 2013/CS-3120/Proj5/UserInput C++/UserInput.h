//
//  UserInput.h
//  Gamegame
//
//  Created by Nicholas Rebhun on 11/12/13.
//  Copyright (c) 2013 Nicholas Rebhun. All rights reserved.
//

#ifndef __Gamegame__UserInput__
#define __Gamegame__UserInput__

#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class UserInput {

public:
	static string GetString(void);
	static int GetInt(void);
	static char GetChar(void);
	static double GetDouble(void);
	
	static bool GetConfirmation(void);
		// Overloaded, with params
	static string GetString(int, int);
	static int GetInt(int, int);
	static char GetChar(char, char);
	static double GetDouble(double, double);
};
#endif /* defined(__Gamegame__UserInput__) */
