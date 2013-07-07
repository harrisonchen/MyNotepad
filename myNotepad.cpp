#include "myNotepad.h"
#include <fstream>

using namespace std;

MyNotepad::MyNotepad()
{

}

void MyNotepad::loadNotes()
{
	const int MAX = 1000;
	char title[MAX];
	ifstream readNotes("SavedNotes/files.txt");
	do
	{
		readNotes.getline(title, MAX);
		if(!readNotes.eof())
		{	
			notes.pushFront(title);
		}
	}
	while(!readNotes.eof());
	readNotes.close();
}

void MyNotepad::createNote(string title)
{
	notes.pushFront(title);
	ofstream writeFile("SavedNotes/files.txt", ios::app);
	writeFile << title;
	writeFile << "\n";
	writeFile.close();
	title = "SavedNotes/" + title + ".txt";
	const char* c = title.c_str();
	ofstream writeNote(c);
	writeNote.close();
}

string MyNotepad::deleteNote(string title)
{
	string info;
	info = notes.deleteNode(title);
	ofstream writeFile("SavedNotes/files.txt");
	while(!notes.isEmpty())
	{
		writeFile << notes.popBack();
		writeFile << "\n";
	}
	writeFile.close();
	loadNotes();
	title = "SavedNotes/" + title + ".txt";
	const char* c = title.c_str();
	remove(c);
	return info;
}

void MyNotepad::editNote(string title)
{
	title = "SavedNotes/" + title + ".txt";
	const char* c = title.c_str();
	ofstream writeNote(c,ios::app);
	string sentences, temp;
	bool finished = false;
	do
	{
		getline(cin, sentences);
		if(sentences == "")
		{
			finished = true;
		}
		else
		{
			writeNote << sentences;
			writeNote << "\n";
		}
	}
	while(!finished);
	writeNote.close();
}

void MyNotepad::listNotes()
{
	notes.printList();
}

void MyNotepad::readNote(string title)
{
	string sentences = "";
	const int MAX = 1000;
	char buffer[MAX];
	title = "SavedNotes/" + title + ".txt";
	const char* c = title.c_str();
	ifstream readNote(c);
	do
	{
		readNote.getline(buffer,MAX);
		if(!readNote.eof())
		{
			sentences = sentences + buffer + "\n";
		}
	}
	while(!readNote.eof());
	cout << sentences;
	readNote.close();	
}
