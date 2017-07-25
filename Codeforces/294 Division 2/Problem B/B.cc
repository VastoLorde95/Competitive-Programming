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
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

map<int, int> a, b;
int n, x, f, s;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(x);
		if(a.find(x) == a.end())
			a[x] = 1;
		else{
			a[x] += 1;
		}	
	}
	for(int i = 0; i < n-1; i++){
		sd(x);
		if(b.find(x) == b.end())
			b[x] = 1;
		else
			b[x] += 1;
		if(a.find(x) != a.end()){
			a[x]--;
			if(a[x] == 0)
				a.erase(x);
		}
	}
	
	f = (a.begin())->first;
	
	for(int i = 0; i < n-2; i++){
		sd(x);
		if(b.find(x) != b.end()){
			b[x]--;
			if(b[x] == 0)
				b.erase(x);
		}
	}	
	
	s = (b.begin())->first;
	cout<<f<<"\n"<<s<<endl;
	
	return 0;
}
	
