#include<stdio.h>
#include<stdlib.h>
struct node(
	char* symbol;
	double id;
	char side;
	int quantity;
	float price;
}
void addNewNode;
struct node* addNewNode (struct node *head, int n)
{
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = n;
    temp -> link = head;
    return temp;
}
int main(char** argv, int argc){

	int i=0;
	char* in = "-i";
	char* ou = "-o";
	char *fileop;
	char* outpu;
	for(i=0;i<argc;i++){
		if(strcmp(argv[i],in)==0){
			fileop = argv[i++]; 
		}
		if(strcmp(argv[i], ou)==0){
			outpu = aqrv[i++];
		}
	}
struct lnode* head = NULL;
if(fileop!=NULL){
	FILE* infile;
	infile = fopen(fileop, "r");
	if(infile !=NULL){
			if(ch == 'A'){
			//	struct lnode* store = (struct lnode *)malloc(sizeof(struct lnode));
				store->next = hashtable[store->id % 3000];
	   			fscanf(inputfile, "%ld %c %s %d %lf\n", &store->id, &store->side, &store->symbol, &store->quantity, &store->price);
				struct lnode* t = head;
				 while(t != NULL && t->next != NULL){
					t  = t->next;
		           	   }
		             	 if(t == NULL){
					head = store;
		              	 }
				 else{
					t->next = store;
				 }
					store->next = NULL;
					temp = store;

			}

		}
	}
}



}
	store2 = (struct lnode *)malloc(sizeof(struct lnode));
			store2->next= hashtable[store->id % 3000];
                                fscanf(inputfile, "%ld %s\n", &store2->id, &store2->symbol);
                                struct lnode* p = head;
                                struct lnode* prev=head;
                                while(p!=NULL){

                                    if(p->id==store2->id && prev != NULL){
                                        prev->next=p->next;
					free(p);
				//	printf("EXITING if X\n");
                                        break;
                                    }else if(p->id==store2->id && prev == NULL){
                                        head=p->next;
					free(p);
				//	printf("EXITING else if X\n");
                                        break;
                                    }
                                    prev = p;
                                    p = p->next;

                                }

