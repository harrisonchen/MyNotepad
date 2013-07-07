#include "myNotepad.h"

using namespace std;

MyNotepad::MyNotepad()
{

}

void MyNotepad::createNote(string title)
{
	notes.pushFront(title);
}

string MyNotepad::deleteNote(string title)
{
	return notes.deleteNode(title);
}

void MyNotepad::editNote(string title)
{

}

void MyNotepad::listNotes()
{
	notes.printList();
}

void MyNotepad::readNote(string title)
{

}
