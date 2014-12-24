#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
void unCapitalize(char* c) {
  /* FILL IN HERE */
if(*c>= 'A' && *c<='Z')
    *c = *c + 32;
}

int isAlpha(char ch) {
  /* FILL IN HERE */
	if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z'){
		return 1;
	}
	else{
		return 0;
	}
}
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

 struct lnode{
    struct lnode* next;
    int index ;
    int find;
    int line;
    char *word; 
   
 };

int main(){
  char msg[140];
  int storeword;
  int k=0;
  int j=0; 
  int *start = &k;
  int *end = &j; 
  int length;
  int linelength;
  int i;
  int numlines=0;
  char *word;
  char string[140];
   for(i=0;i<140;i++){
     string[i] = '\0';
   }
  int lines;

  struct lnode *node, *head, *tail, *temp, *track;
	head=tail=NULL;
	node=NULL;
  node = (struct lnode *)malloc(sizeof(struct lnode));
  while ((length = readMsg(msg))!= EOF){
//	printf("length %d\n", length);
       *start =0;
       *end = 0;
	while(getWord(msg,length,start,end)){;
		for(i = *start;i<=*end;i++){
			unCapitalize(msg+i);
		}
		int a=0;
		for(i = *start;i<=*end;i++){
			if(isAlpha(msg[i])==1){
			string[a++] = msg[i];
			}			
		}
					
		a=0;
		int linenum =1;
	/*	for(i=0;i<140;i++){
			string[i] = '\0';
		}*/
			
	//	printf("string %s\n", string);
	//	printf("start %d\n",*start);
	//	printf("end %d\n",*end);
	//	printf("in while\n");
	//	word=node->word;
	/*	node = newNode(&head,&tail,string,numlines);
		nodeGetNext(node);
		lines = nodeGetLine(node);
		if(node == getNode(&head,&tail, (msg+*start),lines)){
			printf("inside if loop\n");
			word = nodeGetWord(node);
			numlines = nodeIncCount(node);
		}*/
	//	}
	//	printf("word %s\n", word);
	//	printf("line %d\n", numlines);
	//	printf("%s: %d %d\n", nodeGetWord(node), nodeGetLine(node), nodeGetCount(node));
		newNode(&head,&tail,string,1);
		for(i=0;i<140;i++){
			string[i] = '\0';
		}
	}

		node = getNode(&head,&tail,string,1);
//		(temp) = node->word;		
    		for (node = head; node != NULL; node = nodeGetNext(node)) {
		        /* increment its count */
		      nodeIncCount(node);
	        printf("%s: %d %d\n", nodeGetWord(node), nodeGetLine(node), nodeGetCount(node));
    		}
}
		//printf("lines %d\n",numlines);

  return 0;    
}




















