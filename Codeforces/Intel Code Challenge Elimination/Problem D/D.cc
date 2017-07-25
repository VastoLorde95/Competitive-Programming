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

const ld PI = 3.1415926535897932384626433832795;

const int N = 50100;
const int M = 30;

unordered_map<int, set<int> > g;
unordered_map<int, int> o;

void print(set<int> s){
	for(auto x : s){ tr(x);}
}

set<int>* dfs(int x){
	int a = 2*x;
	int b = 2*x+1;

	if(g[x].empty()){
		set<int> *s = new set<int>();
		s->insert(x);
		return s;
	}
	
	if(g[x].size() == 2){
		set<int> *p = dfs(a);
		set<int> *q = dfs(b);
		
//		tr(x);
//		print(*p);
//		print(*q);
		
		if(o[x] == 1){
			if(p->size() < q->size()){
				swap(p, q);
			}
			
			p->insert(x);
			
			for(auto &x: *q){
				p->insert(x);
			}
//			
//			tr(1111, x);
//			print(*p);
			return p;
		}
		
		int mx1 = *((*p).rbegin());
		int mx2 = *((*q).rbegin());
		
//		tr(mx1, mx2);
		
		if(mx1 > mx2){
			p->erase(mx1);
			p->insert(x);
		}
		else{
			q->erase(mx2);
			q->insert(x);
		}
		
		if(p->size() < q->size()) swap(p, q);
		
		for(auto &x: *q){
			p->insert(x);
		}
		
//		tr(1111, x);
//		print(*p);
		
		return p;
	}
	else{
		set<int> *s = dfs(*g[x].begin());
		if(o[x] == 1){
			s->insert(x);
		}
		else{
			int mx = *s->rbegin();
			if(mx > 1){
				s->erase(mx);
				s->insert(x);
			}
		}
//		tr(1111, x);
//		print(*s);
		return s;
	}
}

int main(){
	int n;
	sd(n);
	
	for(int i = 0; i < n; i++){
		int y; sd(y);
		o[y] = 1;
		if(g.count(y)) continue;

		int x = y/2;
		
		while(y > 1){
			g[y/2].insert(y);
			y /= 2;
		}
	}
	
	set<int> *ans = dfs(1);
	for(auto &x : *ans){
		printf("%d ", x);
	}
	puts("");
	
	return 0;
}
