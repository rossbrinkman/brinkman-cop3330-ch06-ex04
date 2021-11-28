#include "main.h"

void Terminate(string exitMessage)
{
	cout << "\nCurrent names: \n";
	if (nameVals.size() != 0)
	{
		for (int i = 0; (unsigned)i < nameVals.size(); i++)
		{
			cout << nameVals[i].Name << " " << nameVals[i].Value << "\n";
		}
	}
	cout << "\nTerminated: " << exitMessage;
	exit(0);
}

void CheckSize(vector<string> elements)
{
	if (elements.size() != 2)
	{
		Terminate("Incorrect count. Please enter in the following format: \"name value\"");
	}
}

int TryToConvert(vector<string> elements, int index)
{
	int num = 0;
	string el;
	if (elements.size() >= index+1)
	{
		try { num = stoi(elements[index]); }
		catch (exception)
		{
			Terminate("Incorrect value. Please enter in the following format: \"name value\"");
		}
	}
	else
		Terminate("Index outside bounds of array.");
	return num;
}

void SplitString(string str, vector<string>& vec) {

	string temp = "";
	for (int i = 0; (unsigned)i < str.length(); ++i) {

		if (str[i] == ' ') {
			vec.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(str[i]);
		}

	}
	vec.push_back(temp);
}

void CheckIfNameExists(string name)
{
	for (Name_value n : nameVals)
	{
		if (n.Name == name)
			Terminate("Name cannot be entered twice.");
	}
}

int main()
{
	string input;
	double rootExists;

	while (true)
	{
		getline(cin, input);
		SplitString(input, elements);
		CheckSize(elements);
		CheckIfNameExists(elements[0]);
		Name_value temp = Name_value(elements[0], TryToConvert(elements, 1));
		nameVals.push_back(temp);
		elements.clear();
	}
}