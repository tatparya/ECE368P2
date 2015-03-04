/* ****************************
**
**  ECE 368 Project 2
**
**  Title: Sorting Competetion
**
**  Student 1: Tatparya Shankar
**  username: tshankar
**
***************************** */

#include "project2.h"


int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

//  Main function

int main (int argc, char ** argv)
{
    int n;
    int num = atoi( argv[1] );
    printf("Before sorting the list is: \n");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }

    qsort(values, 5, sizeof(int), cmpfunc);

    printf("\nAfter sorting the list is: \n");
    for( n = 0 ; n < 5; n++ ) {
        printf("%d ", values[n]);
    }
    printf("\n");
    int i = 0;
    int a = 1;
    for( i = 0; i < num; i ++ )
    {
        for( a = 0; a < num; a ++ )
        {

        }
    }

    printf( "Num = %d\n", num );
    return(0);
}

//  Main Sort Function
void sort( int list[], int n )
{

}

//  Print array of numbers
void * printArray( int list[], int n )
{
    int i = 0;
    printf( "Array :\n" );
    for( i = 0; i < n; i++ )
    {
        printf( "%d", list[i] );
    }
    printf( "\n" );
}

//  Function to generate a list of random numbers of n elements
int * randGenerator( int n )
{
    time_t t;
    srand( ( unsigned ) tiem( &t ) );
    int * list;
    list = malloc( n * sizeof( int ) )
    int i = 0;
    int num;
    for( i = 0; i < n; i ++ )
    {
        num = rand() % 10 + 1;
        list[i] = num;
    }
}
