#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util-program.h"


int crystal(char* inputStr){

    char* buf_ptr = NULL;
    char buf[V2_SIZE];
    buf_ptr = buf;
    initialize_buffer(buf_ptr,V2_SIZE);
    int p,g,b;
    p = g = b = 0;

    sprintf(buf_ptr, "%s", inputStr);
    buf_ptr += strlen(inputStr);

    if(p == 0x12345678){
        printf("\nPurple\n");
    }else if(g == 0x12345678){
        printf("\nGreen\n");
    }else if(b == 0x12345678){
        printf("\nBlue\n");
    }else{
        printf("\nRed, fallen to the dark side you have\n");
    }

    return 0;
}

int main(int argc, char **argv){

    if ( argc < 2 ) {
      printf("These are not the arguments you are looking for!\n"); 
      exit(0);
    }
    printf("You now must pick your Kyber crystal\n");
    char *str;
    int x = crystal(argv[1]);
    return 0;
}
