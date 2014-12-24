#include <stdio.h>
#include<stdlib.h>
struct lnode {
struct lnode* next;
long value;
};

struct lnode *error(struct lnode *head){
	struct lnode* temp;
	temp=(struct lnode *)malloc(sizeof(struct lnode));
//	temp->next=NULL;
	if(temp !=NULL){
	temp->next=(head);
	}
	else{
	exit(0);
	}
if(head==NULL){
	int counter=1;
	temp->value=counter;
}
else{
	temp->value=(head->value) + 1;
}
}

int main(){
struct lnode *cur;
cur=(struct lnode *)malloc(sizeof(struct lnode));
int d=1;
while(d){
	cur = error(cur);
	if(((cur->value)%100000)==0){
		printf("%ld\n",cur->value);

	}

   }
}
