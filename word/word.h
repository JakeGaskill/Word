/********************************************************************************************

Name: Jacob Gaskill                    Z#: 23236263
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  2/25/2016           Due Time: 11:00 PM
Total Points: 100
Assignment 4: Word program

Description: In this assignment, we:
(1) allocate memory dynamically
(2) implement a default, explicit-value and copy constructor,
(3) implement a destructor;
(5) identify substrings in a string, and
(6) fully implement and manage a string class.
*********************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class character
{
public:
	char symbol;
	character *next;
};

class WORD
{
public:

	
	WORD();	//constructors and destructor
	WORD(string);
	WORD(const WORD &);
	~WORD();

	bool IsEmpty();	//behaviors
	bool IsEqual(WORD &);
	void Insert(WORD);
	int  Length();
	void InsertLetter(char);
	void addNode(char);
	void deleteList();

	WORD & operator=(const string &); //overloaded operators
	WORD & operator=(const WORD &);
	WORD & operator+(WORD &);
	friend ostream & operator<<(ostream &, WORD &);

private:   
	character *front;  //states
	character *back;   
};


