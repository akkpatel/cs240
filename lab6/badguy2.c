#include <stdio.h>
#include<stdlib.h>
#include "callstack.h"

void badguy(int food) {
  /* FILL THIS IN */
   /* int* p;
    int x =0;
    p=&food;
    int y=0;
    int* i;
    i=&y;
    i*=0xBADBEEF;
    for(x=0;x<50;x++){
    *p=*i;  
  
    *p++;
    printf("%p: %X\n", p, *p);
    }
printf("%p: %X\n", p, *p);
*/ 
    int* p;
    int x =0;
    p=&food;
    int y=0;
    int* i;
    i=&y;
    i*=0xBADBEEF;
    for(x=0;x<50;x++){
    *p=*i;  
  
    *p++;
    printf("%p: %X\n", p, *p); 
    puts("here");
    }
    printf("%p: %X\n", p, *p);
   
}


