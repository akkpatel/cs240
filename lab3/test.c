#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "list.h"

struct lnode {
 char *word;
 int line;
 int count;
 struct lnode *prev;
 struct lnode *next;
};

void deleteNode(struct lnode **head, struct lnode **tail, struct lnode *node) {
printf("IN DELETENODE\n");
printf("HMMM: %p\n", node);
	if((*head) == node){
		printf("Inside IF\n");
		(*head) = node->next;
		//free((node->word));
		//free(node);
		printf("free\n");
	}else if(((*tail) == node)){
		printf("Inside ELSEIF 0\n");
		(*tail)=(node->prev);
		free((node->word));
		free(node);
}else if((node->next) != NULL){
printf("Inside ELSEIF 1\n");
printf("Lets see: %p\n", node);
printf("That word: %p\n", (node->word));
((node->next)->prev)=(node->prev);
((node->prev)->next)=(node->next);
printf("Before free\n");
free((node->word));
printf("The word: %p\n", (node->word));
free(node);
printf("Lets see: %p\n", node);
}else if((node->prev) != NULL){
printf("Inside ELSEIF 2\n");
((node->prev)->next)=(node->next);
((node->next)->prev)=(node->prev);
free((node->word));
free(node);
}
}

/**
 * In the linked list with *head and *tail as head and tail pointers,
 * add a newly-created node to the tail of the list. The new node has
 * the given word and line, and a count of 1. You must duplicate word,
 * as the original word may be modified by the calling function. Return
 * value is the newly-created node.
 */

//void deleteNode(struct lnode **head, struct lnode **tail, struct lnode *node) {
    /* FILL THIS IN */
/*	struct lnode* temp;
	temp=(*head);
	printf("deletenode started\n");
	if(node==temp){
		printf("inside if\n");	
		(*head)=(head)->next;
		printf("head->next\n");	
		if((*tail)==node){
			(tail)=(tail)->next;
			printf("tail->next\n");
		}
		//free(node);
	}
	else{
		while(temp->next!=node){
			temp=temp->next;
			printf("in while\n");
		}
		temp->next=node->next;
		if((*tail)==node){
			(*tail)=temp;
			printf("tail==temp\n");
			//free(*tail);
		}
		//free(node);
  	}*/
	/*if((*head)==NULL && (node)==NULL){
		return;
	}
	if((*head)==node){
		(*head) = node->next;
		delete(node);
	}
	if((*tail)==node){
		(*tail)=node->next;
	}
	if((node->next)!= NULL){
		node->next->prev = node->prev;
	}
	if((node->prev) != NULL){
		node->prev->next = node->next;
	}*/
//}

int main(){
printf("Start\n");
 struct lnode *head=NULL;
 struct lnode *tail=NULL;
 struct lnode *node;
//node=getNode(&head,&tail,"f",1);
printf("getnode is fine\n");
deleteNode(&head,&tail,node);
printf("deltenode is fine\n");
return 0;
}
