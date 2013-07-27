#include <cstddef>
#include <iostream>
#include <climits>
#include <string>

using namespace std;

#define ASCII_SET_SIZE 128

/* 7/27/13 Cracking the Coding Interview
* 1.3 Given 2 strings, decide if 1 is a permutation of the other
*/

bool isPermutation(string s1, string s2)
{
	if(s1.length() != s2.length())
		return false;
	if(s1.length() == 0)
		return true;
	int hashTable[ASCII_SET_SIZE] = {0};
	for(int i = 0 ; i < s1.length() ; i++)
	{
		hashTable[s1[i]]++;
		hashTable[s2[i]]--;
	}
	for(int i = 0 ; i < ASCII_SET_SIZE ; i++)
	{
		if(hashTable[i] != 0)
			return false;
	}
	return true;
}

int main(int argc, char * argv[])
{
	if(argc < 3)
	{
		cerr << "Usage: " << argv[0] << " STRING1 STRING2" << endl;
		return 1;
	}
	cout << isPermutation(argv[1], argv[2]) << endl;
}