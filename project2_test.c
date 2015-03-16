/*
**      File to test the recursive qsort in the testcode
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//  Function to generate a list of random numbers of n elements
int * randGenerator( int n )
{
    //  Randomize
    time_t t;
    srand( ( unsigned ) time( &t ) );
    int * list;

    //  Mallo list memory
    list = malloc( n * sizeof( int ) );
    int i = 0;
    int num;

    //  Generate random integers and put into list
    for( i = 0; i < n; i ++ )
    {
        num = rand() % 10000 + 1;
        list[i] = num;
        //printf( "%d : %d\n", i + 1, list[i] );
    }

    //  Return list
    return list;
}

//  Main function
int main (int argc, char ** argv)
{
    int n;
    int * list;

    //  UI
    //printf( "Enter the number of integers in list: " );
    //scanf( "%d", &n );

    n = 10000;

    //  Call to rand generator
    list = randGenerator( n );

    //  Print generated list
    //printf( "Testing recursive qsort\n");
    //printArray( list, n, "\nRandomly generated array:\n" );

    sort( list, n );

    //printArray( list, n, "\nAfter Sorting:\n" );

    return(0);
}
