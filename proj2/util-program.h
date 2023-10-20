#define FILE_CLEAR 1
#define FILE_APPEND 0

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
* This utility function initializes your buffer to 0's.
*/
void initialize_buffer(char* buf_ptr, int size);

/*
* This utility function is taken from CSE443 - Overflows by Dr. Trent Jaeger
*/
int errorMessage( char *msg );

/*
* This utility function is taken from CSE443 - Overflows by Dr. Trent Jaeger
*/
int write_to_file(char *fname, char *content, int len, unsigned flag);

/*
* This utility function is taken from CSE443 - Overflows by Dr. Trent Jaeger
*/
int read_from_file(char *fname, char **content);

/*
* Buffer Sizes for all victims.
*/
#define V1_SIZE 165
#define V2_SIZE 100
#define V3_SIZE 189
#define V4_SIZE 170
#define V5_SIZE 157
#define V6_SIZE 149
#define V7_SIZE 67
#define V8_SIZE 96
#define V9_SIZE 96