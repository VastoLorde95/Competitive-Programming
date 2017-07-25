#include<iostream>
#include<cmath>
using namespace std;

long long A[10];
long long B[10];

void sum(long long N, long long a[], long long f){
    if(N/10==0){
        for(long long j=1;j<=N;j++)a[j]=a[j]+1;
    }
    else{
        long long i=0;
        long long n=N;
        while(n/10!=0){
            i++;
            n/=10;
        }
        long long p=pow(10,i);
        if(f==0) a[0]=a[0]-(p/10-1)*10/9+i;
        //else a[0]=a[0]+p*i/10;
        for(long long j=0;j<10;j++) a[j]=a[j]+p*i/10;
        for(long long j=0;j<10;j++) a[j]=a[j]+(n-1)*p*i/10;
        for(long long j=1;j<n;j++) a[j]=a[j]+p;
        a[n]=a[n]+ N%p +1;
        sum(N%p,a,1);
    }
}

int main(){
    long long a,b,t;
    cin>>a>>b;
    while(a!=0 || b!=0){
        if(a>b){t=b;b=a;a=t;}
        for(long long i=0;i<10;i++) A[i]=0;
        for(long long i=0;i<10;i++) B[i]=0;
        sum(a-1,A,0);
        sum(b,B,0);
        for(long long i=1;i<10;i++) cout<<B[i]-A[i]<< ' '; cout << endl;
        cin>>a>>b;
    }
    return 0;
}
