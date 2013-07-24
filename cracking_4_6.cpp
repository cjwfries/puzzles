#include <cstddef>
#include <iostream>
#include <climits>

using namespace std;

/* 7/23/13 Cracking the Coding Interview
* 4.6 Write an algorithm to find the next node (in-order) in a BST.
*/

class treeNode
{
	public:
		int data;
		int max;
		int min;
		treeNode* left;
		treeNode* right;
		treeNode* parent;
		treeNode(int x){
			data = x;
			max = -1;
			min = -1;
			left = NULL;
			right = NULL;
			parent = NULL;
		}	
};


treeNode* nextNode(treeNode* n)
{
	if(n->parent != NULL) 
	{
		if(n->parent->left == n)
		{
			return n->parent; //left nodes
		}
		if(n->parent->right == n)
		{
			treeNode* ptr = n->parent;
			do
			{
				ptr = ptr->parent;
			}while(ptr != NULL && ptr->parent != NULL && ptr != ptr->parent->left);
			return ptr;
		}
	}
	if(n->left != NULL) //middle nodes
	{
		if(n->right == NULL)
			return NULL;
		treeNode* ptr = n->right;
		while(ptr->left != NULL)
		{
			ptr = ptr->left;
		}
		return ptr;
	}
}

int main()
{
	treeNode* root = new treeNode(4);
	root->left = new treeNode(2);
	root->left->parent = root;
	root->left->left = new treeNode(1);
	root->left->left->parent = root->left;

	
	treeNode * result = nextNode(root->left);
	cout << result->data << endl;
	return 1;
}