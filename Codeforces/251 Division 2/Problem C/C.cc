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

int n, k, p, a[100100], taken[100100], odd, even;
int cnt1 = 0, cnt2 = 0;
vector<int> o[100100], e[100100];

void output(){
	puts("YES");
	
	for(int i = 0; i < cnt2; i++){
		printf("%d ", (int) e[i].size());
		foreach(it, e[i]) printf("%d ", *it);
		printf("\n");
	}
	
	for(int i = 0; i < cnt1; i++){
		printf("%d ", (int) o[i].size());
		foreach(it, o[i]) printf("%d ", *it);
		printf("\n");
	}
	
	return;
}

int main(){
	sd3(n,k,p);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		if(a[i]%2) odd++;
	}
	
	if(odd < k-p){
		puts("NO"); return 0;
	}
	
	even = n-odd;
	
	int rem =  odd-(k-p);
	if(rem%2 == 1){
		puts("NO"); return 0;
	}
	
	if(rem/2 + even < p){
		puts("NO"); return 0;
	}
	
	for(int i = 0; i < n; i++){
		if(a[i]%2 == 1 and cnt1 < k-p){
			o[cnt1++].pb(a[i]); 
			taken[i] = 1;
		}
		else if(a[i]%2 == 0 and cnt2 < p){
			e[cnt2++].pb(a[i]);
			taken[i] = 1;
		}
	}
	
	bool second = false;
	for(int i = 0; i < n; i++){
		if(a[i]%2 == 1 and taken[i] == 0){
			if(cnt2 < p){
				e[cnt2].pb(a[i]);
				if(second) cnt2++;
				second = !second;
			}
			else if(p > 0){
				e[cnt2-1].pb(a[i]);
			}
			else{
				o[cnt1-1].pb(a[i]);
			}
		}
		else if(a[i]%2 == 0 and taken[i] == 0){
			if(p == 0) o[cnt1-1].pb(a[i]);
			else e[cnt2-1].pb(a[i]);
		}
	}
	
	if(cnt1 != k-p and cnt2 != p){
		puts("NO"); return 0;
	}
	
	output();
	
	return 0;
}
