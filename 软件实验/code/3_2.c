#include <stdio.h>  
extern int cmpnum(int t1,int t2);
int main() { 
	int i,j,temp;   
	char  buffer[]={11,24,38,40,126,78,95,204,35,9,2,33,159,146,211,23,67,93,66,54};   
	
	for(j=0;j<20;j++){
		for(i=0;i<20-j-1;i++){
			if(cmpnum(buffer[i],buffer[i+1])<0){
				temp=buffer[i];
				buffer[i]=buffer[i+1];
				buffer[i+1]=temp;
			}
		}
	}   
	printf("the sorted numbers:\n");   
	for(i=0;i<20;i++)   
	printf("%d  ",buffer[i]); 
}