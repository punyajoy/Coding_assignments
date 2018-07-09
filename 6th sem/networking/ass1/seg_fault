#include <stdio.h>

int main()
{
   char *str; 
 
   /* Stored in read only part of data segment */
   str = "HELLO";     
 
   /* Problem:  trying to modify read only memory */
   *(str+1) = 'h'; 
   return 0;
}