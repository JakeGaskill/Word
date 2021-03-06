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
#include "word.h"

using namespace std;

int main()
{

	WORD you;
	cout<<"************TEST#1*******************************\n";
	cout<<"Testing the default constructor and printing empty word\n";
	cout<<you<<endl;
	cout<<"The length of you is "<<you.Length()<<"= 0\n";
	cout<<"*************************************************\n";
	cout<<endl<<endl;
	

	cout<<"************TEST#2*******************************\n";
	WORD me("AAAA0000AAA0000AAA");
	cout<<"Testing the explicit-value constructor\n";
	cout<<me<<endl;
	cout<<"me is \n"<<me<<"= AAAA0000AAA0000AAA\n";
	cout<<"*************************************************\n";
	cout<<endl<<endl;


	cout<<"************TEST#3*******************************\n";
	WORD them = me;
	cout<<"Testing the copy constructor\n";
	cout<<"them is \n"<<them<<"= AAAA0000AAA0000AAA\n";
	cout << "Testing the copy constructor for them = them\n";
	them = them;
	cout << "A mesage stating they are equal should appear\n";
	cout<<"*************************************************\n";
	cout<<endl<<endl;

	cout<<"************TEST#4*******************************\n";
	cout<<"Testing length\n";
	cout<<"The length of me is "<<me.Length()<<" = 18 "<<endl;
	cout<<"The length of them is "<<them.Length()<<" = 18 "<<endl;
	cout<<"The length of you is "<<you.Length()<<" = 0 "<<endl;
	cout<<"*************************************************\n";
	cout<<endl<<endl;

	cout<<"************TEST#5*******************************\n";
	WORD us;
	us = "AA";
	cout<<"Testing operator= by assignment the value of \"AA\" to use\n";
	cout<<"The word us is \n"<<us<<" = AA"<<endl;
	cout<<"*************************************************\n";
	cout<<endl<<endl;

	cout<<"************TEST#6*******************************\n";
	WORD everyone;
	everyone = "hello world\n";
	us = everyone;
	cout<<"Testing operator= by assigning everyone to us";
	cout<<"The word us is \n"<<us<<" = hello world"<<endl;
	cout<<"*************************************************\n";
	cout<<endl<<endl;

	cout<<"************TEST#7*******************************\n";
	WORD our, him;

	our = "AAA000AAA000";
	us = "XXXX";
	WORD thing = "XXXX";

	cout<<"Testing IsEqual by testing to see if us is equal to our \n";
	if (our.IsEqual(us))
	cout<<"The 2 words (our and us) are equal\n";
	else
	cout<<"The 2 words (our and us) are not equal\n";
	cout << "TEST SHOULD REVEAL THAT our AND us are not equal\n";

	cout << "Testing IsEqual by testing to see if thing is equal to us \n";
	if (thing.IsEqual(us))
		cout << "The 2 words (thing and us) are equal\n";
	else
		cout << "The 2 words (thing and us) are not equal\n";
	cout << "TEST SHOULD REVEAL THAT thing AND us are equal\n";
	


	cout<<"*************************************************\n";
	cout<<endl<<endl;

	cout<<"************TEST#8*******************************\n";
	cout<<"Adding 2 words by adding us to the back of their.  Their is the current object \n";
	WORD their("AAAA0000AAA0000AAA");
	their + us;
	cout<<"their followed by us is \n"<<their<<" = AAAA0000AAA0000AAAXXXX"<<endl;
	cout<<"*************************************************\n";
	cout<<endl<<endl;

	cout<<"************TEST#9*******************************\n";
	cout<<"Adding 2 words, their2 is empty, by adding us to the back of their.  Their is the current object \n";
	WORD their2("");
	their2 + us;
	cout<<"their followed by us is \n"<<their2<<" = XXXX"<<endl;
	cout<<"*************************************************\n";
	cout << endl << endl;

	cout<<"************TEST#10*******************************\n";
	cout<<"Adding 2 words, their3 is empty, by adding us to the back of their.  Their is the current object \n";
	WORD their3("");
	us + their3;
	cout<<"us followed by empty their3 is \n"<<us<<" = XXXX"<<endl;
	cout<<"*************************************************\n";
	cout<<endl<<endl;
	cout<<endl<<endl;

	return 0;
}