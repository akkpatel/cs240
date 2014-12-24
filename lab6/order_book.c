#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

struct lnode {
	struct lnode* next;
	long id;
	char side;
	char symbol;
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

/*	int i;
	char *inname;
	char *outname;
	int hashflag = 0;
	for(i=0;i<3;i += 2){
		if(argv[i] = "-i"){
			inname = argv[i+1];
			printf(" inname %s", inname);
		}
		else if(argv[i] = "-o"){
			outname = argv[i+1];
		}
		else if(argv[i] = "-h"){
			hashflag = 1;
		}
	}
*/


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
                                fscanf(inputfile, "%ld %c %s %d %lf\n", &store->id, &store->side, &store->symbol, &store->quantity, &store->price);
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
				//printf("EXITING X\n");
                                break;
                        case 'T'://printf("CASE T\n");
                                point=(struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%ld %s %d\n", &point->id, &point->symbol, &point->quantity);
                                struct lnode* x = head;
                                while(x!=NULL){
                                    if(x->id==point->id){
                                        x->quantity = x->quantity - point->quantity;
					if(x->quantity==0){
						struct lnode* p = head;
				                struct lnode* prev=head;
				                while(p!=NULL){

				                    if(p->id==x->id && prev != NULL){
				                        prev->next=p->next;
							free(p);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(p->id==x->id && prev == NULL){
				                        head=p->next;
							free(p);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
				                    prev = p;
				                    p = p->next;

				                }
					}
				//	printf("EXITING while T\n");
                                        break;
                                    }
                                    x=x->next;
                                }
				//printf("EXITING T\n");
                                break;

                        case 'C'://printf("CASE C\n");
                                point2=(struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%ld %s %d\n",&point2->id, &point2->symbol, &point2->quantity);
                                 struct lnode* x1 = head;
				//				printf("outside While in C\n");
                                while(x1!=NULL){
				//					printf("inside while C\n");
                                    if(x1->id==point2->id){
                                      //  printf("%d ",x1->quantity);
                                        x1->quantity = x1->quantity - point2->quantity;
                                     	if(x->quantity==0){
						struct lnode* p = head;
				                struct lnode* prev=head;
				                while(p!=NULL){

				                    if(p->id==x->id && prev != NULL){
				                        prev->next=p->next;
							free(p);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(p->id==x->id && prev == NULL){
				                        head=p->next;
							free(p);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
				                    prev = p;
				                    p = p->next;

				                }
					}
				//	printf("EXITING while C\n");
                                        break;
                                    }
                                    x1=x1->next;
                                }
				//printf("EXITING C\n");
                                break;
                        case 'R'://printf("CASE R\n");
				point3=(struct lnode *)malloc(sizeof(struct lnode));
                                fscanf(inputfile, "%ld %s %d %lf\n",&point3->id, &point3->symbol, &point3->quantity, &point3->price);
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
                                scanf("%ld %c %s %d %lf\n", &store->id, &store->side, &store->symbol, &store->quantity, &store->price);
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
                                scanf("%ld %s\n", &store2->id, &store2->symbol);
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
				//printf("EXITING X\n");
                                break;
                        case 'T'://printf("CASE T\n");
                                point=(struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%ld %s %d\n", &point->id, &point->symbol, &point->quantity);
                                struct lnode* x = head;
                                while(x!=NULL){
                                    if(x->id==point->id){
                                        x->quantity = x->quantity - point->quantity;
				//	printf("EXITING while T\n");
					if(x->quantity==0){
						struct lnode* p = head;
				                struct lnode* prev=head;
				                while(p!=NULL){

				                    if(p->id==x->id && prev != NULL){
				                        prev->next=p->next;
							free(p);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(p->id==x->id && prev == NULL){
				                        head=p->next;
							free(p);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
				                    prev = p;
				                    p = p->next;

				                }
					}
                                        break;
                                    }
                                    x=x->next;
                                }
				//printf("EXITING T\n");
                                break;

                        case 'C'://printf("CASE C\n");
                                point2=(struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%ld %s %d\n",&point2->id, &point2->symbol, &point2->quantity);
                                 struct lnode* x1 = head;
				//				printf("outside While in C\n");
                                while(x1!=NULL){
				//					printf("inside while C\n");
                                    if(x1->id==point2->id){
                                      //  printf("%d ",x1->quantity);
                                        x1->quantity = x1->quantity - point2->quantity;
                                    	if(x->quantity==0){
						struct lnode* p = head;
				                struct lnode* prev=head;
				                while(p!=NULL){

				                    if(p->id==x->id && prev != NULL){
				                        prev->next=p->next;
							free(p);
						//	printf("EXITING if X\n");
				                        break;
				                    }else if(p->id==x->id && prev == NULL){
				                        head=p->next;
							free(p);
						//	printf("EXITING else if X\n");
				                        break;
				                    }
				                    prev = p;
				                    p = p->next;

				                }
					}
				//	printf("EXITING while C\n");
                                        break;
                                    }
                                    x1=x1->next;
                                }
				//printf("EXITING C\n");
                                break;
                        case 'R'://printf("CASE R\n");
				point3=(struct lnode *)malloc(sizeof(struct lnode));
                                scanf("%ld %s %d %lf\n",&point3->id, &point3->symbol, &point3->quantity, &point3->price);
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
                fprintf(outputfile,"%ld %c %d %lf\n", count->id, count->side, count->quantity, count->price);
                count=count->next;
            }
        }

    }else{
            struct lnode* count=head;
            while(count!=NULL){
                printf("%ld %c %d %lf", count->id, count->side, count->quantity, count->price);
                count=count->next;
            }
        }
    }
