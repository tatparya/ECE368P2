/*
**      File to test the random generator in the testcode
*/

#include <stdlib.h>
#include <stdio.h>

//  Main function
int main (int argc, char ** argv)
{
    int n;
    int * list;

    //  UI
    printf( "Enter the number of integers in list: " );
    scanf( "%d", &n );

    //  Call to rand generator
    list = randGenerator( n );

    //  Print generated list
    printArray( list, n, "\nRandomly generated array;" );

    sort( list, n );

    printArray( list, n, "\nAfter Sorting:" );

    return(0);
}
