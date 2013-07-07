#include "myNotepad.h"
#include <fstream>
//#include <cstdio>

using namespace std;

MyNotepad::MyNotepad()
{

}

void MyNotepad::createNote(string title)
{
	notes.pushFront(title);
	title = "SavedNotes/" + title + ".txt";
	const char* c = title.c_str();
	ofstream writeNote(c);
	writeNote.close();
}

string MyNotepad::deleteNote(string title)
{
	title = "SavedNotes/" + title + ".txt";
	const char* c = title.c_str();
	remove(c);
	return notes.deleteNode(title);
}

void MyNotepad::editNote(string title)
{
	title = "SavedNotes/" + title + ".txt";
	const char* c = title.c_str();
	ofstream writeNote(c);
	string sentences;
	getline(cin, sentences);
	writeNote << sentences;
	writeNote.close();
}

void MyNotepad::listNotes()
{
	notes.printList();
}

void MyNotepad::readNote(string title)
{

}
