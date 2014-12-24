#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void filereader(FILE* in, int bflag, char* sym, int n){
	FILE* iq = fopen("iq.txt", "w");
	FILE* ob = fopen("ob.txt", "w");
	int count = 0;
	if(!bflag){
		char ch;
		int id;
		while(!feof(in)){
			fscanf(in,"%c",&ch);
			if(ch == 'A'){
				char side;
				char* symbol = (char*)malloc(sizeof(char*));
				int quantity;
				double price; 
				fscanf(in,"%d %c %s %d %lf\n",&id, &side, symbol, &quantity, &price);
				if(!strcmp(sym,symbol)){
					hashAdd(id, side, symbol, quantity, price);
					//printf("%ld %c %s %d %lf\n", id, side, symbol, quantity, price);
					//count++;
				}
			}else if(ch == 'X'){
				char* symbol = (char*)malloc(sizeof(char*));
				fscanf(in,"%d %s\n",&id, symbol);
				hashDel(id);
			}else if(ch == 'T'){
				int id;
				char* symbol = (char*)malloc(sizeof(char*));
				int quantity;
				fscanf(in, "%d %s %d\n", &id, symbol, & quantity);
				if(!strcmp(sym,symbol)){
					changeNode(id, quantity);
				}
			}else if(ch == 'R'){
				int id;
				char* symbol = (char*)malloc(sizeof(char*));
				int quantity;
				double price;
				fscanf(in, "%d %s %d %lf\n", &id, symbol, &quantity, &price);
				changePnode(id, quantity, price);
			}else if(ch == 'C'){
				int id;
				char* symbol = (char*)malloc(sizeof(char*));
				int quantity;
				fscanf(in, "%d %s %d\n", &id, symbol, & quantity);
				if(!strcmp(sym,symbol)){
					changeNode(id, quantity);
				}

			}
			count++;
			//printf("count %d\n", count);
			//printf("n in file %d\n", n);
			if(count == n){
				count = 0;
				double sellPrice = 0.0;
				double buyPrice = 0.0;
				if(sell != NULL)
					sellPrice = sell->price;
				if(buy != NULL)
					buyPrice = buy->price;
				fprintf(iq, "%lf %lf\n", sellPrice, buyPrice);
			}

		}

	}else{
		char c;
		  while(!feof(in)){
			fread(&c, sizeof(char), 1,in);
			if(c == 'A'){
				int id;
				char side;
				char *symbol = (char *) malloc(sizeof(char *));
				int quantity;
				double price;
				fread(&id,sizeof(int),1,in);
				fread(&side,sizeof(char),1,in);
				fread(symbol,sizeof(char),4,in);
				symbol[strlen(symbol)] = '\0';
				fread(&quantity,sizeof(int),1,in);
				fread(&price,sizeof(double),1,in);
				if(!strcmp(sym,symbol)){
					hashAdd(id, side, symbol, quantity, price);
					//printf("%ld %c %s %d %lf\n", id, side, symbol, quantity, price);
				}
			}
			if(c == 'X'){
				int id;
				char *symbol = (char *) malloc(sizeof(char *));
				fread(&id,sizeof(int),1,in);
				fread(symbol,sizeof(char),4,in);
				symbol[strlen(symbol)] = '\0';
				hashDel(id);
			}
			
			if(c == 'T'){
				int id;
				char *symbol = (char *) malloc(sizeof(char *));
				int quantity;
				fread(&id,sizeof(int),1,in);
				fread(symbol,sizeof(char),4,in);
				symbol[strlen(symbol)] = '\0';
				fread(&quantity,sizeof(int),1,in);
				changeNode(id, quantity);				
			}
			if(c == 'C'){
				int id;
				char *symbol = (char *) malloc(sizeof(char *));
				int quantity;
				fread(&id,sizeof(int),1,in);
				fread(symbol,sizeof(char),4,in);
				symbol[strlen(symbol)] = '\0';
				fread(&quantity,sizeof(int),1,in);
				changeNode(id,quantity);
			}
			if(c == 'R'){
				int id;
				char *symbol = (char *) malloc(sizeof(char *));
				int quantity;
				double price;
				fread(&id,sizeof(int),1,in);
				fread(symbol,sizeof(char),4,in);
				symbol[strlen(symbol)] = '\0';
				fread(&quantity,sizeof(int),1,in);
				fread(&price,sizeof(double),1,in);
				changePnode(id, quantity, price);
			}
		}
	
	}
	printhash(ob);
}

int main(int argc, char** argv){
	FILE* in = stdin;
	int bflag = 0;
	int n = 1000;
	char* sym = (char *) malloc(sizeof(char*));
	int i;
	for(i = 1; i < argc; i++){
		if(!strcmp(argv[i], "-i"))
			in = fopen(argv[++i], "r");
		if(!strcmp(argv[i], "-b"))
			bflag = 1;
		if(!strcmp(argv[i], "-s"))
			strcpy(sym, argv[++i]);
		if(!strcmp(argv[i], "-n"))
			n = atoi(argv[++i]);
		//	printf("n in for %d\n", n);
	}
			//	printf("n %d\n", n);
//	hashInit();
	filereader(in, bflag, sym, n);
}

