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

const int N = 10010001;
const ll MOD = 1e9 + 7;

int n, k, q;

ll A[N];
ll lft[N];
ll rgt[N];

void getA(){
	ll a, b, c, d, e, f, r, s, t, m;
	cin >> a >> b >> c >> d >> e >> f >> r >> s >> t >> m >> A[1];
	
	ll rem = t % s;
	for(int x = 2; x <= n; x++){
		rem = rem * t % s;
		
		
		if(rem <= r){
			A[x] = ((a * (A[x-1] * A[x-1] % m) % m) + (b * A[x-1] % m) + c) % m;
		}
		else{
			A[x] = ((d * (A[x-1] * A[x-1] % m) % m) + (e * A[x-1] % m) + f) % m;
		}
	}
	
	deque<pii> dq;
	int x = 1, y = 1;
	
	while(y <= k){
		while(!dq.empty() and dq.front().fi >= A[y]) dq.pop_front();
		dq.push_front(mp(A[y], y));
		++y;
	}
	
	lft[1] = rgt[k] = dq.back().fi;
	
	while(y <= n){
		while(!dq.empty() and dq.front().fi >= A[y]) dq.pop_front();
		dq.push_front(mp(A[y], y));
		
		if(dq.back().se == x){
			dq.pop_back();
		}	
		
		lft[++x] = rgt[y] = dq.back().fi;
		y++;
	}
}

ll sum = 0;
ll pro = 1;	

void genQ(){
	ll L1, La, Lc, Lm, D1, Da, Dc, Dm;
	
	cin >> L1 >> La >> Lc >> Lm >> D1 >> Da >> Dc >> Dm;
	
	ll L, R;
	for(int i = 1; i <= q; i++){
		L1 = (La * L1 + Lc) % Lm;
		D1 = (Da * D1 + Dc) % Dm;
		L = L1 + 1;
		R = min(L + k - 1 + D1, 1ll * n);
		
		ll small = min(lft[L], rgt[R]);
		
		sum += small;
		pro = pro * small % MOD;
	}
	
}

int main(){ _
	cin >> n >> k >> q;
	
	getA();
	genQ();

	cout << sum << ' ' << pro << endl;
	
	return 0;
}
