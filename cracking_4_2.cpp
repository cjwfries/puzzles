#include <cstddef>
#include <vector>
#include <queue>
#include <iostream>

/* 7/15/14 Cracking the Coding Interview
* 4.2 Given a directed graph, design an algorithm to find out whether there is a route 
* between two nodes.
*/


using namespace std;

class node {
	private:
		char data;
	public:
		node(char c)
		{
			data = c;
			visited = false;
		}
		vector<node*> neighbors;
		bool visited;
};

bool hasRoute(node* s, node* f, queue <node*> *q)
{
	if(q->empty())
		return false;
	s->visited = true;
	for(int i = 0 ; i < s->neighbors.size() ; i++)
	{
		node* e = s->neighbors[i];
		if(e == f)
			return true;
		if(!(e->visited))
			q->push(e);
	}
	node* n = q->front();
	q->pop();
	return hasRoute(n, f, q);
}


int main() {
	node* a = new node('a');
	node* b = new node('b');
	node* c = new node('c');
	node* d = new node('d');
	a->neighbors.push_back(b);
	a->neighbors.push_back(c);
	b->neighbors.push_back(c);
	b->neighbors.push_back(d);
	
	queue<node*> *q = new queue<node*>;
	q->push(a);
	
	if(!hasRoute(c, d, q))
		cout << "No Route" << endl;
	else
		cout << "Has Route" << endl;
	delete q;
	return 1;
}