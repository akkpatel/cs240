#include<stdio.h>
#include<stdlib.h>


int count = 10000000;

int main(){
  int i; 
  int rep;
  int res;
  int* buf=(int*)malloc(10000000 * sizeof(int));
	buf[count];
//  buf[count];
  for(i=0;i<count;i++){
	buf[i]=i;
  }
  res =0;
  for(rep=0;rep<10;rep++){
	for(i=0;i<count;i++){
		res += buf[i];
	}
  }
 printf("%d\n",res);
}
