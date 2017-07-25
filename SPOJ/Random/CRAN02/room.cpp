#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	long long t, n, num;
	long long count;
	long long sums[1000000];
	map<long long, long long> d;
	cin>>t;
	while(t--){
		d.clear();
		cin>>n;
		count = 0;
		scanf("%lld",&num);
		sums[0] = num;
		d[num] = 1;
		for(int i = 1; i < n; i++){
			scanf("%lld",&sums[i]);
			sums[i] += sums[i-1];
			d[sums[i]]++;
		}
		long long a,b;
		for(map<long long,long long>::iterator it = d.begin(); it != d.end(); it++){
			a = it->first;
			b = it->second;
			if(a != 0)count += b * (b-1) / 2;
			else count += b + (b * (b-1)/2 );	
		}
		cout<<count<<endl;
		
	}
	return 0;
}
