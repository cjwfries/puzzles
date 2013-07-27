#include <cstddef>
#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>

using namespace std;

/* 7/27/13 Cracking the Coding Interview
* 9.1 A child is running up a staircase with n steps and can hop either 1 steps,
* 2 steps, or 3 steps at a time. Implement a method to count how many possible ways
* the child can run up the stairs.
*
* Algorithm:
* This is a top-down approach.
*	For the very last step, she can do 1 3-hop, 1 2-hop, or 1 1-hop.
*	So we look at different subsets of stairs- (n-1), (n-2), and (n-3)- and we recursively look at the same subsets of those
*	More intuitively, we're counting the number of ways to reach each subset, and to do that, we count the number of ways to reach each subset of those subsets
*/

int numWays(int n)
{
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	if(n == 3)
		return 4;
	return numWays(n-1) + numWays(n-2) + numWays(n-3);
}

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		cerr << "Usage: " << argv[0] << " INT" << endl;
		return 1;
	}
	cout << numWays(atoi(argv[1])) << endl;
}