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
*	Keep it simple- when using recursion try to return something rather than passing a pointer in the parameter
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


treeNode* createMinBST(int* a, int start, int fin)
{
	if(fin < start)
		return NULL;
	int mid = (fin - start) / 2 + start;
	treeNode* n = new treeNode(a[mid]);
	n->left = createMinBST(a, start, mid - 1);
	n->right = createMinBST(a, mid + 1 , fin);
	return n;
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
	treeNode* n = createMinBST(a, 0, 3);

	vector<LLnode*> * v = new vector<LLnode*>();
	graphLevel(n, 0, v);
	for(int i = 0 ; i < v->size() ; i++)
	{
		LLnode* ptr = (*v)[i];
		cout << ptr->data << ", ";
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
			cout << ptr->data << ", ";
		}
		cout << endl;
	}
	delete v;
	
	return 1;
}