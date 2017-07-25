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

int n, m, k, pos[100001], icon[100001], a;	//what is present at that position, ith icon is at which position
long long cnt;

int main(){
	sd3(n,m,k);
	for(int i = 1; i <= n; i++){
		sd(a);
		pos[i] = a;
		icon[a] = i;
	}
	
	for(int i = 0; i < m; i++){
		sd(a);
		if(icon[a]%k == 0) 
			cnt += (icon[a]/k);
		else
			cnt += (icon[a]/k + 1);
		if(icon[a] != 1){
			//swap pos[icon[a]] with pos[icon[a] - 1]
			icon[pos[icon[a]-1]]++;
			icon[a]--;
			swap(pos[icon[a]], pos[icon[a]+1]);
		}
	}
	
	printf("%I64d\n", cnt);
	return 0;
}
