#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

#define MID length/2

/* 7/16/14 Cracking the Coding Interview
* 4.3 Given a sorted (in increasing order) array, write an algorithm to create
* a binary search tree with minimal height.
*
* What I learned:
* 	Test indices very carefully
*/

class node{
	public:
		int data;
		node* left;
		node* right;
		node(int x){
			data = x;
			left = NULL;
			right = NULL;
		}	
};


void createBST(int* a, int start, int fin, node* root)
{
	if(fin < start)
		return;
	if(fin - start == 0){
		if(a[0] <= root->data)
			root->left = new node(a[0]);
		else
			root->right = new node(a[0]);
		return;
	}
	int length = fin - start + 1;
	root->left = new node(a[start + MID/2]);
	root->right = new node(a[MID + (fin - MID)/2 + 1]); //check if out of bounds
	createBST(a, start, start + MID - 1, root->left);
	createBST(a, start + MID + 1, fin, root->right);
	
}

int main()
{
	int a[] = {0, 1, 2, 3};
	node* n = new node(a[(3+1)/2]);
	createBST(a, 0, 3, n);
	return 1;
}