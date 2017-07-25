#include<stdio.h>
#include<set>
using namespace std;
long long MOD = 2147483648;
int primes[4800],k;
set<long long> d;
int is_prime(long long num){
	int i;
	for(i = 0; i < k; i++){
		if((num % primes[i]) == 0){
			return 0;
		}
	}
	return 1;
}
int main(){
	int i, j;
	primes[0] = 2;
	d.insert(2);
	k = 1;
	for(i = 3; i <= 46340; i+=2){
		if(is_prime(i)){
			primes[k] = i;
			d.insert(i);
			k++;
		}
	}
	//for(i = 0; i <k; i++)
	//	printf("%d\n",primes[i]);
	long long a = 1;
	for( i = 1; i <= 500000; i++){
		if(d.find(a) != d.end())
			printf("1");
		else if(a == 0 || a == 1)
			printf("0");
		else if(is_prime(a) == 1){
			d.insert(a);
			printf("1");
			}
		else
			printf("0");
		a = (a+1234567890)%MOD;
	}
	return 0;
}





