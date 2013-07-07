#ifndef MYNOTEPAD.H
#define MYNOTEPAD.H
#include <iostream>
#include "dLList.cpp"

using namespace std;

class MyNotepad
{
public:
	MyNotepad();
	void loadNotes();
	void createNote(string);
	string deleteNote(string);
	void editNote(string);
	void listNotes();
	void readNote(string);

protected:
	DoublyList notes;
};

#endif /*MYNOTEPAD.H*/
