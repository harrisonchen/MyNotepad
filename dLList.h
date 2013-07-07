#ifndef DLLIST.H
#define DLLIST.H
#include "dllNode.h"

using namespace std;

class DoublyList
{
public:
	DoublyList();
	~DoublyList();
	bool isEmpty();
	void pushFront(string);
	void pushBack(string);
	string popFront();
	string popBack();
	string deleteNode(string);
	bool isInList(string);
	void printList();
private:
	DLLNode *head, *tail;
};

#endif /*DLLIST.H*/
