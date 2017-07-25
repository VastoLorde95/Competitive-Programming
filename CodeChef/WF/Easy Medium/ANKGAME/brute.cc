using namespace std;
	#include <stdio.h>
    #include <stdlib.h>
    #include <algorithm>
    #define mod 1000000007
    #define lim 100010
    long int fact[lim],invfact[lim];
    long long abso(long long i){
    	if(i>=0) return i%mod;
    	return (i%mod+mod)%mod;
	}
    long long int powermod(long int x, long int y)
    {
        long long int temp;
        if( y == 0)
            return 1;
        temp = powermod(x, y/2);
        if (y%2 == 0)
            return (temp*temp)%mod;
        else
            return (((x*temp)%mod)*temp)%mod;
    }
    void fac(){
    	long int i=0;
    	fact[0]=1; invfact[0]=1;
    	for(i=1;i<lim;i++){
    		fact[i]=((long long int)fact[i-1]*i)%mod;
    	}
    	for(i=1;i<lim;i++){
    		invfact[i]=powermod(fact[i],mod-2);
    	}
    }
    int main(){
    	int t;
    	long n,i,j,count[lim];
    	long long int a[lim];
    	fac();
    	scanf("%d",&t);
    	while(t--){
    		scanf("%ld",&n);
    		for(i=0;i<n;i++)
    			scanf("%lld",&a[i]);
    		sort(a,a+n);
    		count[0]=1;
    		j=0;
    		for(i=0 ;i<n-1;i++){
    			if(a[i]==a[i+1]){
    				count[j]++;
    			}
    			else{
    				j++;
    				count[j]=1;
    			}
    		}
    		long int countsize=j+1;
    		int flag=0;
    		long count0=0;
    		if(a[0]==1 ){
    			flag=1;
    			count0=count[0];
    		}
    		else count0=0;
    		if(count0==n){
    			if(n%2==0)
    			   printf("0\n");
    			else printf("1\n");
    			continue;
    		}
    		long long den=1;
    		long long ans=0;
    		for(i=flag;i<countsize;i++){
    			den=(den*invfact[count[i]])%mod;
    		}
    		for(i=0;i<=count0;i=i+2){
    			long o=count0-i;
    			long k=n-i;
    			if(o==0){
    				ans+=(fact[k]*den)%mod;
    				ans=ans%mod;
    				continue;
    			}
    			ans+= abso(((long long)fact[k]*invfact[o])-((long long)fact[k-1]*invfact[o-1]))*den ;
    			ans=ans%mod;
    		}
    		printf("%lld\n",ans);
    	}
    	return 0;
    }  
