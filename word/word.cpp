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

#include <string>
#include "word.h"

using namespace std;


/*****************************************************************************************************
Function Name:  WORD
Preconditon:  The state has not been initialized for the list.
Postcondition: The state of the class is initialized. Front and Back = 0.
Description:  For the default constructor, both the front and back pointers are initialized to 0.
*******************************************************************************************************/
WORD::WORD()
{
	front = back = 0; //set front and back to default
}

/*****************************************************************************************************
Function Name:  WORD
Preconditon:  The state has not been initialized for the list.
Postcondition: State of class is intialized and the nodes are set to the string passed.
Description:  The explicit value constructor allows the nodes to contain the string passed. It
initializes the nodes and allocates memory.
*******************************************************************************************************/
WORD::WORD(string s)
{
	front = back = 0; //set front and back to default
	*this = s; //use assignment operator to set current object to s
}

/*****************************************************************************************************
Function Name:  WORD
Preconditon:  The state has not been initialized for the list.
Postcondition:The state of the class is initialized. 
Description:  For the copy constructor, words are declared by value.
*******************************************************************************************************/
WORD::WORD(const WORD &org)
{
	front = back = 0;
	*this = org;
}


/*****************************************************************************************************
Function Name:  ~WORD 
Preconditon:  The state of the list was previously initialized.
Postcondition: All memory is deallocated from the current object.
Description:  The destructor deallocates memory from the current object.
*******************************************************************************************************/
WORD::~WORD()
{
	cout << "The destructor has been called" << endl; //message

	deleteList();

	front = 0; //front is null
}

/*****************************************************************************************************
Function Name:  addNode
Preconditon:  The list has been initialized.
Postcondition: A node is added to the back of the list
Description:  This function allocates new memory for the new node and adds it to the back of the list. 
If there is no list, it becomes the first node. This function is called within Insert and assignment
operator overloading functions.
*******************************************************************************************************/
void WORD::addNode(char c)
{
	character *add = new character;	//initialize new node
	add->symbol = c; //adds character to list
	add->next = 0; //next pointer points last

	if (front == 0) //first node
	{
		front = add; //both front and back
		back = add;	//=add
		return;
	}

	back->next = add; //back node points next
	back = add; //new back node
}



/*****************************************************************************************************
Function Name:  Insert
Preconditon:  The list has been initialized.
Postcondition:  The incoming word is inserted into the position designated by the integer
Description:  The word inserted at end of list
*******************************************************************************************************/
void WORD::Insert(WORD org)
{
	int size = Length();
	character *current;

	current = org.front; //add characters to end one by one
	while (current != 0) //current isn't null
	{
		addNode(current->symbol);
		current = current->next;
	}
}

/*****************************************************************************************************
Function Name:  InsertLetter
Preconditon:  The list has been initialized.
Postcondition:  Node created and added.
Description:  Inserts char, c, at the end of the list.
*******************************************************************************************************/
void WORD::InsertLetter(char c)
{
	character *addthis = new character;	//new node
	addthis->symbol = c; //insert c
	addthis->next = front;
	front = addthis;
}

/*****************************************************************************************************
Function Name:  IsEmpty
Preconditon:  The list has been initialized.
Postcondition:  Returns true or false
Description:  Simply, this function returns true if WORD is empty. This could have been done inline,
however, I prefer to keep all functions within one .cpp file.
*******************************************************************************************************/
bool WORD::IsEmpty()
{
	return (front == 0);
}


/*****************************************************************************************************
Function Name:  IsEqual
Preconditon:  The list has been initialized.
Postcondition:  Returns true
Description:  This function goes through the list to see if the two match.
*******************************************************************************************************/
bool WORD::IsEqual(WORD &org)
{
	character *temp = org.front;  //temporary node
	character *current = front;			// current node

	while (current != 0 && temp != 0) //while both not null
	{
		if (current->symbol != temp->symbol) //if current and temp do not match
		{
			return false; //they are not equal
		}

		temp = temp->next; //both nodes move up
		current = current->next;
	}
	return true;  //are equal
}

/*****************************************************************************************************
Function Name:  Length
Preconditon:  The list has been initialized.
Postcondition:  Returns the amount of nodes in the list.
Description:  Keeps count by incrementing for each node where front !=0
*******************************************************************************************************/
int WORD::Length()
{
	int count = 0; //declare and initialize count
	character *current = front;	//current = front
	
	while (current != 0)	//while current isn't null
	{
		count++; //count increments
		current = current->next;	//current points next and loop
	}

	return count;	//return size (count)
}

/*****************************************************************************************************
Function Name:  operator<<
Preconditon:  The list has been initialized.
Postcondition:  Operator << is overloaded to allow for WORD output
Description:  Loops each letter through output
*******************************************************************************************************/
ostream & operator<<(ostream &out, WORD &org)
{
	character *current = org.front;

	while (current != 0) //loops until current = 0
	{
		out << current->symbol; //output the current character
		current = current->next; //point to the next and loop
	}

	return out;
}

/*****************************************************************************************************
Function Name:  operator+
Preconditon:  The list has been initialized.
Postcondition:  Adds explicit WORD to the end of implicit WORD
Description:  The Insert() function is called to insert the explicit WORD at the end of the current object.
*******************************************************************************************************/
WORD & WORD::operator+(WORD &org)
{

	Insert(org); //call Insert function where org and its length are the actual arguments

	return *this; //return the current object

}


/*****************************************************************************************************
Function Name:  operator=
Preconditon:  The list has been initialized.
Postcondition: Overloads assignment operator when the explicit agrument is a string
Description:  The WORD now contains a list of the characters in string
*******************************************************************************************************/
WORD & WORD::operator=(const string &s)
{
	deleteList();

	front = 0; //re-initialize front and back
	back = 0;

	for (unsigned int i = 0; i<s.size(); i++)
	{
		addNode(s[i]);
	}

	return *this;
}

/*****************************************************************************************************
Function Name:  deleteList
Preconditon:  The list has been initialized.
Postcondition: Deletes nodes in list
Description:  Simple function that deletes the list, usually for the destructor or assignment operators.
*******************************************************************************************************/
void WORD::deleteList()
{
	character *current = front; //temp nodes
	character *temp;

	while (current != 0) //loop and delete old list
	{
		temp = current->next; //use temps to
		delete current;
		current = temp;
	}

}

/*****************************************************************************************************
Function Name:  operator=
Preconditon:  The list has been initialized.
Postcondition:  Overloads assignment operator for when the explicit argument is a WORD
Description:  Implicit argument (this) is now a list equivilant to the explicit WORD
*******************************************************************************************************/
WORD & WORD::operator=(const WORD &org)
{

	
	if (this == &org) //if they are the same, print message and return current object
	{ 
		cout << "The two WORDS are already equivalent..." << endl;
		return *this; 
	}

	deleteList();
	
	character *current = front = 0; //re-initialize list front and back
	back = 0;

	current = org.front; //start at explicit's front

	while (current != 0)
	{
		addNode(current->symbol); //add the current symbol then
		current = current->next; //point next and loop
	}
	return *this;
}
