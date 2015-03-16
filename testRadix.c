/*
**      File to test the radix sort in the testcode
*/

#include <stdlib.h>
#include <stdio.h>

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
        num = rand() % 1000 + 1;
        list[i] = num;
        //printf( "%d : %d\n", i + 1, list[i] );
    }

    //  Return list
    return list;
}

//  To print an array of length n
void printArray( int * array, int n, char * comment )
{
    int i = 0;
    printf("%s\n", comment );
    for( i = 0; i < n; i++ )
    {
        printf( "%d : %d\n", i + 1, array[i] );
    }
    printf( "\n" );
}

//  Find largest number in array
int findLargest( int * array, int n )
{
    int i = 0;
    int max = 0;

    for( i = 0; i < n; i++ )
    {
        //  Check if negative
        if( array[i] < 0 )
        {
            if( array[i] > max )
            {
                max = array[i] * -1;
            }
        }
        //  Positive
        else
        {
            if( array[i] > max )
            {
                max = array[i];
            }
        }

    }

    return max;
}


//  Regular radix sort
//
void radixSort( int * array, int n )
{
    //  Find largest element
    int i = 0;
    int max = 0;
    int sigDig = 1;
    const int base = 10;
    int * b = (int *) malloc( n * sizeof( int ) );

    printf( "In radix sort:\n" );

    //  Find the lasrgest number in the list
    max = findLargest( array, n );

    printf( "Max = %d\n", max );

    //  Sort by each radix
    while( max / sigDig != 0 )
    {
        //  Initiallize bucket to 0
        int bucket[10] = { 0 };

        //  Count num keys for each bucket
        for( i = 0; i < n; i ++ )
        {
            bucket[ ( array[i] / sigDig ) % base ]++;
        }

        printArray( bucket, 10, "Bucket" );

        //  Add the count of the previous buckets
        //  to aquire the indices after the end of
        //  each bucket location in the array
        for( i = 1; i < 10; i++ )
        {
            bucket[i] += bucket[i - 1];
            // *** FIX THIS LINE
        }

        printArray( bucket, 10, "Bucket after summing" );

        //  Starting at the end of the list,
        //  get index correspoinding to a[i]'s key
        //  Decremend it, and use it to place a[i]
        //  into the array
        for( i = n - 1; i >= 0; i -- )
        {

            b[--bucket[(array[i] / sigDig) % base]] = array[i];
        }

        //printArray( bucket, 10, "Bucket" );

        //  Copy array b to a
        for( i = 0; i < n; i++ )
        {
            array[i] = b[i];
        }

        printArray( array, n, "Main array after pass" );

        //  Incremend significant digit
        sigDig *= base;
    }

    //  Free allocated memory
    free( b );

}



//  Main function
int main (int argc, char ** argv)
{
    int n;
    int * list;
    //int listtemp[20] = { 12,11,10,9,15,13,8,7,6,5,4,3,2,1 };

    //  UI
    //printf( "Enter the number of integers in list: " );
    //scanf( "%d", &n );

    n = 24;

    //  Call to rand generator
    list = randGenerator( n );

    //  Print generated list
    printf( "Testing radix sort\n");
    printArray( list, n, "\nBefore sorting:\n" );

    printf( "%p\n\n", &n );

    radixSort( list, n );

    printArray( list, n, "\nAfter Sorting:\n" );

    return(0);
}
