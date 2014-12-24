#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

struct lnode {
	struct lnode* next;
	int id;
	char side;
	char symbol[8];
	int quantity;
	double price;
};

int main(int argc, char** argv){
    
    //printf("STARTING ...\n");
    char* output_option="-o";
    char* input_option="-i";

    char* ifile;
    char* ofile;

    bool isInputFileGiven = false;
    bool isOutputfileGiven = false;
    char ch;

    struct lnode* head = NULL;
    struct lnode* temp;
    struct lnode* store;
    struct lnode* store2;
    struct lnode* store3;
    struct lnode* store4;
    struct lnode* point;
    struct lnode* point2;
    struct lnode* point3;
    if(argc<3){
	//printf("Arguments < 3\n");
        printf("usage %s\n",argv[0]);
        exit(0);
    }
    if(argc==3){
	//printf("Arguments = 3\n");
        isInputFileGiven = false;
        isOutputfileGiven = false;
    }
    if(argc==4){
	//printf("Arguments = 4\n");
        if(strcmp(argv[2],output_option) != 0){
	//	printf("Input file given\n");
            isInputFileGiven = true;
            isOutputfileGiven = false;
            ifile = argv[2];
        }else if(strcmp(argv[2],output_option) == 0){
	//	printf("Output file given\n");
            isInputFileGiven = false;
            isOutputfileGiven = true;
            ofile = argv[3];
        }
    }
    if(argc==5){
	//printf("Arguments = 5\nInput file given\n Output file given\n");
        isInputFileGiven = true;
        isOutputfileGiven = true;
        ifile = argv[2];
        ofile = argv[4];
    }





    if(isInputFileGiven){
        FILE *inputfile=fopen(ifile,"r");
            if(inputfile==0){
                printf("error\n");
            }
            else{
                while(!feof(inputfile)){
                    fscanf(inputfile,"%c",&ch);
   			//printf("SWITCHING...\n");
                    switch(ch){
                        case 'A'://printf("CASE A\n");
                                store = (struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%d %c %s %d %lf\n", &store->id, &store->side, &store->symbol, &store->quantity, &store->price);
                                struct lnode* t = head;
                                while(t != NULL && t->next != NULL){
                                    t  = t->next;
                                }
                                if(t == NULL){
                                    head = store;
                                }else{
                                    t->next = store;
                                }
                                store->next = NULL;
                                temp = store;
				//printf("EXITING A\n");
                                break;
                        case 'X'://printf("CASE X\n");
				store2 = (struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%d %s\n", &store2->id, &store2->symbol);
                                struct lnode* p = head;
                                struct lnode* prev0=NULL;
                                while(p!=NULL){

                                    if(p->id==store2->id && prev0 != NULL){
                                        prev0->next=p->next;
					free(p);
				//	printf("EXITING if X\n");
                                        break;
                                    }else if(p->id==store2->id && prev0 == NULL){
                                        head=p->next;
					free(p);
				//	printf("EXITING else if X\n");
                                        break;
                                    }
                                    prev0 = p;
                                    p = p->next;

                                }
				//printf("EXITING X\n");
                                break;
                        case 'T'://printf("CASE T\n");
                                point=(struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%d %s %d\n", &point->id, &point->symbol, &point->quantity);
                                struct lnode* x = head;
				struct lnode* prev=NULL;
                                while(x!=NULL){
                                    if(x->id==point->id){
                                        x->quantity = x->quantity - point->quantity;
					if(x->quantity<=0){
						   if(prev != NULL){
				                        prev->next=x->next;
							free(x);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(prev == NULL){
				                        head=x->next;
							free(x);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
				                    
					}
				//	printf("EXITING while T\n");
                                        break;
                                    }
				    prev=x;
                                    x=x->next;
                                }
				//printf("EXITING T\n");
                                break;

                        case 'C'://printf("CASE C\n");
                                point2=(struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%d %s %d\n",&point2->id, &point2->symbol, &point2->quantity);
                                struct lnode* x1 = head;
				struct lnode* prev1=NULL;
                                while(x1!=NULL){
				//					printf("inside while C\n");
                                    if(x1->id==point2->id){
                                      //  printf("%d ",x1->quantity);
                                        x1->quantity = x1->quantity - point2->quantity;
                                    	if(x1->quantity<=0){
						  if(prev1 != NULL){
				                        prev1->next=x1->next;
							free(x1);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(prev1 == NULL){
				                        head=x1->next;
							free(x1);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
					}
				//	printf("EXITING while C\n");
                                        break;
                                    }
				    prev1 = x1;
                                    x1=x1->next;
                                }
				//printf("EXITING C\n");
                                break;
                        case 'R'://printf("CASE R\n");
				point3=(struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%d %s %d %lf\n",&point3->id, &point3->symbol, &point3->quantity, &point3->price);
                                struct lnode* y=head;
                                while(y!=NULL){
                                    if(y->id==point3->id){
                                        y->quantity=point3->quantity;
                                        y->price=point3->price;
				//	printf("EXITING while R\n");
                                        break;
                                    }
                                    y=y->next;
                                }
				//printf("EXITING R\n");
                                break;

                        }
                }
//		printf("End of File\n");
            }
	fclose(inputfile);
    }
    else{
	char c;
	//scanf("%d",&c);
	while((c = getchar())!=EOF){		
                    
   			//printf("SWITCHING...\n");
			
                    switch(c){
                        case 'A'://printf("CASE A\n");
                                store = (struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%d %c %s %d %lf", &store->id, &store->side, &store->symbol, &store->quantity, &store->price);
                                struct lnode* t = head;
                                while(t != NULL && t->next != NULL){
                                    t  = t->next;
                                }
                                if(t == NULL){
                                    head = store;
                                }else{
                                    t->next = store;
                                }
                                store->next = NULL;
                                temp = store;
				//printf("EXITING A\n");
                                break;
                        case 'X'://printf("CASE X\n");
				store2 = (struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%d %s", &store2->id, &store2->symbol);
                                struct lnode* p = head;
                                struct lnode* prev0=NULL;
                                while(p!=NULL){

                                    if(p->id==store2->id && prev0 != NULL){
                                        prev0->next=p->next;
					free(p);
				//	printf("EXITING if X\n");
                                        break;
                                    }else if(p->id==store2->id && prev0 == NULL){
                                        head=p->next;
					free(p);
				//	printf("EXITING else if X\n");
                                        break;
                                    }
                                    prev0 = p;
                                    p = p->next;

                                }
				//printf("EXITING X\n");
                                break;
                        case 'T'://printf("CASE T\n");
                                point=(struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%d %s %d", &point->id, &point->symbol, &point->quantity);
                                struct lnode* x = head;
				struct lnode* prev=NULL;
                                while(x!=NULL){
                                    if(x->id==point->id){
                                        x->quantity = x->quantity - point->quantity;
				//	printf("EXITING while T\n");
					if(x->quantity<=0){
						    if(prev != NULL){
				                        prev->next=x->next;
							free(x);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(prev == NULL){
				                        head=x->next;
							free(x);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
					}
                                        break;
                                    }
				    prev=x;
                                    x=x->next;
                                }
				//printf("EXITING T\n");
                                break;

                        case 'C'://printf("CASE C\n");
                                point2=(struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%d %s %d",&point2->id, &point2->symbol, &point2->quantity);
                                 struct lnode* x1 = head;
				struct lnode* prev1=NULL;
                                while(x1!=NULL){
				//					printf("inside while C\n");
                                    if(x1->id==point2->id){
                                      //  printf("%d ",x1->quantity);
                                        x1->quantity = x1->quantity - point2->quantity;
                                    	if(x1->quantity<=0){
						  if(prev1 != NULL){
				                        prev1->next=x1->next;
							free(x1);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(prev1 == NULL){
				                        head=x1->next;
							free(x1);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
					}
				//	printf("EXITING while C\n");
                                        break;
                                    }
				    prev1 = x1;
                                    x1=x1->next;
                                }
				//printf("EXITING C\n");
                                break;
                        case 'R'://printf("CASE R\n");
				point3=(struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%d %s %d %lf",&point3->id, &point3->symbol, &point3->quantity, &point3->price);
                                struct lnode* y=head;
                                while(y!=NULL){
                                    if(y->id==point3->id){
                                        y->quantity=point3->quantity;
                                        y->price=point3->price;
				//	printf("EXITING while R\n");
                                        break;
                                    }
                                    y=y->next;
                                }
				//printf("EXITING R\n");
                                break;

                        }
			
                }

            


    }

    if(isOutputfileGiven){
            FILE *outputfile =fopen(ofile,"w+");
            if(outputfile==0){
                printf("error\n");
            }
            else{
                struct lnode* count=head;
            while(count!=NULL){
                fprintf(outputfile,"%d %c %d %lf\n", count->id, count->side, count->quantity, count->price);
                count=count->next;
            }
        }

    }else{
            struct lnode* count=head;
            while(count!=NULL){
                printf("%d %c %d %lf", count->id, count->side, count->quantity, count->price);
                count=count->next;
            }
        }
    }
