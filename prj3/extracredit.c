#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sea_animal{
	char name[20];
	int age;
	double weight;
	void (*eat)(struct sea_animal*);
	void (*swim)(struct sea_animal*,int hours);
};

void readline(char c[]){ 
	int i=0; 
	while((c[i++]=getchar())!='\n'); 
				c[i-1]='\0'; 
}

void whale_eat(struct sea_animal* this){
	double wGain;
	wGain = 0.05*(this->weight);
	if((this->weight)*1.05 <= 400000.00){
		(this->weight) *=1.05;
		printf("%s happily ate %.2lf pounds of food. Its weight is now %.2lf pounds.\n",(this->name),wGain,(this->weight));
	}else{
		printf("%s is too fat.\n", (this->name));
	}
}

void whale_swim(struct sea_animal* this, int hours){
	printf("%s happily swam %.2lf miles.\n",(this->name),(3*(this->age)*(200000/(this->weight)))*hours);
}

void shark_eat(struct sea_animal* this){
	double wGain;
	wGain = 0.1*(this->weight);
	if((this->weight)*1.1 <= 2000.00){
		(this->weight) *= 1.01;
		printf("%s happily ate %.2lf pounds of food. Its weight is now %.2lf pounds.\n",(this->name),wGain,(this->weight));
	}else{
		printf("%s is too fat.\n", (this->name));
	}
}

void shark_swim(struct sea_animal* this, int hours){
	printf("%s happily swam %.2lf miles.\n",(this->name),(10*(this->age)*(1000/(this->weight)))*hours);
}

struct sea_animal* whale_new(char *name, int age, double weight){
	struct sea_animal *new_whale = malloc(sizeof(struct sea_animal));
	strncpy(new_whale->name,name,20);
	new_whale->name[20] = '\0';
	new_whale->age = age;
	new_whale->weight = weight;
	new_whale->eat = whale_eat;
	new_whale->swim = whale_swim;
	return new_whale;
}

struct sea_animal* shark_new(char *name, int age, double weight){
	struct sea_animal *new_shark = malloc(sizeof(struct sea_animal));
	strncpy(new_shark->name,name,20);
	new_shark->name[20] = '\0';
	new_shark->age = age;
	new_shark->weight = weight;
	new_shark->eat = shark_eat;
	new_shark->swim = shark_swim;
	return new_shark;
}

int main(int argc, char *argv[]){
	char pet[1];
	char name[20];
	char age_Str[4];	
	char weight_Str[20];
	double weight;
	char temp;
	int age;
	char hour_str[20];
	int hours;
	
	printf("Create your new pet, whale or shark? (w/s):");
	readline(pet);
	printf("Pet's Name : ");
	readline(name);
	printf("Age : ");
	readline(age_Str);
	age = atoi(age_Str);
	printf("Weight : ");
	readline(weight_Str);
	weight = atol(weight_Str);

	struct sea_animal *new_pet = NULL;
	if(pet[0] == 'w'){
		new_pet = whale_new(name,age,weight);
	}else if(pet[0] == 's'){
	 new_pet = shark_new(name,age,weight);
	}
	printf("Pet Created!\n");
	char input;
	char hoursS[3];
	while(input != '3'){
		printf("\nHave fun with your new pet %s\n",name);
		printf("1.Feed\n");
		printf("2.Walk\n");
		printf("3.Play later\n");
		printf("Input: ");
		input = getchar();
		
		while((temp = getchar()) != '\n');
	 		if(input == '1') {
				((new_pet->eat))(new_pet);
			}else if(input == '2') {
			 char hoursS[3];
				 printf("For how many hours?: ");
				 readline(hoursS);
				 hours = atoi(hoursS);
				 ((new_pet->swim))(new_pet,hours);						 
			 }
		}
	if(input == '3'){
		printf("Quit\n");
	}				 
	return 0;
}
