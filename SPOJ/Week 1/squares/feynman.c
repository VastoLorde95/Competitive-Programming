#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	while(n != 0){
		unsigned long total = 0;
		while(n > 0){
			total += n * n;
			--n;
		}
		printf("%lu\n", total);
		scanf("%d",&n);
	}
	return 0;
}
