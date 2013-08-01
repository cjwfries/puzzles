#include <cstddef>
#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>

using namespace std;

/* 7/27/13 Cracking the Coding Interview
* 9.2 Imagine a robot sitting on the upper left corner of an X by Y grid.
* The robot can only move right and down. How many possible paths are there for the robot to go from (0,0)
* to(X,Y).
*/

int numPaths(int srcx, int srcy, int dstx, int dsty)
{
	if(srcx > dstx || srcy > dsty)
	{
		return 0;
	}
	if(srcx == dstx && srcy == dsty)
	{
		return 1;
	}
	int ret = numPaths(srcx + 1, srcy, dstx, dsty) +
		numPaths(srcx, srcy+1, dstx, dsty);
	return ret;
}

int main(int argc, char* argv[])
{
	if(argc < 5)
	{
		cerr << "Usage: " << argv[0] << "srcx srcy dstx dsty" << endl;
	}
	cout << numPaths(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])) << endl;
}