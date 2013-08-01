#include <iostream>

using namespace std;

/* 7/31/13 Cracking the Coding Interview
* 9.3 Find index i where A[i] == i, given sorted array A.
*
* (Aside): If all elements in A were unique-
* Take an example where (1) A[i] < i
* Because they're unique, A[i-1] < A[i] -------> (2) A[i-1] <= A[i] - 1
* Which follows from (1) and (2) A[i-1] < i - 1
* Generalized- A[i-j] < i - j
* Therefore: if (1) A[i] < i, then the magic index cannot be on the left side
*
* Note: Practice binary search, keep track of indices- where they go out of bound, how to find the midpoint of a subarray.
*/

int magicIdx(int arr[], int start, int end, int length)
{
	if(end - start < 0 || start < 0 || end >= length)
	{
		return -1; //not found
	}
	int mid = start + (end - start) / 2;
	int mid_val = arr[mid];
	if(mid == mid_val)
		return mid;
	int left = magicIdx(arr, start, mid-1, length);
	if(left != -1)
		return left;
	int right = magicIdx(arr, mid+1, end, length);
	if(right != -1)
		return right;
	return -1;
	
}

int main()
{
	int arr[] = {1,2,4,4,4,6};
	cout << magicIdx(arr, 0, 5, 6) << endl;
}