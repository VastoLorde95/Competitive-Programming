#include <bits/stdc++.h>
 
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
 
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
 
#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
 
template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}
 
template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}
 
template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}
 
template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}
 
const int N = 50;

vector<int> ids[4][N+1];

char p[N][N];
int a[N];
int k[N];
int ans[N];
char q[N];
 
void gen(int i, int cl){
	for(int &id : ids[cl][i]){
		int cnt = 0;
		for(int j = 0; j < i; j++){
			cnt += (p[id][j] != q[j]);
		}
		
		if(cnt <= k[id]) ans[id]++;
	}
	
	if(i == 26){
		return;
	}
	
	for(int c = 0; c < cl; c++){
		bool flag = true;
		
		for(int j = i-1; j >= 0; j--){
			if(q[j] - 'a' != c or j + j < i) continue;
			
			if(q[j] == q[j+j-i]){
				flag = false;
				break;
			}
		}
		
		if(flag){
			q[i] = 'a' + c;
			gen(i+1, cl);
		}
	}
}
 
int main(){
	int t;
	sd(t);
	for(int i = 0; i < t; i++){
		sd2(a[i], k[i]);
		scanf("%s", p[i]);
		
		int l = strlen(p[i]);
		
		ids[a[i]][l].pb(i);
	}
	
	for(int i = 1; i <= 3; i++){
		gen(0, i);
	}
	
	for(int i = 0; i < t; i++){
		printf("%d\n", ans[i]);
	}
	
	return 0;
} 

