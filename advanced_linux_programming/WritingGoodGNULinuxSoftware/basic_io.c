#include <stdio.h>
int main( int argc, char** argv )
{
    int i = 1000;
    while (i--)
    {
        fprintf( stderr, "." );
        sleep(1);
    }
    return 0;
}
