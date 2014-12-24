#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "hash.h"
//#include "market.h"

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
	struct lnode* another = (struct lnode *)malloc(sizeof(struct lnode));
	//a.symbol = (char *) malloc(sizeof(char *));
	another->id = a.id;
	another->side = a.side;
	strcpy(another->symbol,a.symbol);
	another->quantity = a.quantity;
	another->price = a.price;
	another->next = NULL;
	another->newnext = NULL;
//	printf("id:%ld\n side:%c\n sym:%s\n quantity:%d\n price:%lf\n", another->id, another->side, another->symbol, another->quantity, another->price);
	int hashkey = hash(another->id);
	int buyprice = 0;
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
		}else{
			while(current!=NULL && another->price < current->price){
				prev = current;
				current = current->newnext;
			}
			prev->newnext = another;
			another->newnext = current;
		}
	}else if(another->side == 'S'){
		struct lnode* current = sell;
		struct lnode* prev = sell;
		if(sell == NULL){
			sell = another;
		}else{
			while(current!=NULL && another->price > current->price){
				prev = current;
				current = current->newnext;
			}
			prev->newnext = another;
			another->newnext = current;
		}
	}
 return 1;
}
struct lnode* searchNode(int id){
	struct lnode* current = hashtable[hash(id)];
	while(current!=NULL && current->id != id){
		 current = current->next;
	}
	if(current->id == id){
		return current;
	}else{
		return NULL;
	}
	
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
	struct lnode* current = hashtable[hashkey];
	if(current->next!=NULL){
		hashInit();
	}else{
		hashtable[hashkey] = current->next;
	}
}
