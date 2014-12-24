#include <stdio.h>
int isAlpha(char d){
	    if(d>= 'A' && d<='Z'|| d>= 'a' && d<= 'z' || d>= '0' && d<='9')
	    {
		return 1;
	    }
	    else
	    {
		return 0;
	    }
}


int main(){
	char username[140];
	char tempsentence[300];
	int count=0;
	int i=0 ;
	int j=1;
	int counter = 0;
	char c;
	char e;
	while((c=getchar())!=EOF){
		username[i]=c;
		//printf("%s", username);
		if(username[i]=='@'){
				count = i-1;
				//printf("count %d\n", count);
				e= username[count];
				while(count>-1 && !(isAlpha(e)==0) && username[count]!=32){
					username[count]=88;
					e=username[count-1];
					--count;
				}
			}
		i++;

	}
		printf("%s", username);
}

	
