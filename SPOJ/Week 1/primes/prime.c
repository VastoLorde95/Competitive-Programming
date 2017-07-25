#include<stdio.h>
#include<math.h>
int is_prime(long long n, long primes[], int j){
	double root = sqrt(n);
	long long int i = 0;
	while(primes[i] <= root && i != j){
		if( n % primes[i] == 0 )
			return 0;
		++i;
	}
	
	return 1;
}
int main(){
	long primes[9592];
	int j = 0, N;
	scanf("%d",&N);
	long long int i;
	for (i = 2; i<=100000; i++){
		if(is_prime(i, primes, j)){
			primes[j++] = i;
		}
	}
	while(N--){
		long long int m, n;
		scanf("%lld %lld",&m, &n);
		if(m<2)
			m = 2;
		i = m;
		if(i%2 == 0)
			++i;
		while(i<=n){
			if(is_prime(i, primes, 9592)){
				printf("%lld\n", i);
			}
			++i;
		}
		printf("\n");
	
	}
	return 0;
}
