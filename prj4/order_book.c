#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include <pthread.h>
#include "market.h"

struct prediction get_prediction(){

}

int main(int argc, char** argv){
	FILE* in = stdin;
	int tflag = 0;
	char* sym = (char *) malloc(sizeof(char*));
	char action;
	int i;
	int n = 14;
	int m = 3;
	int index = 0;
	unsigned int length;
	int trd;
	for(i = 1; i < argc; i++){
		if(!strcmp(argv[i], "-i"))
			in = fopen(argv[++i], "r");
		if(!strcmp(argv[i], "-s"))
			strcpy(sym, argv[++i]);
		if(!strcmp(argv[i], "-n"))
			n = atoi(argv[++i]);
		if(!strcmp(argv[i], "-t"))
			tflag = 1;
		if(!strcmp(argv[i], "-m"))
			m = atoi(argv[++i]);
	}

	init_market(in, sym);
	pthread_t threads;
	trd = pthread_create(&threads, NULL, market, NULL);
	if(trd == 1){
		fprintf(stderr, "can not create thread\n");
	}else{
		char* buffer;
		while(1){
			buffer = get_inputs(&length);
			if(length == 0){
				break;
			}
			while(length!= 0){
			//	action = (*buffer);
				memcpy(&action,buffer,sizeof(char));
				buffer++;
				if(action == 'A'){
					struct A a;
					memcpy(&a,buffer,sizeof(struct A));
					buffer += sizeof(struct A);
					hashAdd(a);
					//printf("%d %c %s %d %lf\n", a.id, a.side, a.symbol, a.quantity, a.price);
				}
				if(action == 'X'){
					printf("found X\n");
				}
				if(action == 'R'){
					printf("found R\n");
				}
				if(action == 'C'){
					printf("found C\n");
				}
				if(action == 'T'){
					printf("found T\n");
					break;
				}
				index++;

			}
		}
		
	}
	
}
