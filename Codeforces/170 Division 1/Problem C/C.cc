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

typedef pair<int,int> pii;

const int K = 100100;

int n, m, k;
map<int, vector<pii> > row, col;
map<int,int> crow, ccol;

void merge(vector<pii> &v){
	int l = v.size();
	vector<pii> res;
	pii cur = v[0];
	
	for(int i = 1; i < l; i++){
		if(v[i].fi <= cur.se) cur.se = max(cur.se,v[i].se);
		else{
			res.pb(cur);
			cur = v[i];
		}
	}
	res.pb(cur);
	
	v = res;
}

int main(){
	sd3(n,m,k);
	
	int x1, y1, x2, y2;
	for(int i = 0; i < k; i++){
		sd2(x1,y1); sd2(x2,y2);
		
		if(x1 == x2){
			if(y1 > y2) swap(y1,y2);
			row[x1].pb(mp(y1,y2));
		}
		else{
			if(x1 > x2) swap(x1,x2);
			col[y1].pb(mp(x1,x2));
		}
	}

	int nim = 0, rem = 0, tot = 0;
	rem = n - 1 - (int)row.size();
	if(rem%2) nim ^= m;
	rem = m - 1 - (int)col.size();
	if(rem%2) nim ^= n;
	
	
	foreach(r, row){
		sort((r->se).begin(), (r->se).end());
		merge(r->se);
		
		int cnt = m;
		foreach(it, (r->se)) cnt -= it->se-it->fi;
		nim ^= cnt;
		
		
		crow[r->fi] = cnt;
	}
	
	foreach(c, col){
		sort((c->se).begin(), (c->se).end());
		merge(c->se);
		
		int cnt = n;
		foreach(it, (c->se)) cnt -= it->se-it->fi;	
		nim ^= cnt;
		
		ccol[c->fi] = cnt;
	}

	if(nim == 0){
		puts("SECOND");
		return 0;
	}
	
	puts("FIRST");
	
	foreach(r, row){
		int s = crow[r->fi];
		if((s^nim) < s){
			// found
			int val = s^nim;
			int rem = s-val;
			
			vector<pii> &v = (r->se);
			
			int cur = min(v[0].fi, rem), e = v[0].fi;
			if(cur < e) e = cur;
			int i = 1;
	
			v.pb(mp(m,m));
			while(cur < rem and i < v.size()){
				cur += v[i].fi - v[i-1].se;
				e = v[i].fi;
				if(cur >= rem){
					e -= (cur-rem);
					break;
				}
				i++;
			}
			
			
			if(cur < rem) continue;
						
			printf("%d %d %d %d\n", r->fi, 0, r->fi, e);
			
			assert(e <= m);
			
			return 0;
		}
	}
	
	foreach(c, col){
		int s = ccol[c->fi];
		if((s^nim) < s){
			// found
			int val = s^nim;
			int rem = s-val;
			
			vector<pii> &v = (c->se);
			
			int cur = min(v[0].fi, rem), e = v[0].fi;
			if(cur < e) e = cur;
			int i = 1;
			
			v.pb(mp(n,n));
			while(cur < rem and i < v.size()){
				cur += v[i].fi - v[i-1].se;
				e = v[i].fi;
				if(cur >= rem){
					e -= (cur-rem);
					break;
				}
				i++;
			}
			
			if(cur < rem) continue;
			
			printf("%d %d %d %d\n", 0, c->fi, e, c->fi);
			
			assert(e <= n);
			
			return 0;
		}
	}
	
	if((m-(m^nim)) > 0){
		for(int i = 1; i < n; i++){
			if(!row.count(i)){
				printf("%d %d %d %d\n", i, 0, i, m-(m^nim));
				return 0;
			}
		}
	}
	
	for(int i = 1; i < m; i++){
		if(!col.count(i)){
			printf("%d %d %d %d\n", 0, i, n-(n^nim), i);
			return 0;
		}
	}
	
	return 0;
}
