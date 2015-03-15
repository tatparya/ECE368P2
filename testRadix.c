/*
**      File to test the radix sort in the testcode
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
    //scanf( "%d", &n );

    n = 10;

    //  Call to rand generator
    list = randGenerator( n );

    //  Print generated list
    printf( "Testing recursive qsort\n");
    printArray( list, n, "\nRandomly generated array:\n" );

    recQSort( list, n );

    printArray( list, n, "\nAfter Sorting:\n" );

    return(0);
}
