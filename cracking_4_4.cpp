#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

#define MID length/2

/* 7/20/13 Cracking the Coding Interview
* 4.4 Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depth.
*/

class LLnode
{
	public:
		LLnode(int x)
		{
			data = x;
			next = NULL;
		}
		LLnode* next;
		int data;

};

class treeNode
{
	public:
		int data;
		treeNode* left;
		treeNode* right;
		treeNode(int x){
			data = x;
			left = NULL;
			right = NULL;
		}	
};

void graphLevel(treeNode* n, int level, vector<LLnode*> * v)
{
	if(n == NULL)
		return;
	if(v->size() <= level)
		v->push_back(new LLnode(n->data));
	else{
		LLnode* ptr = (*v)[level];
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new LLnode(n->data);
	}
	level++;
	graphLevel(n->left, level, v);
	graphLevel(n->right, level, v);
}

int main()
{
	int a[] = {0, 1, 2, 3};
	treeNode* n = new treeNode(0);
	n->left = new treeNode(11);
	n->right = new treeNode(12);
	n->left->left = new treeNode(21);
	n->left->right = new treeNode(22);
	n->right->left = new treeNode(23);
	vector<LLnode*> * v = new vector<LLnode*>();
	graphLevel(n, 0, v);
	for(int i = 0 ; i < v->size() ; i++)
	{
		LLnode* ptr = (*v)[i];
		cout << ptr->data << ", ";
		while(ptr->next != NULL)
		{
			cout << ptr->data << ", ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	delete v;
	return 1;
}