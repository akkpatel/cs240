#include <stdio.h>
#include "words.h"

int main(int argc, char** argv) {
  char msg[SIZE];
  // read in every line of the tweets 
  //int counter = 0; 
  int length = 0 ; 
  int  start = 0;
  int  end  = 0;  
  while (length = readMsg(msg) != EOF) 
   {

	 unCapitalize (msg); 
	
	    while ( getWord(msg,length,&start, &end) ) 
	   {
	     
		 
	      checkWord(msg,length,argv , argc);	      // check and process the word
	    }
    // output the processed message 
  	
  }
printf("%s", msg);
 return 0;
}


