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
int res[2000101];


int main(){
	sd(n);
	for(int i = 1; i <= n; i++) res[i] = i;
	
	int start = 1;
	
	for(int k = 2; k <= n; k++){
		int tmp = res[start], tmp2;
		bool ok = true;
		
		for(int j = start + k; ok; j += k){
			if(j >= start+n){
				j = start + n;
				ok = false;
			}
			
			tmp2 = res[j];
			res[j] = tmp;
			tmp = tmp2;
		}
		
		start++;
	}
	
	for(int i = start; i < start+n; i++){
		cout << res[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
