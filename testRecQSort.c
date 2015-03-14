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
    //scanf( "%d", &n );

    n = 30;

    //  Call to rand generator
    list = randGenerator( n );

    /*int k = 0, l = 0, z = 0, m;
    for( ; k < 100000000; k++ )
        for( ; l < 100000000; l++ )
            for( ; z < 100000000; z++ )
            {
                m = z/10;
            }
*/
    //  Print generated list
    //printArray( list, n, "\nRandomly generated array;" );

    //recQSort( list, n );

    //printArray( list, n, "\nAfter Sorting:" );

    return(0);
}
