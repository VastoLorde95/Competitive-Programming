#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int MOD=1000000007;

long long expo1(long long a, long long b){
	long long res = 1, p = MOD-1;
	//a = a%p;
	while(b>0){
		if(b&1) res = (res*a)%p;
		a = (a*a)%p;
		b >>= 1;
	}
	return res;
}

long long expo2(long long a, long long b){
	long long res = 1, p =MOD;
	//a = a%p;
	while(b>0){
		if(b&1) res = (res*a)%p;
		a = (a*a)%p;
		b >>= 1;
	}
	return res;
}


int main(){
	int a,b,c, res;
	scanf("%d %d %d",&a,&b,&c);
	while(a != -1){
		if(a%MOD != 0){
			res = expo1(b,c);
			res = expo2(a,res);
		}
		else{
			if(b == 0 && c != 0)
				res = 1;
			else 
				res = 0;
		}
		
		printf("%d\n",res);
		scanf("%d %d %d",&a,&b,&c);
	}
	return 0;
}

