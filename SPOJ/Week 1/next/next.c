#include<stdio.h>
int main(){
	long a,b,c;
	scanf("%ld %ld %ld",&a, &b, &c);
	while(a != 0, b != 0, c != 0){
		long temp = c-b;
		if(temp == b-a){
			printf("AP %ld\n", c + temp);
		}
		else{
			printf("GP %ld\n",c * (b/a));
		}
		scanf("%ld %ld %ld",&a, &b, &c);
	}	
	return 0;
}
	
