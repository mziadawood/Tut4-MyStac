// Stack1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Stack1.h"


// This is an example of an exported variable
STACK1_API int nStack1=0;

// This is an example of an exported function.
STACK1_API int fnStack1(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Stack1.h for the class definition
CStack1::~CStack1()
{

	NODE*p1;
	while (head != NULL)
	{
		p1 = head;
		head = head->link;
		delete p1;
	}

	return;
}

bool CStack1::push(int val)
{
	NODE *p1 = new NODE;

	if (p1 != NULL)
	{
		if (!isFull()){
			if (head == NULL)
			{
				head = p1;
				p1->link = NULL;
				p1->data = val;
				currS++;
				return true;
			}

			else
			{
				p1->link = head;
				p1->data = val;
				head = p1;
				currS++;
				return true;
			}
		}
	}

	return false;

}


bool CStack1::pop(int &val)
{
	if (!isEmpty())
	{
		NODE *p1 = head;
		val = head->data;
		head = head->link;
		currS--;
		delete p1;

		return true;

	}
	return false;
}

bool CStack1::peek(int &val)
{
	if (!isEmpty())
	{
		
		val = head->data;
		return true;

	}
	return false;

}


bool CStack1::isEmpty()
{
	if (currS == 0)
		return true;
	else
		return false;

}


bool CStack1::isFull()
{
	if (currS == maxS)
		return true;
	else
		return false;

}