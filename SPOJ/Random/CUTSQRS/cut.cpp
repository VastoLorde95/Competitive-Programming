#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

bool isgood(int a,int b)
{
int n;
if(b%a)
{
n=b/a;
if(n>1) return 1;
return (1-isgood(b-a,a));
}
return 1;
}


long long total_moves(int a, int b){
	long long count = 0, temp;
	while(a != 0 ){
		count += (int)b/a-1;
		temp = b%a;
		b = a;
		a = temp;
		}
	return count;
	}

int main(){
	int t, a, b, j, k;
	long double p=log10((double)2),m;
	sd(t);
	while(t--){
		j = 0;
		sd2(a,b);
		k=total_moves(a,b);
		m=k*p;
		j+=(int)m+1;
		if(k) m=(k-1)*p;
		else m=0;
		j+=(int)m+1;
		j+=isgood(a,b)?5:6;
		cout<<j<<"\n";
		}
	return 0;
	}
