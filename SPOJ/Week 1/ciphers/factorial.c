#include<stdio.h>
#include<stdlib.h>
int main(){
	unsigned long long n;
	scanf("%llu",&n);
	unsigned long long samples [n];
	unsigned long long i = 0;
	while(i<n){
		scanf("%llu",&samples[i]);
		i++;
	}
	i = 0;
	while(i<n){
		unsigned long long num = samples[i];
		unsigned long long denom = 5;
		unsigned long long ciphers = 0;
		while(denom < num){
			ciphers += num/denom;
			denom *= 5;
		}
		printf("%lld\n",ciphers);
		i++;
	}
	return 0;
}
