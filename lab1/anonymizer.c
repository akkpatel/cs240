#include <stdio.h>


int main(){

	char username[300];
	char tempsentence[300];
	int count=0;
	int i=0 ;
	int counter = 0;
	int temp;
	char d;
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


	gets(username);
	char c ;
/*	while((c=getchar())!= NULL  )
//	{
		username[i]=c;
		printf("%s\n",username);*/
	//printf("%s\n",username); 
	    while ( username[i]!= NULL)
	    {
		//printf("%c\n",username[i]);
	   	 if( username[i] == 64)
	  	  {
			temp = i-1;
			d = username[temp];
				while(temp >-1 && !(isAlpha(d)==0) && username[temp] != 32 )
				{
				    username[temp]= 88;
				    d=username[temp-1];
				    --temp;
	    			}
	    		
		}
		i++;
	  }
	printf("%s",username); 
}

