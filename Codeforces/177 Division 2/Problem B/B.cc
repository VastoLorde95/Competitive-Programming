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

int n, m, d, a[100][100], res, cnt, tot, cur, prev;	
map<int, int> b;
int main(){
	sd3(n,m,d);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			sd(a[i][j]);
			b[a[i][j]]++;
		}
	}
	
	int x = a[0][0];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if( (a[i][j]-x)%d != 0 ){
				printf("-1\n");
				return 0;
			}
		}
	}
	
	cur = b.begin()->first;
	
	for(map<int, int>::iterator it = b.begin(); it != b.end(); it++){
		tot += ((it->first - cur)/d) * it->second;
	}	
	
	res = tot;
	
	map<int, int>::iterator it = b.begin();
	cnt = it->second;
	prev = it->first;
	it++;
	
	for(; it != b.end(); it++){
		tot = tot + ((it->first - prev)/d)*cnt - (n*m -cnt) * ( it->first - prev)/d;
		res = min(res, tot);
		prev = it->first;
		cnt += it->second;
	}	
	
	printf("%d\n",res);
	
	return 0;
}
