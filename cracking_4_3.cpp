#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

#define MID length/2

/* 7/16/13 Cracking the Coding Interview
* 4.3 Given a sorted (in increasing order) array, write an algorithm to create
* a binary search tree with minimal height.
*
* What I learned:
* 	Test indices very carefully
*/

class treeNode{
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


void createBST(int* a, int start, int fin, treeNode* root)
{
	if(fin < start || root == NULL)
		return;
	if(fin - start == 0){
		if(a[0] <= root->data)
			root->left = new treeNode(a[0]);
		else
			root->right = new treeNode(a[0]);
		return;
	}
	int length = fin - start + 1;
	int leftIdx = start + MID/2;
	int rightIdx = MID + (fin - MID)/2 + 1;
	if(leftIdx >= start and leftIdx <= fin)
	{
		root->left = new treeNode(a[leftIdx]);
	}
	if(rightIdx >= start and rightIdx <= fin)
	{
		root->right = new treeNode(a[rightIdx]);		
	}	
	createBST(a, start, start + MID - 1, root->left);
	createBST(a, start + MID + 1, fin, root->right);
}


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

void graphLevel(treeNode* n, int level, vector<LLnode*> * v)
{
	if(n == NULL)
		return;
	if(v->size() <= level){
		v->push_back(new LLnode(n->data));
	}
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
	treeNode* n = new treeNode(a[(3+1)/2]);
	createBST(a, 0, 3, n);
	
	cout << "***" << endl;
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