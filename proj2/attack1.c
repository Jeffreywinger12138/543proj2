#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    char buf[174];
    memset(buf, 'A', 173);
    buf[173] = 0;
    /* YOUR CODE: Generate buf appropriately */
    write_to_file( "attack1-payload", buf, 174, FILE_CLEAR );
    exit(0);
}