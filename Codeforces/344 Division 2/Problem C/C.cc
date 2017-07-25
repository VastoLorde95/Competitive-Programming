#include <bits/stdc++.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define foreach(it, v) for(__typeof((v).begin()) it=(v).begin(); it != (v).end(); ++it)
#define meta __FUNCTION__,__LINE__

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

void tr(){cout << endl;}
template<typename S, typename ... Strings>
void tr(S x, const Strings&... rest){cout<<x<<' ';tr(rest...);}

typedef long long ll;
typedef pair<int,int> pii;

const int N = 200100;

int n, m;
int a[N], ans[N];
pii b[N];
int r[N];

int main(){
	sd2(n,m);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		ans[i] = a[i];
	}
	
	for(int i = 0; i < m; i++){
		sd2(b[i].fi, b[i].se);
	}
	
	r[m-1] = m;
	stack<int> s;
	s.push(m-1);
	
	for(int i = m-2; i >= 0; i--){
		while(!s.empty() and b[s.top()].se < b[i].se) s.pop();
		if(s.empty()) r[i] = m;
		else r[i] = s.top();
		
		s.push(i);
	}
	
	int id = -1;
	for(int i = 0; i < m; i++){
		if(r[i] == m){
			id = i;
			break;
		}
	}
	
	int start_type = b[id].fi, l = b[id].se;
	sort(a, a+l);
	
	int x = 0, y = l-1, cur = l-1;
	for(int i = id+1; i < m; i++){
		if(r[i] == m){
			if(b[i].fi == start_type){
				continue;
			}
							
			int next_l = b[i].se, next_type = b[i].fi;					
			int del = l - next_l;
			while(del--){
				if(next_type == 1)
					ans[cur--] = a[x++];
				else
					ans[cur--] = a[y--];
			}
			
			start_type = next_type;
			l = next_l;
		}
	}
	
	if(start_type == 1){
		while(cur >= 0) ans[cur--] = a[y--];
	}
	else{
		while(cur >= 0) ans[cur--] = a[x++];
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	puts("");
	
	return 0;
}
