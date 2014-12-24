#include <stdio.h>
#include "words.h"

int main(int argc, char** argv) {
  char msg[SIZE];
		int len=0;
		int start=0;
		int *pstart=&start; 
		int end=0;
		int *pend=&end;
		int count=0;
		// read in every line of the tweets
  while ((len = readMsg(msg)) != EOF) {
    // get every word in the current line
    *pstart=0;
				*pend=0;
    while (getWord(msg,len,pstart,pend)) {
      // turn the word to small case
//	printf("start %d\n", *pend - *pstart);
//	printf("end %d\n", *pend);
      count = *pstart;
						while(count <= *pend) {
							unCapitalize(msg+count);
							count++;
      }
      // check and process the word
	printf("word %s\n",(msg+*pstart));
      checkWord((msg+*pstart),*pend-*pstart,argv,argc); 
    		
	}
    // output the processed message
    for(count=0;count<len;count++) {
   // putchar(*(msg+count));
    }
  }
  return 0;
}
