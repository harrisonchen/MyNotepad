#include "dLList.h"

using namespace std;

DoublyList::DoublyList()
{
	head = tail = 0;
}

DoublyList::~DoublyList()
{
	DLLNode *temp;
	if(head != 0)
	{
		for(temp = head->next; temp != 0; temp = temp->next)
		{
			delete head;
			head = temp;
		}
	}
}

bool DoublyList::isEmpty()
{
	if(head == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DoublyList::pushFront(string d)
{
	if(isEmpty())
	{
		head = tail = new DLLNode(d);
	}
	else
	{
		head = new DLLNode(d,head,0);
		head->next->prev = head;
	}
}

void DoublyList::pushBack(string d)
{
	if(isEmpty())
	{
		head = tail = new DLLNode(d);
	}
	else
	{
		tail = new DLLNode(d,0,tail);
		tail->prev->next = tail;
	}
}

string DoublyList::popFront()
{
	string info;
	if(!isEmpty())
	{
		if(head == tail)
		{
			info = head->data;
			delete head;
			head = tail = 0;
			return info;
		}
		else
		{
			info = head->data;
			DLLNode *temp = head;
			head = head->next;
			head->prev = 0;
			delete temp;
			return info;
		}
	}
	return "empty";
}

string DoublyList::popBack()
{
	string info;
	if(!isEmpty())
	{
		if(head == tail)
		{
			info = tail->data;
			delete tail;
			head = tail = 0;
			return info;
		}
		else
		{
			info = tail->data;
			tail = tail->prev;
			delete tail->next;
			tail->next = 0;
			return info;
		}
	}
	return "empty";
}

string DoublyList::deleteNode(string d)
{
	string info;
	if(!isEmpty())
	{
		if(head->data == d)
		{
			info = popFront();
			return info;
		}
		else if(tail->data == d)
		{
			info = popBack();
			return info;
		}
		else
		{
			DLLNode *temp;
			for(temp = head; (temp != 0)&&(temp->data != d); temp = temp->next);
			if(temp != 0)
			{
				info = temp->data;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
				return info;
			}
			else
			{
				return "none";
			}
		}
	}
	return "empty";
}

void DoublyList::printList()
{
	if(isEmpty())
	{
		cout << "Empty List" << endl;
	}
	else
	{
		DLLNode *temp;
		for(temp = head; temp != 0; temp = temp->next)
		{
			cout << temp->data << endl;
		}
	}
}
