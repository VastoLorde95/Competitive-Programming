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

int n, k, nt q[101], s[101], p[2][101], cpy[101], x[101], y[101];

bool fwd(){
	int indx = 0;
	for(int i = 1; i <= k; i++){
		indx = 1-indx;
		for(int j = 1; j <= n; j++) p[indx][j] = p[1-indx][q[j]];
		
		bool ok = true;
		for(int j = 1; j <= n; j++)
			if(p[indx][j] != s[j]) ok = false;
		
		if(ok and (k-i)%2 == 0) return ok;
	}
	return false;
}

bool rev(){
	for(int i = 1; i <= n; i++) p[0][i] = cpy[i];
	
	int indx = 0;
	for(int i = 1; i <= k; i++){
		indx = 1-indx;
		for(int j = 1; j <= n; j++) p[indx][q[j]] = p[1-indx][j];
		
		bool ok = true;
		for(int j = 1; j <= n; j++)
			if(p[indx][j] != s[j]) ok = false;
		
		if(ok and (k-i)%2 == 0) return ok;
	}
	return false;
}

int main(){
	sd2(n,k);
	
	for(int i = 1; i <= n; i++) sd(q[i]);
	for(int i = 1; i <= n; i++) sd(s[i]);	
	for(int i = 1; i <= n; i++) cpy[i] = p[0][i] = i;
	
	bool ok = false;
	
	for(int i = 1; i <= n; i++){
		if(p[0][i] != s[i]) ok = true;
	}
	
	if(!ok){
		puts("NO"); return 0;
	}
	
	for(int i = 1; i <= n; i++) x[i] = p[0][q[i]], y[q[i]] = p[0][i];
	
	ok = false;
	for(int i = 1; i <= n; i++)
		if(!(x[i] == y[i] and y[i] == s[i])) ok = true;
	
	if(!ok and k == 1){
		puts("YES"); return 0;
	}	
	else if(!ok){
		puts("NO"); return 0;
	}
	
	if(fwd() or rev()){
		puts("YES"); return 0;
	}
	
	puts("NO");
	
	return 0;
}
