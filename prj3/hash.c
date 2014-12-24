#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "hash.h"
//#include "market.h"

double GlobalVariable;
double lowprice;
struct lnode* head = NULL;
struct lnode* tail = NULL;

int hash(int id){
	int key = (id % SIZE);
	return key;
}
void hashInit(){
	int i;
	for(i=0; i<SIZE;i++){
		hashtable[i] = NULL;
	}
}
int hashAdd(struct A a){
	//printf("in hashad\n");
	struct lnode* another = (struct lnode *)malloc(sizeof(struct lnode));
	another->id = a.id;
	another->side = a.side;
	another->quantity = a.quantity;
	another->price = a.price;
	another->next = NULL;
	another->newnext = NULL;
	int hashkey = hash(another->id);
	int buyprice = 0;
/*	struct lnode* current;
	current = head;
	struct lnode* prev;
	while(current != NULL && current->next != NULL){
	   current  = current->next;
	   if(current->next != prev){
	       prev= current->next;
	       prev = another;
	   }
        }
        if(current == NULL){
	     head = another;
        }else{
		current->next = another;
		prev = another;
	}	
	prev = tail;
	another->next = prev;
	printf("%d %c %d %lf\n", another->id, another->side, another->quantity, another->price);*/
	if(hashtable[hashkey] !=NULL){
		struct lnode* current = hashtable[hashkey];
		while(current!=NULL){
			current = current->next;
		}
		current->next = another;
	}else{
		hashtable[hashkey] = another;
	}
	if(another->side == 'B'){
		struct lnode* current = buy;
		struct lnode* prev = buy;
		if(buy == NULL ){
			buy = another;
			GlobalVariable = another->price;
		}else{
			while(current!=NULL && another->price < current->price){
				prev = current;
				current = current->newnext;
			}
			prev->newnext = another;
			another->newnext = current;
			GlobalVariable = another->price;
		//	printf("%lf ", GlobalVariable);
		}
	//	printf("another->side == b\n");
	}else if(another->side == 'S'){
		struct lnode* current = sell;
		struct lnode* prev = sell;
		if(sell == NULL){
			sell = another;
			lowprice = another->price;
		}else{
			while(current!=NULL && another->price > current->price){
				prev = current;
				current = current->newnext;
			}
			prev->newnext = another;
			another->newnext = current;
			lowprice = another->price;
		}
	//	printf("another->side = S\n");
	}
//	printf("exiting hash\n");
 return 1;
}
struct lnode* searchNode(int id){
	struct lnode* current=head;// = hashtable[hash(id)];
	while(current!=NULL && current->id != id){
		 current = current->next;
	}
	if(current->id == id){
		return current;
	}else{
		return NULL;
	}
/*	current = head;
	while(current!=NULL){
		if(current->id == id){
			return current;
		}else{
			current = current->next;
		}	
	}*/
	
}

int changeNode(struct TC t){
	struct lnode* current;
	current = searchNode(t.id);
	struct lnode* change = (struct lnode *)malloc(sizeof(struct lnode));
	change->id = t.id;
	change->quantity = t.quantity;
//	printf("id:%ld\n sym:%s\n quantity:%d\n", change->id, change->symbol, change->quantity);
	while(current!=NULL){
		if(current->id == change->id){
			current->quantity = current->quantity - change->quantity;
			/*if(current->quantity==0){
				//hashDel();
				break;
			}*/
			break;
		}
		current = current->next;
	}

}
int changePnode(struct R r){
	struct lnode* current = searchNode(r.id);
	struct lnode* change = (struct lnode *)malloc(sizeof(struct lnode));
	change->id = r.id;
	change->quantity = r.quantity;
	change->price = r.price;
	while(current!=NULL){
		if(current->id == change->id){
			current->quantity = change->quantity;
			current->price = change->price;
			break;
		}
		current = current->next;
	}
}
void printhash(FILE* ob){
	int i;
	for(i=0;i<SIZE;i++){
		struct lnode* current = hashtable[i];
		while(current!=NULL){
			fprintf(ob,"%ld %c %d %lf\n", current->id, current->side, current->quantity, current->price);
			current = current->next;
		}
	}
}

void hashDel(struct X x){
	struct lnode* another = (struct lnode *)malloc(sizeof(struct lnode));
	another->id = x.id;
	int hashkey = hash(another->id);
	struct lnode* current=head; //= hashtable[hashkey];
	if(current->next!=NULL){
		hashInit();
	}else{
		head = current->next;
	}
}
