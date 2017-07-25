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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int n, m[100000], flag, cur;

int main(){
	sd(n);
	for(int i = 0; i < n; i++) sd(m[i]);
	
	for(int i = 3; i <= n; i++){
		if(n%i == 0){
			for(int j = 0; j < n/i; j++){
				flag = 1, cur = j;
				for(int k = 0; k < i; k++){
					if(m[cur] != 1){
						flag = 0;
						break;
					}
					cur = (cur+(n/i))%n;
				}
				if(flag == 1){
					puts("YES");
					return 0;
				}
			}
		}
	}
	
	puts("NO");
	
	return 0;
}
