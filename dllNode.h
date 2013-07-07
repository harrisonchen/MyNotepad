#ifndef DLLNODE.H
#define DLLNODE.H
#include <iostream>

using namespace std;

class DLLNode
{
public:
	string data;
	DLLNode *next, *prev;
	DLLNode(string d, DLLNode *n = 0, DLLNode *p = 0)
	{
		data = d;
		next = n;
		prev = p;
	}
};
	
#endif /*NODE.H*/
