#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<stack>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);
#define fi first
#define se second
#define pb(x) push_back(x)

using namespace std;

int n, m, a, b, cnt, label[101], cycle[101], size[101];

int find(int x){
	return x == label[x] ? x: label[x] = find(label[x]);
}

void merge(int x, int y){
	cycle[find(x)] |= cycle[find(y)];
	label[find(x)] = label[find(y)];
	return;
}

int main(){
	sd2(n,m);
	
	for(int i = 1; i <= n; i++){
		label[i] = i;
	}
	
	for(int i = 0; i < m; i++){
		sd2(a,b);
		if(find(a) == find(b)){
			cycle[find(a)] = 1;
		}
		else{
			merge(a,b);
		}
	}
	
	for(int i = 1; i <= n; i++){
		size[find(i)]++;
	}
	
	for(int i = 1; i <= n; i++){
		if(find(i) == i){
			if(cycle[i] == 1 and size[i]%2 == 1) cnt++;
		}
	}
	
	if( (n-cnt)%2 == 1) cnt++;
	
	cout<< cnt << endl;
	
	return 0;
}
