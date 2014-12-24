#include <stdio.h>
#include "utils.h"
#include "words.h"

/**
 * Read one line from standard input into {buf}. \n will be put in {buf} too
 * if there is one. Return the length of the message. Return EOF if there are
 * no more lines to read.
 */
int readMsg(char* buf) {
  /* FILL IN HERE */
  int c;
  int j=0;
  int i = 0;

  while ((c = getchar()) != EOF) {
	if(buf!=0){
	j++;
	*(buf + i++) = (char)c;
	if(c=='\n'){
	break;
	}
  j=0;
     }
 
  }
while(c == EOF && j==0) {
	    return -1;
 }

    return i;
}
/**
 * Find the next word. {msg} is a pointer to an array of characters.
 * {len} is the length of the {msg} array. {end} is a pointer to an integer that
 * holds the current position in the array of characters.
 *
 * The function will find the next word, starting from the position given by the
 * initial value of {end}.
 *
 * If a word was found the function returns 1, and updates {start} to point to
 * the index of the first character in the word, {end} to point to the index of
 * the first character after the word.
 *
 * If no word was found, the function returns 0.
 */
int getWord(char* msg, int len, int* start, int* end) {
 /* FILL IN HERE */
	int i;
	int j=*end;	
	int k=0;
	//*start=0;
	for(i=j; i<len;i++){
		if(isAlpha(*(msg+i))&&k==0){
			*start=i;
		 // *start++;
	  	 k=1;
		}

//	}
//	for(i=j; i<len;i++){
		else if(!(isAlpha(*(msg+i)))&& k==1){
			*end=i;
			k=0;
		return *end-*start;	
		}
	  }

return 0;
} 
                                                                                                                                      










/**
 * Check if {word} is contained in {keywords}. If yes, erase {word} with
 * white spaces. {len} indicates the length of {word} and {num} indicates
 * the length of the keyword list.
 */
void checkWord(char* word, int len, char** keywords, int num) {
  /* FILL IN HERE */
	for(int i=0;i<num; i++){
		if(len==num){
		word=*keywords;
		}
		spaceOut(word,i);
	}
}

/*
 * Change the character pointed by {c} to lower case if it is a capital.
 */
void unCapitalize(char* c) {
  /* FILL IN HERE */
if(*c>= 'A' && *c<='Z')
    *c = *c + 32;

}
