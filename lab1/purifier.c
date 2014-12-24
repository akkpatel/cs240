#include <stdio.h>

int main()
{
char words[300];
char rats[] = "darn";
char hell[] = "hell";
char damn[] = "fool";
char all[]= "darnhellfool";
char x[] = "XXXX";
int i =0;
int j =0;
int flag = 0;
scanf("%[^\n]s",words);
for(i=0;words[i]!='\0';i++){
    int index = i;
    for(j=0; rats[j] != '\0'; j++,i++){
        if(words[i]==rats[j] || words[i]==hell[j] || words[i]==damn[j] && words[i]!=all[j]){
            flag = 1;
        }else{
            flag = 0;
            break;
        }
    }
    if(isalpha(words[i])){
        flag = 0;
    }
    if(flag){
        int temp = 0;
        for(temp = 0; temp < 4; temp++,index++){
            words[index] = 'X';
        }
    }

}
printf("%s",words);
}



int isalpha(char c){

if(c > 'A' && c < 'Z' || c > 'a' && c < 'z')
    return 1;
return 0;
}
