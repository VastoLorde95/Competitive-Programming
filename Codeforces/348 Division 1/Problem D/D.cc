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

const long double PI = 3.1415926535897932384626433832795;

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

int N = 100100;
int tree[100100]; // Careful, indexing begins from 1.

int query(int idx, int sum = 0){
    for(; idx; idx -= (idx & -idx)) sum += tree[idx];
    return sum;
}

void update(int idx, int val){
    for(; idx < N; idx += (idx & -idx)) tree[idx] += val;
}

int n;
map<int, vector<pair<int, pii> > > pos;
int ans[100100];
int z[100100];

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		int a, t, x; sd3(a,t,x);
		pos[x].pb(mp(i, mp(a,t)));
		z[i] = a;
	}
	
	vector<int> t;
	foreach(it, pos){
		vector<pair<int, pii> > &v = it->se;
		t.clear();
		
		for(int i = 0; i < v.size(); i++) t.pb(v[i].se.se);
		
		sort(t.begin(), t.end());
		t.resize(unique(t.begin(), t.end()) - t.begin());
		
		N = t.size() + 1;
		fill(tree, tree + N, 0);
		
		for(int i = 0; i < v.size(); i++){
			int id = v[i].fi;
			int type = v[i].se.fi;
			int tim = lower_bound(t.begin(), t.end(), v[i].se.se) - t.begin() + 1;
			
			if(type == 1)
				update(tim, 1);
			else if(type == 2)
				update(tim, -1);
			else
				ans[id] = query(tim);
		}
	}
	
	for(int i = 0; i < n; i++) 
		if(z[i] == 3)
			printf("%d\n", ans[i]);
	
	return 0;
}
