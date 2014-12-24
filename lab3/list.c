#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

struct lnode {
    /* FILL THIS IN */
struct lnode* next;
struct lnode* prev;
char* word;
int count;
int line;
};

/**
 * In the linked list with *head and *tail as head and tail pointers,
 * add a newly-created node to the tail of the list. The new node has
 * the given word and line, and a count of 1. You must duplicate word,
 * as the original word may be modified by the calling function. Return
 * value is the newly-created node.
 */
struct lnode *newNode(struct lnode **head, struct lnode **tail, char *word, int line) {
    /* FILL THIS IN */

struct lnode* temp; //create a temporary node to store data;
temp = (struct lnode *)malloc(sizeof(struct lnode)); //allocate memory
temp->word = (char *)malloc(strlen(word)+1);
strcpy(temp->word, word);//copy word to temp
//strcpy(temp->line, line);//copy line to temp
temp->line=line;
temp->next = NULL; //set it to null


 if((*head) == NULL && (*tail) == NULL){ // check to see if head and tail are null;
	(*head)=temp;
	(*tail)=temp; //set them to newnode if they are null;
	return temp;
	//free(*head);
	}
  else{
   (*tail)->next = temp;
  (*tail)=temp;
	return temp;

  }
free(temp);
//free(line);


}


/**
 * Removes the specified node from the list, and frees all memory the node is using.
 * Remember that if *head or *tail are the node, they will need to be updated!
 */
void deleteNode(struct lnode **head, struct lnode **tail, struct lnode *node) {
    /* FILL THIS IN */

	struct lnode* temp;
	temp=(*head);
	struct lnode* temp2;
	temp2=(*tail);
	if(node==temp){
		(*head)=(*head)->next;
		if((*tail)==node){
			(*tail)=(*tail)->next;
		}
		//free(node);
	}
	else{
		while(temp->next!=node){
			temp=temp->next;
		}
		temp->next=node->next;
		if((*tail)==node){
			(*tail)=temp;
			//free(*tail);
		}
		//free(node);
  	}
  free(node);
  return 0;
}

/**
 * Simply returns the next node in the list, or NULL if there are no further nodes.
 */
struct lnode *nodeGetNext(struct lnode *node) {
    /* FILL THIS IN */
	struct lnode* temp;
	temp = node->next;
	return temp;
}

/**
 * Simply returns the word in the given node.
 */
char *nodeGetWord(struct lnode *node) {
    /* FILL THIS IN */
char* temp;
temp=node->word;
return temp;

}

/**
 * Simply returns the line in the given node.
 */
int nodeGetLine(struct lnode *node) {
    /* FILL THIS IN */
return node->line;
}

/**
 * Simply returns the count in the given node.
 */
int nodeGetCount(struct lnode *node) {
    /* FILL THIS IN */
int counter =1;
return (node->count = counter);
}

/**
 * Increments the count in the given node, and returns the new count.
 */
int nodeIncCount(struct lnode *node) {
    /* FILL THIS IN */
    int counter =1;
    if((node->count = counter)!='\0'){
    (node->count)++;
    }
    return node->count;
}

/**
 * If the linked list with *head and *tail as head and tail pointers contains
 * a node with the specified word, that node is returned, with its line updated
 * to the specified line. Otherwise, returns NULL.
 */
struct lnode *getNode(struct lnode **head, struct lnode **tail, char *word, int line) {
    /* FILL THIS IN */
    struct lnode* temp;
    temp=*head;
    if(strcmp(temp->word,word)==0 && temp!=NULL){
            temp->line=line;
            return temp;
        }
    if((temp=temp->next)!=NULL){
            if(strcmp(temp->word,word)==0){
                temp->line=line;
                return temp;
            }
    }
        temp=*tail;
    if(strcmp(temp->word,word)==0 && (*tail)!=NULL){
            temp->line=line;
            return temp;
        }
    else{
        return NULL;
    }
}

/**
 * Deletes every node in the list with *head and *tail as head and tail pointers.
 * After calling this function, all memory used by the list should be freed,
 * and *head and *tail should both be NULL.
 */
void deleteList(struct lnode **head, struct lnode **tail) {
    /* FILL THIS IN */
struct lnode* temp=*head;
if(temp != NULL){
      deleteNode(head, tail, temp->next);
    }
    *head = NULL;
    *tail = NULL;
free(*head);
free(*tail);
free (temp);
}
