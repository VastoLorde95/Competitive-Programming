#include <bits/stdc++.h>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define func __FUNCTION__
#define line __LINE__

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.fi<<", "<<p.se<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

set<int> s;

bool check(int z, int cur, int a, int b){
	if(s.count(cur)) return false;
	if(z < 0) return false;
	if(z == 0) return true;
	
	if(check(z-a,cur+a,a,b)) return true;
	if(check(z-b,cur+b,a,b)) return true;
	
	for(int i = a; i <= z; i += a){
		int j = (i/b)*b + b;
		if(check(z-i-(i-j),cur+(i+i-j), a,b)) return true;
	}
	
	for(int i = b; i <= z; i += b){
		int j = (i/a)*a + a;
		if(check(z-i-(i-j),cur+(i+i-j), a,b)) return true;
	}
	
	return false;
	
	
}

int main(){
	int t;
	int a, b, q, x;
	sd(t);
	while(t--){
		sd3(a,b,q);
		int z;
		
		if(b < a) swap(b,a);
			
		s.clear();
//		tr(a,b,b-a);
		
		while(q--){
			sd(z);
			
			if(s.count(z)) printf("1");
			else if(check(z,0,a,b)) printf("1"); else printf("0");
		}
		printf("\n");
	}
	return 0;
}
