#include <stdio.h>
#include "callstack.h"

void badguy(int food) {
  /* FILL THIS IN */
	int* p;
	int x =0;
	//p=&x;
	p=&food;
//	p++;
	for(x=0;x<50;x++){
	printf("%p: %X\n", p, *p);
	*p++;
	}
}
