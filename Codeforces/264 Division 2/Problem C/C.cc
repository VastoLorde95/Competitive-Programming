#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;

int n, a[2000][2000];
long long s1[4000], s2[4000];

int main(){ _
	long long mx1 = -1, mx2 = -1;
	int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
	
	sd(n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sd(a[i][j]);
			s1[i+j] += a[i][j];
			s2[i-j+n-1] += a[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i+j)%2 == 0){
				if(s1[i+j] + s2[i-j+n-1] -a[i][j] > mx1){
					mx1 = s1[i+j] + s2[i-j+n-1] -a[i][j];
					x1 = i;
					y1 = j;
				}
			}
			else{
				if(s1[i+j] + s2[i-j+n-1] -a[i][j] > mx2){
					mx2 = s1[i+j] + s2[i-j+n-1] -a[i][j];
					x2 = i;
					y2 = j;
				}
			}
		}
	}
	
	printf("%I64d\n",mx1 + mx2);
	printf("%d %d %d %d\n", x1+1, y1+1, x2+1, y2+1);
	
	return 0;
}
