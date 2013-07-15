#include <cstddef>
#include <iostream>
#include <stdlib.h> //abs
#include <algorithm> //max

using namespace std;
/* Cracking the Coding Interview
*	4.1 Implement a function to check if a binary tree is balanced. A balanced tree is defined to be
*	a tree such that the heights of the two subtrees of any node never differ by more than one.
*
*	What I Learned:
*		Always initialize pointers, even must explicitly initialize to NULL
*		Use (ptr == NULL) to check if pointer is NULL; (!ptr) sometimes gives strange behavior
*		I initially didn't use the given definition- just checked if a given node had 2+ levels on one side vs none on the other
*			This wouldn't have worked with this example- overall left subtree had height 8, overall right subtree had height 6
*			Therefore, while it is helpful to use a simple case to figure out a solution; I still need to keep the overall picture in mind
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

void generateGraph(node* root, int height)
{
	if(height != 0)
	{
		root->left = new node(height);
		root->right = new node(height);
		generateGraph(root->left, height-1);
		generateGraph(root->right, height-1);
	}
}

void printGraph(node* root)
{
	if(root == NULL)
		return;
	cout << root->data << endl;
	printGraph(root->left);
	printGraph(root->right);
}

// balHeight checks for heights of subtress while checking if they're balanced
// if subtrees are not balanced, return -1
int balHeight(node* n){
	if(n == NULL)
		return 0;
	int leftH = balHeight(n->left);
	int rightH = balHeight(n->right);
	if(leftH < 0 || rightH < 0) //some lower subtree is imbalanced, entire tree is imbalanced
		return -1;
	if(abs(leftH - rightH) > 1) //if current subtree is imbalanced
		return -1;
	return 1 + max(leftH, rightH);	
}

bool isBalanced(node* n){
	if(balHeight(n) < 0)
		return false;
	return true;
}
int main()
{
	node* root = new node(3);
	generateGraph(root, root->data - 1);
	
	//printGraph(root);
	// Add some more nodes to leftmost graph to check unbalanced
	node* it = root;
	while(it->left != NULL){
		it = it->left; 
	}
	it->left = new node(0);
	it->left->left = new node(-1);
	
	//cout << "***" << endl;
	//printGraph(root);
	bool ret = isBalanced(root);
	if(!ret)
		cout << "Not Balanced" << endl;
	else
		cout << "Balanced" << endl;
	return 0;
}