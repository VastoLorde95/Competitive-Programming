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

int n, w[100];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(w[i]);
	}
	
	sort(w, w+n);
	
	for(int k = n-1; k >= 1; k--){
		for(int i = 0; i < n; i++){
			if((i/k) > w[i]){
				cout << k+1 << "\n";
				return 0;
			}
		}
	}
	
	cout << "1\n";
	
	return 0;
}
