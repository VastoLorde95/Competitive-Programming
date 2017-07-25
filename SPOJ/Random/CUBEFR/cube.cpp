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

int num[1000001];
vector<int> v;

int main(){
	int a, b, t, n;
	for(int i = 2; i <= 100; i++){
		a = i*i*i;
		b = a;
		while(b <= 1000000){
			num[b] = 1;
			b += a;
		}
	} 
	for(int i = 1; i <= 1000000; i++){
		if(!num[i])
			v.push_back(i);		
	}
	//cout<<v.size()<<endl;
	sd(t);
	for(int j = 1; j <=t; j++){
		sd(n);
		if(!num[n]){
			cout<<"Case "<<j<<": "<<lower_bound(v.begin(), v.end(), n) - v.begin() + 1<<endl; 
		}
		else{
			printf("Case %d: Not Cube Free\n", j);
		}
	}	
}
