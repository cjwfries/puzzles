#include <cstddef>
#include <iostream>
#include <climits>

using namespace std;

/* 7/20/13 Cracking the Coding Interview
* 4.5 Implement a function to check if a binary tree is a binary search tree.
*
* Algorithm:
* The definition of a BST is where all nodes left of root < root < all nodes right of root.
* Therefore we can think of each node having an acceptable min and max value.
*/

class treeNode
{
	public:
		int data;
		int max;
		int min;
		treeNode* left;
		treeNode* right;
		treeNode(int x){
			data = x;
			max = -1;
			min = -1;
			left = NULL;
			right = NULL;
		}	
};


bool isBST(treeNode * n, int min, int max)
{
	if(n == NULL)
		return true;
	if(n->data < min || n->data > max)
		return false;
	return isBST(n->left, min, n->data) && 
		isBST(n->right, n->data, max);
}

int main()
{
	treeNode* root = new treeNode(6);
	root->left = new treeNode(4);
	root->left->right = new treeNode(7);
	cout << isBST(root, INT_MIN, INT_MAX) << endl;
	return 1;
}