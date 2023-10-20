#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "util-program.h"

/*
*
* PACK function usage.
*
* Use this function to add a valid address "value" to a char array at Address "addr"+"offset"
* Example 1 - pack(p,24,0x0876aaff) will add the address value "0x0876aaff" exactly 24 bytes after the address pointed by the pointer "p".
* Example 2 - pack(b,32,0x0188a2e3) will add the address value "0x0188a2e3" exactly 32 bytes after the address pointed by the pointer "b".
*
*/
#define pack(addr, offset, value)  (*((int *)(addr+offset)) = value)

/*
* This utility function is taken from CSE443 - Overflows by Dr. Trent Jaeger
*/
int errorMessage( char *msg ) 
{
    /* Print message and return */
    fprintf( stderr, "CSE443 Error: %s\n", msg );
    return( 0 );
}

/*
* This utility function initializes your buffer to 0's.
*/
void initialize_buffer(char* buf_ptr, int size){
    for(int i=0; i<size; i++){
        *(buf_ptr + i) = 0;
    }
    return;
}

/*
* This utility function is taken from CSE443 - Overflows by Dr. Trent Jaeger
*/
int write_to_file(char *fname, char *content, int len, unsigned flag )
{
    int fh;
    int outbytes;
    unsigned flag_set = ((flag == FILE_CLEAR) ? 
                 (O_RDWR | O_TRUNC | O_CREAT) :
                 (O_RDWR | O_APPEND));

    if ( (fh=open(fname, flag_set, S_IRUSR | S_IWUSR)) == -1 )
    {
        /* Complain, explain */
        char msg[128];
        sprintf( msg, "failure opening file [%.64s]\n", fname );
        errorMessage( msg );
        return -1;
    }

    outbytes = write( fh, content, len );

    if ( outbytes != len ) {
        /* Complain, explain */
        char msg[128];
        sprintf( msg, "failure writing to file [%.64s]\n", fname );
        errorMessage( msg );
        return -1;
    }

    return 0;
}

/*
* This utility function is taken from CSE443 - Overflows by Dr. Trent Jaeger

*******read fname and put info to the content
*/
int read_from_file(char *fname, char **content)
{
    int fh;
    int outbytes, len;
    struct stat statbuf;
    char *buf;

    if ( (fh=open(fname, O_RDONLY, 0)) == -1 )
    {
        /* Complain, explain */
        char msg[128];
        sprintf( msg, "failure opening file [%.64s]\n", fname );
        errorMessage( msg );
        return -1;
    }

    /* get file size */
    fstat(fh, &statbuf);
    outbytes = statbuf.st_size;

    /* read the file */
    buf = *content = (char *) malloc(outbytes+1);
    if ( (len = read(fh, buf, outbytes)) == -1 ) {
        char msg[128];
        sprintf( msg, "failure writing to file [%.64s]\n", fname );
        errorMessage( msg );
        return -1;
    }
    buf[outbytes] = '\0';
    return len;
}

