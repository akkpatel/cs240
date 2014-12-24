#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

struct lnode {
 char *word;
 int lseen;
 int count;
	struct lnode *prev;
 struct lnode *next;
};
	
 struct lnode *head=NULL;
 struct lnode *tail=NULL;

/**
 * In the linked list with *head and *tail as head and tail pointers,
 * add a newly-created node to the tail of the list. The new node has
 * the given word and line, and a count of 1. You must duplicate word,
 * as the original word may be modified by the calling function. Return
 * value is the newly-created node.
 */
struct lnode *newNode(struct lnode **head, struct lnode **tail, char *word, int line) {
printf("IN\n");
 struct lnode *new;
	printf("There\n");
 new = (struct lnode*)malloc(sizeof(struct lnode));
 (new->word) = (char *)malloc((strlen(word)+1)*(sizeof(char)));
 printf("Here\n");
		strcpy((new->word), word);
		printf("yo\n");
		new->lseen = line;
		new->count = 1;
		printf("YUP\n");
		printf("line: %i\n", line);
		printf("word: %s\n", word);
		if((head == NULL) && (tail == NULL)){
		printf("Head\n");
		printf("Tail\n");
			head=new;
			tail=new;
			printf("New\n");
			(*head)->prev=NULL;
			(*tail)->next=NULL;
		}else{
		printf("ELSE\n");
			//(*tail)->next=new;
			tail=new;
			printf("Bitchplease\n");
			new->next=NULL;
		}
		printf("--->HEAD: %p\n", &head);
		printf("--->TAIL: %p\n", &tail);
		return new;
}

int main(){
printf("Start\n");
newNode(NULL,NULL,"Hi",1);
newNode((NULL+1),(NULL+1),"Man",2);
newNode((NULL+2),(NULL+2),"Whats up?",3);
return 0;
}
