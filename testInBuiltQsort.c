/*
**      File to test the c library qsort in the testcode
*/

#include <stdlib.h>
#include <stdio.h>

//  Main function
int main (int argc, char ** argv)
{
    int n;
    int values[] = { 88, 56, 100, 2, 25 };

    printArray( values, 5, "Before Sorting:" );

    sort( values, 5 );

    printArray( values, 5, "After Sorting:" );

    //  Testing time with inc number of itr
    int i = 0;
    int a = 1;
    int num = 0;
    num = 100;

    for( i = 0; i < num; i ++ )
    {
        for( a = 0; a < num; a ++ )
        {

        }
    }

    printf( "Num = %d\n", num );
    return(0);
}
