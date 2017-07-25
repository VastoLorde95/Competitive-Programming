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

const int MAXN = 1001000;
ll tree[MAXN]; // Careful, indexing begins from 1.

ll query(int idx, ll sum = 0){
    for(; idx; idx -= (idx & -idx)) sum += tree[idx];
    return sum;
}

void update(int idx, int val){
    for(; idx < MAXN; idx += (idx & -idx)) tree[idx] += val;
}

int n, k;
ll ans = 1;

int main(){ _
	cin >> n >> k;
	
	k = min(k, n-k);
	
	int x = 1;
	for(int i = 1; i <= n; i++){
		int y = x + k;
		if(y > n) y -= n;
	
		int a = min(x, y);
		int b = max(x, y);
	
		int l = a+1-k;
		int h = b-1-k;
		h = min(h, a-1);
		
		ll add = 0;
		
		if(l >= 1){
			add += query(h) - query(l-1);
		}
		else if(l < 1 and h >= 1){
			add += query(h);
			l = max(l+n, b+1);
			add += query(n) - query(l-1);
		}
		else{
			l += n;
			h += n;
			
			h = max(h, b+1);
			l = max(l, b+1);
			
			add += query(h) - query(l-1);
		}
		
		l = b + 1 - k;
		h = a - k;
		
		l = max(l, a+1);
		
		if(h < 1){
			h += n;
			h = min(h, b - 1);
			add += query(h) - query(l-1);
		}
		else{
			h = b - 1;
			add += query(h) - query(l-1);
		}
		
		ans += add + 1;
		
		cout << ans << ' ';
		
		
		update(x, 1);	
		x = y;		
	}
	
	cout << endl;
	
	return 0;
}
