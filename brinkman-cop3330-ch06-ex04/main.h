#pragma once

/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Ross Brinkman
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Name_value
{
	public:
		string Name = "";
		int Value = NULL;

		Name_value(string name, int value)
		{
			Name = name;
			Value = value;
		}
};

vector<string> elements;
vector<Name_value> nameVals;
