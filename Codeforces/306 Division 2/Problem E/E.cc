#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n;
int a[100100];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	if(a[n-1] == 1){
		puts("NO"); return 0;
	}
	
	if(n == 1){
		if(a[0] == 0){
			puts("YES");
			cout << 0 << endl;
		}
		else puts("NO");
		return 0;
	}
	
	if(a[n-2] == 1){
		puts("YES");
		for(int i = 0; i < n-1; i++){
			printf("%d->",a[i]);
		}
		printf("%d\n", a[n-1]);
		return 0;
	}
	else{
		if(n == 2){
			puts("NO"); return 0;
		}	
		
		if(a[n-3] == 1){
			int i = n-4;
			while(i >= 0 and a[i] == 1) i--;
			
			if(i < 0){
				puts("NO"); return 0;
			}
			else{
				puts("YES");
				for(int j = 0; j < i; j++){
					printf("%d->", a[j]);
				}
				printf("(0->(");
				for(int j = i+1; j < n-2; j++){
					printf("%d->", a[j]);
				}
				printf("0))->0\n");
				return 0;
			}
		}
		
		puts("YES");
		for(int i = 0; i < n-3; i++){
			printf("%d->",a[i]);
		}
		printf("(0->0)->0\n");
		return 0;
	}
	
	return 0;
}
