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

#define meta __FUNCTION__<<' '<<__LINE__<<' '
#define tr(x) cout<<meta<<#x<<' '<<x<<'\n';
#define tr2(x,y) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<'\n';
#define tr3(x,y,z) cout<<meta<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr4(w,x,y,z) cout<<meta<<#w<<' '<<w<<' '<<#x<<' ' <<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr5(v,w,x,y,z) cout<<meta<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';
#define tr6(u,v,w,x,y,z) cout<<meta<<#u<<' '<<u<<' '<<#v<<' '<<v<<' '<<#w<<' '<<w<<' '<<#x<<' '<<x<<' '<<#y<<' '<<y<<' '<<#z<<' '<<z<<'\n';

using namespace std;

template<typename S, typename T> 
ostream& operator<<(ostream& out, pair<S, T> const& p){out<<'('<<p.first<<", "<<p.second<<')'; return out;}

template<typename T>
ostream& operator<<(ostream& out, vector<T> const & v){
int l = v.size(); for(int i = 0; i < l-1; i++) out<<v[i]<<' '; if(l>0) out<<v[l-1]; return out;}

typedef long long ll;

const int N = 1000100;

int k, n, p[N], b[N], pos[N], l[N], r[N];
ll res;

const int MAXN = N;
int tree[MAXN];

int query(int idx){
    int sum = 0;
    while(idx){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val){
    while(idx < MAXN){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main(){
	sd2(n,k);
	
	for(int i = 1; i <= n; i++){
		sd(p[i]);
		pos[p[i]] = i;
	}
	
	for(int i = 1; i <= k; i++){
		int x;
		sd(x);
		b[x] = 1;
	}
	
	vector<int> s;
	for(int i = 1; i <= n; i++){
		if(!b[p[i]]){
			if(s.empty())
				l[i] = 0;
			else{
				int id = lower_bound(s.begin(), s.end(), p[i]) - s.begin();
				l[i] = (id == 0)? 0 : pos[s[id-1]];
			}
		}
		else{
			while(!s.empty() and s.back() > p[i]) s.pop_back();
			s.pb(p[i]);
		}
	}

	s.clear();	

	for(int i = n; i > 0; i--){
		if(!b[p[i]]){
			if(s.empty())
				r[i] = n+1;
			else{
				int id = lower_bound(s.begin(), s.end(), p[i]) - s.begin();
				r[i] = (id == 0)? n+1 : pos[s[id-1]];
			}
		}
		else{
			while(!s.empty() and s.back() > p[i]) s.pop_back();
			s.pb(p[i]);
		}
	}
	
	vector<pair<int,int> > v;
	for(int i = 1; i <= n; i++) if(!b[p[i]]) v.pb(mp(p[i],i));
	
	sort(v.begin(), v.end());
	
	foreach(it, v){
		int x = it->fi, id = it->se;
		int val = (r[id]-l[id]-1) - (query(r[id]-1) - query(l[id])); 
		res += val;
		update(id, 1);
	}
	
	cout << res << endl;
	
	return 0;
}
