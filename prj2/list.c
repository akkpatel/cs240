#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

struct lnode {
 char* word;
 int count, lseen;
 struct lnode *next;
 struct lnode *prev;
};
 struct lnode *head = NULL;
 struct lnode *tail = NULL;

/**
 * In the linked list with *head and *tail as head and tail pointers,
 * add a newly-created node to the tail of the list. The new node has
 * the given word and line, and a count of 1. You must duplicate word,
 * as the original word may be modified by the calling function. Return
 * value is the newly-created node.
 */
struct lnode *newNode(struct lnode **head, struct lnode **tail, char *word, int line) {
printf("IN\n");
 
struct lnode* temp; //create a temporary node to store data;
temp = (struct lnode *)malloc(sizeof(struct lnode)); //allocate memory
temp->word = (char *)malloc(strlen(word)+1);
printf("copied word\n");
strcpy(temp->word, word);//copy word to temp
//strcpy(temp->line, line);//copy line to temp
temp->line=line;
printf("next line\n");
temp->next = NULL; //set it to null
printf("set to null\n");
		printf("line: %i\n", line);
		printf("word: %s\n", word);

	if((head==NULL)&&(tail==NULL)){
		printf("inside if\n");
		(head)=temp;
		(tail)=temp; //set them to newnode if they are null;
		printf("head & temp\n");
	}else{
		printf("inside else\n");
		 (tail)=temp;
  		 (temp)->next = NULL;
		  printf("tail = temp\n");

	return temp;

	}
 /*if(((*head) == NULL) && ((*tail) == NULL)){ // check to see if head and tail are null;
	printf("inside if\n");
	(*head)=temp;
	(*tail)=temp; //set them to newnode if they are null;
	printf("head & temp\n");
	return temp;
	//free(*head);
	}
  else{
	printf("inside else\n");
   (*tail)->next = temp;
  (*tail)=temp;
	printf("tail = temp\n");
	return temp;

  }*/
return 0;
}

/**
 * Removes the specified node from the list, and frees all memory the node is using.
 * Remember that if *head or *tail are the node, they will need to be updated!
 */
void deleteNode(struct lnode **head, struct lnode **tail, struct lnode *node) {
 if((node == *head) && (node == *tail)){
		*head=(node->next)->prev;
		*tail=(node->next)->next;
		free(node);
 }
}

/**
 * Simply returns the next node in the list, or NULL if there are no further nodes.
 */
struct lnode *nodeGetNext(struct lnode *node) {
 if((node->next) == NULL){
		return NULL;
 }else{return (node->next);}
}

/**
 * Simply returns the word in the given node.
 */
char *nodeGetWord(struct lnode *node) {
  return (node->word);
}

/**
 * Simply returns the line in the given node.
 */
int nodeGetLine(struct lnode *node) {
  return (node->lseen);
}

/**
 * Simply returns the count in the given node.
 */
int nodeGetCount(struct lnode *node) {
  return (node->count);
}

/**
 * Increments the count in the given node, and returns the new count.
 */
int nodeIncCount(struct lnode *node) {
  return(node->(++count));
}

/**
 * If the linked list with *head and *tail as head and tail pointers contains
 * a node with the specified word, that node is returned, with its line updated
 * to the specified line. Otherwise, returns NULL.
 */
struct lnode *getNode(struct lnode **head, struct lnode **tail, char *word, int line) {
	struct lnode *node=*head;
	while((node->head) != NULL){
		if((strcmp((node->word),word)) != 0){
			node->lseen=line;
			return node;
		}else{return NULL};
	}
}

/**
 * Deletes every node in the list with *head and *tail as head and tail pointers.
 * After calling this function, all memory used by the list should be freed,
 * and *head and *tail should both be NULL.
 */
void deleteList(struct lnode **head, struct lnode **tail) {
  struct lnode *node=*head;
  while(node != NULL){
			deleteNode(*head, *tail, node);
  }
  *head=NULL;
  *tail=NULL;
}
