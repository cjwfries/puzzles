#include <cstddef>
#include <iostream>

using namespace std;


/* 7/27/13 Cracking the Coding Interview
* 1.2 Reverse a null-terminated string
*/

void reverse(char* str)
{
	if(str == NULL)
		return;
	char * beg = str;
	char * end = str;
	int length = 1; //actually, don't need a length variable- just check if end < beg
	while(*(end+1) != '\0')
	{
		end++; 
		length++;
	}
	for(int i = 0 ; i < length / 2 ; i++)
	{
		char tmp = *beg;
		*beg = *end;
		*end = tmp;
		beg++;
		end--;
	}
}

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cerr << "Usage: " << argv[0] << "STRING" << endl;
		return 1;
	}
	reverse(argv[1]);
	cout << argv[1] << endl;
}