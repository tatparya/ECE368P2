#include <stdlib.h>
#include <stdio.h>

void customSort( int * list, int numElements );

int main()
{
	int list[10] = { 10, 9, 6, 2, 8, 3, 4, 5, 3 ,1 };
	int numElements = 10;

	customSort( list, numElements );
}

typedef struct integer {
	int value;
	struct integer * next;
} integer;

integer * createInteger( int value );
{
	//	Malloc
	newInt = malloc( sizeof( integer ) );

	//	Initialize values
	newInt -> value = value;
	newInt -> next = NULL;

	//	Return element
	return newInt;
}

integer * addToList( integer * newInt, integer * head )
{
	//	Put at the head
	if( head == NULL )
	{
		head = newInt;
		return head;
	}

	integer * element = head;

	//	Put in the middle
	while( element -> value < newInt -> value )
	{
		//	If reached end
		if( element -> next == NULL )
		{
			//	Put at the end
			element -> next = newInt;
			return head;
		}

		element = element -> next;
	}

	//	Put in the middle
	newInt -> next = element -> next;
	element -> next = newInt;

	return head;
}

void customSort( int * list, int numElements )
{
	int i = 0;
	integer * head;

	//	Go through entire array
	for( i = 0; i < numElements; i++ )
	{
		//	Create list struct
		newInt = createInteger( list[i] );

		//	Add on to list
		head = addToList( newInt, head );
	}

	//	Create the array back
	integer * element = head;
	i = 0;
	do
	{
		list[i] = element -> value;
		i++;
	}
	while( element -> next != NULL );
}