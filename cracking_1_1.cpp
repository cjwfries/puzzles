#include <cstddef>
#include <iostream>
#include <climits>
#include <string>

using namespace std;

#define ASCII_SET_SIZE 128

/* 7/27/13 Cracking the Coding Interview
* 1.1 Implement an algorithm to determine if a string has all unique characters.
* What if you can't use additional data structures?
*/

// No additional data structures
// O(N^2) time, O(1) space
bool isUnique(string str)
{
	if(str.length() == 0 || str.length() == 1)
		return true;
	if(str.length() > ASCII_SET_SIZE)
		return false;
	for(int i = 0 ; i < str.length() - 1 ; i++)
	{
		char tmp = str[i];
		for(int j = i+1 ; j < str.length() ; j++)
		{
			if(tmp == str[j])
			{
				return false;
			}
		}
	}
	return true;
}

// Using hash table
bool isUniqueHash(string str)
{
	if(str.length() == 0 || str.length() == 1)
		return true;
	if(str.length() > ASCII_SET_SIZE)
		return false;
	
	bool hashTable[ASCII_SET_SIZE] = {false};
	for(int i = 0 ; i < str.length() ; i++)
	{
		if(hashTable[str[i]] == true)
			return false;
		else
			hashTable[str[i]] = true;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Usage: " << argv[0] << "STRING" << endl;
	}
	cout << isUniqueHash(argv[1]) << endl;
}